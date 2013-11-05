//
// Client.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Oct 29 16:28:39 2013 guillaume marescaux
// Last update Mon Nov  4 17:29:55 2013 guillaume marescaux
//

#include <string.h>
#include <iostream>
#include			"Core/Client.hh"

//----------------------------------BEGIN CTOR / DTOR---------------------------------------

Client::Client():
  _ptrs(new std::map<Protocol::eProtocol, void(Client::*)(Trame const &)>),
  _sockets(new std::map<eSocket, Socket *>), _socketsClient(new std::map<eSocket, SocketClient *>),
  _select(new Select), _protocol(new Protocol), _id(0)
{
  // ptrs
  _ptrs->insert(std::pair<Protocol::eProtocol, void(Client::*)(Trame const &)>(Protocol::WELCOME, &Client::welcome));
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
  for (auto it = _socketsClient->begin() ; it != _socketsClient->end() ; it++)
    {
      // if ((*it).second)
      // 	delete (*it).second;
    }
  delete _socketsClient;
  delete _select;
  delete _protocol;
}

//-----------------------------------END CTOR / DTOR----------------------------------------

//--------------------------------BEGIN PRIVATE METHODS-------------------------------------

void				Client::welcome(Trame const &trame)
{
  _id = trame.getHeader().getId();
}

void				Client::getGamelist(Trame const &)
{
}
void				Client::ok(Trame const &) { }
void				Client::ko(Trame const &) { }
void				Client::launchGame(Trame const &) { }
void				Client::map(Trame const &) { }
void				Client::enemy(Trame const &) { }
void				Client::projectile(Trame const &) { }
void				Client::player(Trame const &) { }
void				Client::scroll(Trame const &) { }
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

void				Client::initialize(void)
{
  CircularBufferManager		*manager = CircularBufferManager::getInstance();
  Trame				*tmp;
  Protocol::eProtocol		msgType;

  (*_sockets)[TCP]->initialize("TCP");
  (*_sockets)[UDP]->initialize("UDP");
  (*_socketsClient)[UDP] = (*_sockets)[UDP]->connectToAddr("127.0.0.1", 4243);
  (*_socketsClient)[TCP] = (*_sockets)[TCP]->connectToAddr("127.0.0.1", 4243);
  this->read(0, 0, false);
  tmp = manager->popTrame(CircularBufferManager::READ_BUFFER);
  msgType = _protocol->getMsg(tmp);
  (this->*(*_ptrs)[msgType])(*tmp);
  std::cout << _id << std::endl;
  delete tmp;
  _protocol->protocolMsg(Protocol::INITIALIZE, _id, NULL);
  this->write();
  this->read(0, 0, false);
  tmp = manager->popTrame(CircularBufferManager::READ_BUFFER);
  delete tmp;
}

void				Client::destroy(void)
{
  (*_sockets)[TCP]->destroy();
  (*_sockets)[UDP]->destroy();
}

void				Client::loop(void)
{
  // CircularBufferManager		*manager = CircularBufferManager::getInstance();
  // Trame				*trame;

  while (1)
    {
      // trame = new Trame(new Header(1), "toto\n");
    }
}

//-----------------------------------END METHODS----------------------------------------
