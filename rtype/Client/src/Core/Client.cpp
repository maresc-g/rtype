//
// Client.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Oct 29 16:28:39 2013 guillaume marescaux
// Last update Thu Nov 21 14:59:24 2013 guillaume marescaux
//

#include <iostream>

#define _USE_MATH_DEFINES
#include			<math.h>
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

Client::Client(FileSystem::Directory *dir, MutexVar<eState> *state, Action *action):
  Thread(),
  _ptrs(new std::map<Protocol::eProtocol, void(Client::*)(Trame const &)>),
  _sockets(new std::map<eSocket, Socket *>),
  _socketsClient(new std::map<eSocket, SocketClient *>),
  _select(new Select),
  _protocol(new Protocol),
  _id(0),
  _info(new MutexVar<ConnectInfo *>(NULL)),
  _running(new MutexVar<bool>(true)),
  _initialized(new MutexVar<bool>(false)),
  _dir(dir),
  _diffDir(new std::list<std::string>),
  _state(state),
  _action(action)
{
  // ptrs
  (*_ptrs)[Protocol::WELCOME] = &Client::welcome;
  (*_ptrs)[Protocol::GAMELIST] = &Client::gamelist;
  (*_ptrs)[Protocol::KO] = &Client::ko;
  (*_ptrs)[Protocol::LAUNCHGAME] = &Client::launchGame;
  (*_ptrs)[Protocol::MAP] = &Client::map;
  (*_ptrs)[Protocol::ENTITY] = &Client::entity;
  (*_ptrs)[Protocol::SCROLL] = &Client::scroll;
  (*_ptrs)[Protocol::DEAD] = &Client::dead;
  (*_ptrs)[Protocol::REMOVE_ENTITY] = &Client::removeEntity;
  (*_ptrs)[Protocol::SPRITE] = &Client::sprite;
  (*_ptrs)[Protocol::CONTENTFILE] = &Client::contentFile;
  (*_ptrs)[Protocol::LEVELUP] = &Client::levelUp;
  (*_ptrs)[Protocol::ENDGAME] = &Client::endGame;
  (*_ptrs)[Protocol::SERVERQUITTED] = &Client::serverQuit;
  // sockets
  (*_sockets)[TCP] = new Socket;
  (*_sockets)[UDP] = new Socket;
  (*_socketsClient)[TCP] = NULL;
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

  map["id"] = "";
  map["name"] = "";
  map["numPlayer"] = "";
  map["level"] = "";
  return (map);
}

std::map<std::string, std::string>	Client::initMapGetMap()
{
  std::map<std::string, std::string>	map;

  map["id"] = "";
  map["type"] = "";
  map["x"] = "";
  map["y"] = "";
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
	    sf::microseconds(10000);
	  _initialized->setVar(this->initialize());
	  if (!_initialized->getVar())
	    {
	      delete _info->getVar();
	      _info->setVar(NULL);
	    }
	}
      // if (_state->getVar() == WAIT_SPRITE)
      // 	{
      // 	  for (auto it = _diffDir->begin() ; it != _diffDir->end() ; it++)
      // 	    _protocol->protocolMsg(Protocol::GET_SPRITE, _id, reinterpret_cast<void *>(&(*it)));
      // 	  _diffDir->clear();
      // 	}
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

  gameList->clear();
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
  *_state = IN_LOBBY;
}

void				Client::ko(Trame const &)
{
  _state->setVar(IN_LOBBY);
}

void				Client::launchGame(Trame const &)
{
  _state->setVar(PLAYING);
}

void				Client::map(Trame const &trame)
{
  std::istringstream		iss(trame.getContent());
  std::istringstream		*tokenStream;
  std::string			token;
  static std::map<std::string, std::string>	vars = Client::initMapGetMap();
  Map				*map = Map::getInstance();

  while (iss.good() && !iss.str().empty())
    {
      iss >> token;
      tokenStream = new std::istringstream(token);
      std::getline(*tokenStream, vars["id"], ';');
      std::getline(*tokenStream, vars["type"], ';');
      std::getline(*tokenStream, vars["x"], ';');
      std::getline(*tokenStream, vars["y"], ';');
      map->addDecor(new Entity(std::stoi(vars["id"]), std::stoi(vars["x"]), std::stoi(vars["y"]), vars["type"]));
      delete tokenStream;
    }  
}

void				Client::entity(Trame const &trame)
{
  Map				*map = Map::getInstance();
  std::istringstream		iss(trame.getContent());
  std::string			token;
  int				id;
  std::string			type;
  int				x;
  int				y;
  int				saveX;
  int				saveY;
  int				retX;
  int				retY;
  Entity const			*entity;
  std::string			direction;
  double			norme1;
  double			norme2;
  double			scal;
  double			cosA;
  double			angle;

  std::getline(iss, token, ';');
  id = std::stoi(token);
  std::getline(iss, token, ';');
  type = token;
  std::getline(iss, token, ';');
  x = std::stoi(token);
  std::getline(iss, token, ';');
  y = std::stoi(token);
  if (map->exists(id))
    {
      entity = map->getEntityById(id);
      saveX = entity->getX();
      saveY = entity->getY();
      retX = x - saveX;
      retY = saveY - y;
      norme1 = sqrt(pow(retX, 2) + pow(retY, 2));
      norme2 = sqrt(pow(1, 2) + pow(0, 2));
      scal = retX * 1 + retY * 0;
      cosA = scal / (norme1 * norme2);
      angle = acos(cosA) * 180.0 / M_PI;
      if (angle >= 0 && angle <= 23)
	direction = "right";
      else if (angle > 23 && angle <= 68)
	direction = (retY >= 0 ? "right_up" : "right_down");
      else if (angle > 68 && angle <= 113)
	direction = (retY >= 0 ? "up" : "down");
      else if (angle > 113 && angle <= 158)
	direction = (retY >= 0 ? "left_up" : "left_down");
      else
	direction = "left";
      std::cout << "DIRECTION = " << direction << std::endl;
      map->moveEntity(id, x, y, direction);
    }
  else
    map->addEntity(new Entity(id, x, y, type));
}

void				Client::scroll(Trame const &trame)
{
  Map				*map = Map::getInstance();

  map->setScroll(std::stoi(trame.getContent()));
}

void				Client::removeEntity(Trame const &trame)
{
  Map				*map = Map::getInstance();

  map->removeEntity(std::stoi(trame.getContent()));
}

void				Client::dead(Trame const &)
{
  *_state = DEAD;
}

void				Client::sprite(Trame const &trame)
{
  _dir->updateEntries();

  std::map<std::string, std::string>		files;
  std::list<FileSystem::Entry *>		tmpList = _dir->getEntries();
  std::istringstream				iss(trame.getContent());
  std::istringstream				*tokenStream;
  std::string					fileInfo;
  std::string					fileName;
  std::string					fileMd5;
  std::ifstream					ifs;
  std::string					c;
  std::string					content;
  std::function<bool(std::string const &)>	inDir = [&](std::string const &fileName)
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
      iss >> fileInfo;
      tokenStream = new std::istringstream(fileInfo);
      std::getline(*tokenStream, fileName, ';');
      std::getline(*tokenStream, fileMd5, ';');
      files[fileName] = fileMd5;
      delete tokenStream;
    }
  for (auto it = files.begin() ; it != files.end() ; it++)
    {
      if (!inDir((*it).first))
	_diffDir->push_back((*it).first);
      // else
      // 	{
      // 	  ifs.open((*it).first);
      // 	  if (ifs.is_open())
      // 	    {
      // 	      c = ifs.get();
      // 	      content = "";
      // 	      while (ifs.good())
      // 		{
      // 		  content += c;
      // 		  c = ifs.get();
      // 		}
      // 	      if (md5(content) != files[(*it).first])
      // 		_diffDir->push_back((*it).first);
      // 	    }
      // 	  else
      // 	    _diffDir->push_back((*it).first);
      // 	}
    }
  // _state->setVar(WAIT_SPRITE);
}

void				Client::contentFile(Trame const &trame)
{ 
  std::istringstream		iss(trame.getContent());
  std::string			fileName;
  std::string			content;

  std::cout << "CONTENTFILE BEGIN" << std::endl;
  std::getline(iss, fileName, ';');
  std::cout << "FILENAME " << fileName << std::endl;
  std::ofstream			out;

  std::getline(iss, content, ';');
  // out.write(content.c_str(), content.size());
  out.open(fileName.c_str(), std::ofstream::out | std::ofstream::trunc);
  // out.write(content.c_str(), content.size());
  out << content;
  out.close();
  std::cout << "CONTENTFILE END" << std::endl;
}

void				Client::levelUp(Trame const &)
{
  *_state = WAIT_GAME;
}


void				Client::endGame(Trame const &)
{
  *_state = IN_LOBBY;
}

void				Client::serverQuit(Trame const &)
{
  this->destroy();
  *_state = IN_LOGIN;
}

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
      if (tmp->getHeader().getProto() == "TCP")
	{
	  if (_select->isSet((*_socketsClient)[TCP]->getSocket(), Select::WRITE))
	    writeToSocket(*tmp, Client::TCP);
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
  std::list<Trame *>		*tmpTrame;
  int				size;

  if (_select->isSet((*_socketsClient)[sock]->getSocket(), Select::READ))
    {
      memset(buff, 0, SIZE_BUFFER);
      tmp = "";
      while (tmp.rfind(END_TRAME) == std::string::npos)
	{
	  size = (*_socketsClient)[sock]->readSocket(buff, SIZE_BUFFER);
	  if (size > 0)
	    tmp.append(buff, size);
	  else
	    {
	      this->destroy();
	      *_state = IN_LOGIN;
	      return;
	    }
	}
      tmpTrame = Trame::cutToListTrame(tmp); 
      // std::cout << "TO STRING = ";
      // std::cout.write(tmp.c_str(), tmp.size());
      // std::cout << std::endl;
      if (tmpTrame)
	{
	  for (auto it = tmpTrame->begin() ; it != tmpTrame->end() ; it++)
	    {
	      manager->pushTrame((*it), CircularBufferManager::READ_BUFFER);
	    }
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

  *_state = CONNECTING;
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
      *_state = ERROR_CONNECT;
      return (false);
    }
  catch (std::invalid_argument const &e)
    {
      *_state = ERROR_CONNECT;
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
      if (msgType == Protocol::SERVERQUITTED)
	{
	  *_state = ERROR_CONNECT;
	  return (false);
	}
      delete tmp;
    }
  *_state = CONNECTED;
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
  std::string			actionStr;
  sf::Clock	clock;
  sf::Time	elapsedTime;
  float		time;

  clock.restart();
  this->read(0, 0, true);
  tmp = manager->popTrame(CircularBufferManager::READ_BUFFER);
  if (tmp)
    {
      // std::cout << "CONTENT = ";
      // std::cout.write(tmp->getContent().c_str(), tmp->getContent().size());
      std::cout << std::endl;
      msgType = _protocol->getMsg(tmp);
      // std::cout << "MSG_TYPE = " << static_cast<int>(msgType) << std::endl;
      (this->*(*_ptrs)[msgType])(*tmp);
    }
  actionStr = (std::string)(*_action);
  if (_state->getVar() == PLAYING && !_action->empty())
    {
      _protocol->protocolMsg(Protocol::ACTION, _id, &actionStr);
      _action->reset();
    }
  this->write();
  elapsedTime = clock.getElapsedTime();
  time = 100000 / 60 - elapsedTime.asMicroseconds();
  if (time > 0)
    sf::sleep(sf::microseconds(time));
}

//-----------------------------------END METHODS----------------------------------------

//-----------------------------BEGIN GETTERS / SETTERS----------------------------------

void				Client::setConnectInfo(ConnectInfo *info) { _info->setVar(info); }
ConnectInfo			*Client::getConnectInfo() const { return (_info->getVar()); }
void				Client::setRunning(bool const running) { _running->setVar(running); }
bool				Client::getRunning(void) const { return (_running->getVar()); }
void				Client::setInitialized(bool const initialized) { _initialized->setVar(initialized); }
bool				Client::getInitialized(void) const { return (_initialized->getVar()); }
Protocol			*Client::getProto(void) const { return (_protocol); }
int				Client::getId(void) const { return (_id); }

//------------------------------END GETTERS / SETTERS-----------------------------------
