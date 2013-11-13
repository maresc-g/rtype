//
// Client.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Oct 29 16:28:39 2013 guillaume marescaux
// Last update Tue Nov 12 14:01:57 2013 guillaume marescaux
//

#include <iostream>

#include			<string.h>
#include			<map>
#include			<sstream>
#include			"Core/Client.hh"
#include			"Game/GameList.hh"
#include			"Map/Map.hh"
#include			"Error/SocketError.hpp"
#include			"FileSystem/Directory.hh"

//----------------------------------BEGIN CTOR / DTOR---------------------------------------

Client::Client():
  Thread(),
  _ptrs(new std::map<Protocol::eProtocol, void(Client::*)(Trame const &)>),
  _sockets(new std::map<eSocket, Socket *>), _socketsClient(new std::map<eSocket, SocketClient *>),
  _select(new Select), _protocol(new Protocol), _id(0),
  _info(NULL)
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
  bool				initialized = false;

  while (!initialized)
    {
      while (!_info)
	;
      initialized = this->initialize();
      if (!initialized)
	{
	  delete _info;
	  _info = NULL;
	}
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
void				Client::launchGame(Trame const &) { }
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

void				Client::dead(Trame const &) { }
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

  if (_select->isSet((*_socketsClient)[sock]->getSocket(), Select::READ))
    {
      memset(buff, 0, SIZE_BUFFER);
      tmp = "";
      while (tmp.find(END_TRAME) == std::string::npos)
	{
	  (*_socketsClient)[sock]->readSocket(buff, SIZE_BUFFER);
	  tmp += buff;
	}
      tmpTrame = Trame::toTrame(tmp);
      if (tmpTrame)
      	manager->pushTrame(tmpTrame, CircularBufferManager::READ_BUFFER);
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
  FileSystem::Directory		*dir = new FileSystem::Directory("Res");
  dir->updateEntries();
  std::list<FileSystem::Entry *>	tmpList = dir->getEntries();

  for (auto it = tmpList.begin() ; it != tmpList.end() ; it++)
    {
      if ((*it)->getType() == FileSystem::FILE)
	std::cout << (*it)->getPath() << std::endl;
    }
  try
    {
      (*_sockets)[TCP]->initialize("TCP");
      (*_sockets)[UDP]->initialize("UDP");
      (*_socketsClient)[UDP] = (*_sockets)[UDP]->connectToAddr("127.0.0.1", 4242);
      (*_socketsClient)[TCP] = (*_sockets)[TCP]->connectToAddr("127.0.0.1", 4242);
      // (*_socketsClient)[UDP] = (*_sockets)[UDP]->connectToAddr(_info->getIp(), std::stoi(_info->getPort()));
      // (*_socketsClient)[TCP] = (*_sockets)[TCP]->connectToAddr(_info->getIp(), std::stoi(_info->getPort()));
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

void				Client::destroy(void)
{
  (*_sockets)[TCP]->destroy();
  (*_sockets)[UDP]->destroy();
}

void				Client::loop(void)
{
  CircularBufferManager		*manager = CircularBufferManager::getInstance();
  bool				run = true;
  Trame				*tmp;
  Protocol::eProtocol		msgType;

  while (run)
    {
      manager->pushTrame(new Trame(_id, 5, "UDP", "GAMELIST", true), CircularBufferManager::WRITE_BUFFER);
      this->write();
      this->read(0, 0, false);
      tmp = manager->popTrame(CircularBufferManager::READ_BUFFER);
      msgType = _protocol->getMsg(tmp);
      (this->*(*_ptrs)[msgType])(*tmp);
    }
}

//-----------------------------------END METHODS----------------------------------------

//-----------------------------BEGIN GETTERS / SETTERS----------------------------------

void				Client::setConnectInfo(ConnectInfo *info) {_info = info;}
ConnectInfo			*Client::getConnectInfo() const {return _info;}

//------------------------------END GETTERS / SETTERS-----------------------------------
