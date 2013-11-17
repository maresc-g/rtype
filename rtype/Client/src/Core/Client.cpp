//
// Client.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Oct 29 16:28:39 2013 guillaume marescaux
// Last update Sun Nov 17 21:21:42 2013 cyril jourdain
//

#include <iostream>

#include			<string.h>
#include			<map>
#include			<sstream>
#include			<fstream>
#include			<stdexcept>
#include			"Core/Client.hh"
#include			"Game/GameList.hh"
#include			"Map/Map.hh"
#include			"Error/SocketError.hpp"

//----------------------------------BEGIN CTOR / DTOR---------------------------------------

Client::Client(FileSystem::Directory *dir, eState *state):
  Thread(),
  _ptrs(new std::map<Protocol::eProtocol, void(Client::*)(Trame const &)>),
  _sockets(new std::map<eSocket, Socket *>), _socketsClient(new std::map<eSocket, SocketClient *>),
  _select(new Select), _protocol(new Protocol), _id(0),
  _info(new MutexVar<ConnectInfo *>(NULL)), _running(new MutexVar<bool>(true)), _initialized(new MutexVar<bool>(false)),
  _dir(dir), _diffDir(new std::list<std::string>), _state(state)
{
  // ptrs
  _ptrs->insert(std::pair<Protocol::eProtocol, void(Client::*)(Trame const &)>(Protocol::WELCOME, &Client::welcome));
  _ptrs->insert(std::pair<Protocol::eProtocol, void(Client::*)(Trame const &)>(Protocol::GAMELIST, &Client::gamelist));
  _ptrs->insert(std::pair<Protocol::eProtocol, void(Client::*)(Trame const &)>(Protocol::OK, &Client::ok));
  _ptrs->insert(std::pair<Protocol::eProtocol, void(Client::*)(Trame const &)>(Protocol::KO, &Client::ko));
  _ptrs->insert(std::pair<Protocol::eProtocol, void(Client::*)(Trame const &)>(Protocol::LAUNCHGAME, &Client::launchGame));
  _ptrs->insert(std::pair<Protocol::eProtocol, void(Client::*)(Trame const &)>(Protocol::MAP, &Client::map));
  _ptrs->insert(std::pair<Protocol::eProtocol, void(Client::*)(Trame const &)>(Protocol::ENTITY, &Client::entity));
  _ptrs->insert(std::pair<Protocol::eProtocol, void(Client::*)(Trame const &)>(Protocol::SCROLL, &Client::scroll));
  _ptrs->insert(std::pair<Protocol::eProtocol, void(Client::*)(Trame const &)>(Protocol::DEAD, &Client::dead));
  _ptrs->insert(std::pair<Protocol::eProtocol, void(Client::*)(Trame const &)>(Protocol::SPRITE, &Client::sprite));
  _ptrs->insert(std::pair<Protocol::eProtocol, void(Client::*)(Trame const &)>(Protocol::CONTENTSPRITE, &Client::contentSprite));
  _ptrs->insert(std::pair<Protocol::eProtocol, void(Client::*)(Trame const &)>(Protocol::CONFSPRITE, &Client::confSprite));
  _ptrs->insert(std::pair<Protocol::eProtocol, void(Client::*)(Trame const &)>(Protocol::LEVELUP, &Client::levelUp));
  _ptrs->insert(std::pair<Protocol::eProtocol, void(Client::*)(Trame const &)>(Protocol::ENDGAME, &Client::endGame));
  // sockets
  _sockets->insert(std::pair<eSocket, Socket *>(TCP, new Socket));
  _sockets->insert(std::pair<eSocket, Socket *>(UDP, new Socket));
  _socketsClient->insert(std::pair<eSocket, SocketClient *>(TCP, NULL));
  _socketsClient->insert(std::pair<eSocket, SocketClient *>(UDP, NULL));
  _select->setTimeout(0, 0);
}

Client::~Client()
{
  for (auto it = _sockets->begin() ; it != _sockets->end() ; it++)
    {
      if ((*it).second)
	delete (*it).second;
    }
  delete _ptrs;
  delete _sockets;
  delete _socketsClient;
  delete _select;
  delete _protocol;
  if (_info->getVar())
    delete _info->getVar();
  delete _info;
  delete _running;
}

//-----------------------------------END CTOR / DTOR----------------------------------------

//---------------------------------BEGIN STATIC METHODS-------------------------------------

std::map<std::string, std::string>	Client::initMapGameList()
{
  std::map<std::string, std::string>	map;

  map.insert(std::pair<std::string, std::string>("id", ""));
  map.insert(std::pair<std::string, std::string>("name", ""));
  map.insert(std::pair<std::string, std::string>("numPlayer", ""));
  map.insert(std::pair<std::string, std::string>("level", ""));
  return (map);
}

//----------------------------------END STATIC METHODS--------------------------------------

//--------------------------------BEGIN PRIVATE METHODS-------------------------------------

void				Client::exec()
{
  while (_running->getVar())
    {
      while (!_initialized->getVar())
	{
	  while (!_info->getVar())
	    ;
	  _initialized->setVar(this->initialize());
	  if (!_initialized->getVar())
	    {
	      delete _info->getVar();
	      _info->setVar(NULL);
	    }
	}
      if (*_state == WAIT_SPRITE)
	{
	  for (auto it = _diffDir->begin() ; it != _diffDir->end() ; it++)
	    _protocol->protocolMsg(Protocol::GET_SPRITE, _id, reinterpret_cast<void *>(&(*it)));
	  _diffDir->clear();
	}
      this->loop();
    }
}

void				Client::welcome(Trame const &trame)
{
  _id = trame.getHeader().getId();
}

void				Client::gamelist(Trame const &trame)
{
  std::istringstream		iss(trame.getContent());
  std::istringstream		*tokenStream;
  std::string			token;
  static std::map<std::string, std::string>	map = Client::initMapGameList();
  GameList			*gameList = GameList::getInstance();

  while (iss.good() && !iss.str().empty())
    {
      iss >> token;
      tokenStream = new std::istringstream(token);
      std::getline(*tokenStream, map["id"], ';');
      std::getline(*tokenStream, map["name"], ';');
      std::getline(*tokenStream, map["numPlayer"], ';');
      std::getline(*tokenStream, map["level"], ';');
      gameList->addGame(new GameInfo(map["id"], map["name"], map["numPlayer"], map["level"]));
      delete tokenStream;
    }
}

void				Client::ok(Trame const &) { }

void				Client::ko(Trame const &) { }

void				Client::launchGame(Trame const &)
{
  *_state = PLAYING;
}

void				Client::map(Trame const &)
{
}

void				Client::entity(Trame const &trame)
{
  Map				*map = Map::getInstance();
  std::istringstream		iss(trame.getContent());
  std::string			token;
  int				id;
  int				type;
  int				x;
  int				y;

  std::getline(iss, token, ';');
  id = std::stoi(token);
  std::getline(iss, token, ';');
  type = std::stoi(token);
  std::getline(iss, token, ';');
  x = std::stoi(token);
  std::getline(iss, token, ';');
  y = std::stoi(token);
  if (map->exists(id))
    map->moveEntity(id, x, y);
  else
    map->addEntity(new Entity(id, x, y, static_cast<Entity::eEntity>(type)));
}

void				Client::scroll(Trame const &trame)
{
  Map				*map = Map::getInstance();

  map->setScroll(std::stoi(trame.getContent()));
}

void				Client::dead(Trame const &trame)
{
  Map				*map = Map::getInstance();

  map->removeEntity(std::stoi(trame.getContent()));
}

void				Client::sprite(Trame const &trame)
{
  _dir->updateEntries();

  std::list<std::string>			files;
  std::list<FileSystem::Entry *>		tmpList = _dir->getEntries();
  std::istringstream				iss(trame.getContent());
  std::string					fileName;
  std::function<bool(std::string const &)>	fct = [&](std::string const &fileName)
    {
      for (auto it = tmpList.begin() ; it != tmpList.end() ; it++)
	{
	  if ((*it)->getPath() == fileName)
	    return (true);
	}
      return (false);
    };

  _diffDir->clear();
  while (iss.good() && !iss.str().empty())
    {
      iss >> fileName;
      files.push_back(fileName);
    }
  for (auto it = files.begin() ; it != files.end() ; it++)
    {
      if (!fct(*it))
	_diffDir->push_back(*it);
      else
	{
	  // CHECK MD5
	}
    }
  *_state = WAIT_SPRITE;
}

void				Client::contentSprite(Trame const &trame)
{ 
  std::istringstream		iss(trame.getContent());
  std::string			fileName;
  std::string			content;

  std::getline(iss, fileName, ';');

  std::ofstream			out(fileName);

  std::getline(iss, content, ';');
  out.write(content.c_str(), content.size());
  out.close();
}

void				Client::confSprite(Trame const &trame)
{
  std::istringstream		iss(trame.getContent());
  std::string			fileName;
  std::string			content;

  std::getline(iss, fileName, ';');

  std::ofstream			out(fileName);

  std::getline(iss, content, ';');
  out.write(content.c_str(), content.size());
  out.close();
}

void				Client::levelUp(Trame const &) { }


void				Client::endGame(Trame const &) { }

//---------------------------------END PRIVATE METHODS--------------------------------------

//----------------------------------BEGIN METHODS---------------------------------------

void				Client::writeToSocket(Trame const &trame, eSocket sock)
{
  static std::string		trameBuff;
  static char			buff[SIZE_BUFFER];

  trameBuff = trame.toString();
  memset(buff, 0, SIZE_BUFFER);
  trameBuff.copy(buff, trameBuff.size());
  (*_socketsClient)[sock]->writeSocket(buff, trameBuff.size());
}

void				Client::write()
{
  CircularBufferManager		*manager = CircularBufferManager::getInstance();
  Trame				*tmp;

  _select->clear();
  _select->pushFd((*_socketsClient)[TCP]->getSocket(), Select::WRITE);
  _select->pushFd((*_socketsClient)[UDP]->getSocket(), Select::WRITE);
  tmp = manager->popTrame(_id, "TCP", CircularBufferManager::WRITE_BUFFER);
  if (!tmp)
    tmp = manager->popTrame(_id, "UDP", CircularBufferManager::WRITE_BUFFER);
  while (tmp)
    {
      _select->runSelect(false);
      if (tmp->getHeader().getProto() == "UDP")
	{
	  if (_select->isSet((*_socketsClient)[UDP]->getSocket(), Select::WRITE))
	    writeToSocket(*tmp, Client::UDP);
	}
      else if (tmp->getHeader().getProto() == "UDP")
	{
	  if (_select->isSet((*_socketsClient)[UDP]->getSocket(), Select::WRITE))
	    writeToSocket(*tmp, Client::UDP);
	}
      delete tmp;
      tmp = manager->popTrame(_id, "TCP", CircularBufferManager::WRITE_BUFFER);
      if (!tmp)
	tmp = manager->popTrame(_id, "UDP", CircularBufferManager::WRITE_BUFFER);      
    }
}

void				Client::readFromSocket(eSocket sock)
{
  static char			buff[SIZE_BUFFER];
  static std::string		tmp;
  CircularBufferManager		*manager = CircularBufferManager::getInstance();
  Trame				*tmpTrame;
  int				size;

  if (_select->isSet((*_socketsClient)[sock]->getSocket(), Select::READ))
    {
      memset(buff, 0, SIZE_BUFFER);
      tmp = "";
      while (tmp.rfind(END_TRAME) == std::string::npos)
	{
	  size = (*_socketsClient)[sock]->readSocket(buff, SIZE_BUFFER);
	  tmp.append(buff, size);
	}
      tmpTrame = Trame::toTrame(tmp);
      if (tmpTrame)
	{
	  std::cout << "TO STRING = " << tmpTrame->toString() << std::endl;
	  manager->pushTrame(tmpTrame, CircularBufferManager::READ_BUFFER);
	}
    }
}

void				Client::read(long const sec, long const usec, bool setTimeout)
{
  _select->setTimeout(sec, usec);
  _select->clear();
  _select->pushFd((*_socketsClient)[TCP]->getSocket(), Select::READ);
  _select->pushFd((*_socketsClient)[UDP]->getSocket(), Select::READ);
  _select->runSelect(setTimeout);
  this->readFromSocket(Client::TCP);
  this->readFromSocket(Client::UDP);
}

bool				Client::initialize(void)
{
  CircularBufferManager		*manager = CircularBufferManager::getInstance();
  Trame				*tmp;
  Protocol::eProtocol		msgType;

  try
    {
      (*_sockets)[TCP]->initialize("TCP");
      (*_sockets)[UDP]->initialize("UDP");
      // (*_socketsClient)[UDP] = (*_sockets)[UDP]->connectToAddr("10.11.46.54", 4243);
      // (*_socketsClient)[TCP] = (*_sockets)[TCP]->connectToAddr("10.11.46.54", 4243);
      (*_socketsClient)[UDP] = (*_sockets)[UDP]->connectToAddr(_info->getVar()->getIp(), std::stoi(_info->getVar()->getPort()));
      (*_socketsClient)[TCP] = (*_sockets)[TCP]->connectToAddr(_info->getVar()->getIp(), std::stoi(_info->getVar()->getPort()));
    }
  catch (SocketError const &e)
    {
      std::cout << e.what() << std::endl;
      (*_sockets)[TCP]->destroy();
      (*_sockets)[UDP]->destroy();
      return (false);
    }
  catch (std::invalid_argument const &e)
    {
      return (false);
    }
  this->read(0, 0, false);
  tmp = manager->popTrame(CircularBufferManager::READ_BUFFER);
  msgType = _protocol->getMsg(tmp);
  (this->*(*_ptrs)[msgType])(*tmp);
  delete tmp;
  _protocol->protocolMsg(Protocol::INITIALIZE, _id, NULL);
  this->write();
  while (msgType != Protocol::CHECK)
    {
      this->read(0, 0, false);
      tmp = manager->popTrame(CircularBufferManager::READ_BUFFER);
      msgType = _protocol->getMsg(tmp);
      if (msgType == Protocol::SERVERQUIT)
	return (false);
      delete tmp;
    }
  return (true);
}

void				Client::disconnect(void)
{
  destroy();
  _initialized->setVar(false);
}

void				Client::destroy(void)
{
  (*_sockets)[TCP]->destroy();
  (*_sockets)[UDP]->destroy();
}

void				Client::loop(void)
{
  CircularBufferManager		*manager = CircularBufferManager::getInstance();
  Trame				*tmp;
  Protocol::eProtocol		msgType;

  this->read(0, 0, true);
  tmp = manager->popTrame(CircularBufferManager::READ_BUFFER);
  if (tmp)
    {
      msgType = _protocol->getMsg(tmp);
      (this->*(*_ptrs)[msgType])(*tmp);
    }
  this->write();
}

//-----------------------------------END METHODS----------------------------------------

//-----------------------------BEGIN GETTERS / SETTERS----------------------------------

void				Client::setConnectInfo(ConnectInfo *info) { _info->setVar(info); }
ConnectInfo			*Client::getConnectInfo() const { return (_info->getVar()); }
void				Client::setRunning(bool const running) { _running->setVar(running); }
bool				Client::getRunning(void) const { return (_running->getVar()); }
void				Client::setInitialized(bool const initialized) { _initialized->setVar(initialized); }
bool				Client::getInitialized(void) const { return (_initialized->getVar()); }

//------------------------------END GETTERS / SETTERS-----------------------------------
