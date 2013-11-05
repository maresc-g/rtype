//
// Server.cpp for  in /home/ansel_l/Documents/Rtype/work/Server/include
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 20:02:48 2013 laurent ansel
// Last update Tue Nov  5 18:22:31 2013 laurent ansel
//

#include			<list>
#include			<sstream>
#include			<signal.h>
#include			"GameLoop/GameLoopManager.hh"
#include			"Server/Server.hh"
#include			"CircularBufferManager/CircularBufferManager.hh"

bool				quit = false;

void				ctrl_c(int)
{
  quit = true;
#ifdef DEBUG_SERVER
  std::cout << "\b\bSignal : ctrl-c" << std::endl;
#endif
}

Server::Server(int const port):
  _clientId(1),
  _socket(new std::map<std::string, Socket *>),
  _select(new Select),
  _client(new std::list<ClientInfo *>)
{
  CircularBufferManager::getInstance();
  GameLoopManager::getInstance();
  this->_socket->insert(std::make_pair("TCP" , new Socket));
  this->debug("Initialize tcp socket ...");
  (*this->_socket)["TCP"]->initialize("TCP");
  this->debug("Done\nBind tcp socket ...");
  (*this->_socket)["TCP"]->bindSocket(port);
  this->debug("Done\nlisten ...");
  (*this->_socket)["TCP"]->listenSocket();
  this->debug("Done");
  this->_socket->insert(std::make_pair("UDP" , new Socket));
  this->debug("Initialize udp socket ...");
  (*this->_socket)["UDP"]->initialize("UDP");
  this->debug("Done\nBind udp socket ...");
  (*this->_socket)["UDP"]->bindSocket(port);
  this->debug("Done");
  (*this->_socket)["UDP"]->initAddr();
}

Server::~Server()
{
  if ((*this->_socket)["TCP"])
    {
      (*this->_socket)["TCP"]->destroy();
      delete (*this->_socket)["TCP"];
    }
  if ((*this->_socket)["UDP"])
    {
      (*this->_socket)["UDP"]->destroy();
      delete (*this->_socket)["UDP"];
    }
  delete _socket;
  for (std::list<ClientInfo *>::iterator it = this->_client->begin() ; it != this->_client->end() ; ++it)
    if (*it)
      delete *it;
  delete _client;
  delete _select;
  CircularBufferManager::deleteInstance();
}

void				Server::debug(std::string const &str) const
{
#ifdef DEBUG_SERVER
  std::cout << str << std::endl;
#endif
}

void				Server::initializeSelect() const
{
  bool				timeout = false;

  this->_select->clear();
  this->_select->pushFd((*this->_socket)["TCP"]->getSocket().getSocket(), Select::READ);
  this->_select->pushFd((*this->_socket)["UDP"]->getSocket().getSocket(), Select::READ);
  for (std::list<ClientInfo *>::iterator it = this->_client->begin() ; it != this->_client->end() ; ++it)
    {
      this->_select->pushFd((*it)->getFdTcp(), Select::READ);
      if ((*it)->writeSomething("TCP"))
	{
	  this->_select->pushFd((*it)->getFdTcp(), Select::WRITE);
	  timeout = true;
	}
      if ((*it)->writeSomething("UDP"))
	{
	  this->_select->pushFd((*this->_socket)["UDP"]->getSocket().getSocket(), Select::WRITE);
	  timeout = true;
	}
    }
  if (timeout)
    this->_select->setTimeout(0, 0);
  this->debug("Run Select ...");
  this->_select->runSelect(timeout);
  this->debug("Done");
}

void				Server::newClient()
{
  SocketClient			*client;

  if (this->_select->isSet((*this->_socket)["TCP"]->getSocket().getSocket(), Select::READ))
    {
      if ((client = (*this->_socket)["TCP"]->acceptConnection()))
	{
#ifdef DEBUG_SERVER
	  std::cout << "New Client: " << this->_clientId << std::endl;
#endif
	  this->_client->push_back(new ClientInfo(client, NULL, this->_clientId));
	  this->_client->back()->wantWrite("TCP", new Trame(this->_clientId, 0, "TCP", "BIENVENUE", true));
	  this->_clientId++;
	}
    }
}

void				Server::recvTrameUdp()
{
  char				tmp[SIZE_BUFFER] = "";
  Trame				*trame;
  std::string			str;

  if (this->_select->isSet((*this->_socket)["UDP"]->getSocket().getSocket(), Select::READ))
    {
      this->debug("Recv UDP trame ...");
      (*this->_socket)["UDP"]->getSocket().readSocket(tmp, SIZE_BUFFER);
      this->debug("Done");
      str = tmp;
      trame = new Trame(str);
      if (trame->getContent().find("INITIALIZE") != std::string::npos)
	{
	  this->debug("Initialize UDP ...");
	  for (std::list<ClientInfo *>::iterator it = this->_client->begin() ; it != this->_client->end() ; ++it)
	    {
	      std::cout << "id : " << (*it)->getId() << "\tclient id : " << trame->getHeader().getId() << "\tAlreadySetUdp : " << (*it)->alreadySetUdp() << std::endl;
	      if ((*it)->getId() == trame->getHeader().getId() && !(*it)->alreadySetUdp())
		{
		  this->debug("Initialize UDP2 ...");
		  (*it)->setClientUdp(new SocketClient((*this->_socket)["UDP"]->getSocket().getSocket(), "UDP", (*this->_socket)["UDP"]->getSocket().getAddr()));
		  trame->getHeader().setTrameId(0);
		  trame->getHeader().setProto("TCP");
		  trame->setContent("CHECK" + std::string(END_TRAME));
		  (*it)->wantWrite("TCP", trame);
		  //		  CircularBufferManager::getInstance()->pushTrame(trame, CircularBufferManager::WRITE_BUFFER);
		}
	    }
	  this->debug("Done");
	}
      else
	CircularBufferManager::getInstance()->pushTrame(trame, CircularBufferManager::READ_BUFFER);
    }
}

std::list<ClientInfo *>::iterator	&Server::deleteClient(std::list<ClientInfo *>::iterator &it)
{
  ClientInfo				*tmp = *it;

#ifdef DEBUG_SERVER
  std::cout << "delete client " << tmp->getId() << " ..." << std::endl;
#endif
  CircularBufferManager::getInstance()->deleteTrame(tmp->getId());
  delete tmp;
  it = this->_client->erase(it);
  this->debug("Done");
  return (it);
}

void				Server::readAndWriteClient()
{
  for (std::list<ClientInfo *>::iterator it = this->_client->begin() ; !this->_client->empty() && it != this->_client->end() ; ++it)
    {
      if (this->_select->isSet((*it)->getFdTcp(), Select::READ))
	{
	  this->debug("Read TCP Trame ...");
	  if ((*it)->readSomethingInSocket("TCP") <= 0)
	    {
	      this->debug("Done");
	      it = this->deleteClient(it);
	      this->debug("Done");
	      continue;
	    }
	  else
	    this->debug("Done");
	}
      if (this->_select->isSet((*it)->getFdTcp(), Select::WRITE))
	{
	  this->debug("Write TCP Trame ...");
	  (*it)->writeOneTrame("TCP");
	  this->debug("Done");
	}
      if (this->_select->isSet((*this->_socket)["UDP"]->getSocket().getSocket(), Select::WRITE))
	{
	  this->debug("Write UDP Trame ...");
	  (*it)->writeOneTrame("UDP");
	  this->debug("Done");
	}
    }
}

bool				Server::manageQuit(std::list<ClientInfo *>::iterator &it)
{
  bool				ret = false;

  if ((*it)->standbyCommand())
    {
      if ((*it)->getFirstCommand() && (*it)->getFirstCommand()->getAction().getQuitGame())
	{
	  if (GameLoopManager::getInstance()->deletePlayer(*it))
	    {
	      ret = true;
	      (*it)->getFirstCommand()->getAction().setQuitGame(false);
	      this->debug("Client Quit Game");
	    }
	  else
	    this->debug("Game Not Exist");
	}
      if ((*it)->getFirstCommand() && (*it)->getFirstCommand()->getAction().getQuitAll())
	{
	  (*it)->getFirstCommand()->getAction().setQuitAll(false);
	  it = this->deleteClient(it);
	  this->debug("Client Quit All");
	  ret = true;
	}
    }
  return (ret);
}

bool				Server::manageGame(std::list<ClientInfo *>::iterator &it)
{
  bool				ret = false;

  if ((*it)->standbyCommand())
    {
      if ((*it)->getFirstCommand() && (*it)->getFirstCommand()->getAction().getGameList())
	{
	  std::ostringstream	tmp;
	  std::list<Trame *>	*trame;

	  tmp << "GAMELIST" << GameLoopManager::getInstance()->listInfoGame();
	  trame = Trame::ToListTrame((*it)->getId(), (*it)->getTrameId(), "UDP", tmp.str());
	  if (trame)
	    {
	      for (std::list<Trame *>::iterator itT = trame->begin() ; itT != trame->end() ; ++itT)
		{
		  this->debug((*itT)->toString());
		  (*it)->wantWrite("UDP", (*itT));
		}
	    }
	  (*it)->getFirstCommand()->getAction().setGameList(false);
	}
      if ((*it)->getFirstCommand() && (*it)->getFirstCommand()->getAction().getJoin())
	{
	  std::istringstream	str((*it)->getFirstCommand()->getAction().getParam());
	  size_t		id;

	  str >> id;
	  if (GameLoopManager::getInstance()->addPlayerInGame(*it, id))
	    {
	      (*it)->getFirstCommand()->getAction().setJoin(false);
	      this->debug("Join Game");
	      ret = true;
	    }
	}
      if ((*it)->getFirstCommand() && (*it)->getFirstCommand()->getAction().getCreate())
	{
	  GameLoopManager::getInstance()->pushNewGame((*it)->getFirstCommand()->getAction().getParam());
	  (*it)->getFirstCommand()->getAction().setCreate(false);
	  this->debug("Create Game");
	  ret = true;
	}
    }
  return (ret);
}

void				Server::execCommand()
{
  for (std::list<ClientInfo *>::iterator it = this->_client->begin() ; it != this->_client->end() && !this->_client->empty() ; ++it)
    {
      if (*it)
	{
	  this->debug("New Command ...");
	  (*it)->setCommand();
	  this->debug("Done");
	  this->debug("Check Command ...");
	  if (!this->manageQuit(it))
	    this->manageGame(it);
	  this->debug("Done");
	}
    }
}

void				Server::quitAllClient() const
{
  GameLoopManager::getInstance()->quitAllGame();
  for (std::list<ClientInfo *>::iterator it = this->_client->begin() ; it != this->_client->end() ; ++it)
    {
      CircularBufferManager::getInstance()->deleteTrame((*it)->getId());
      (*it)->wantWriteImmediately("TCP", new Trame(this->_clientId, 0, "TCP", "Server Shutdown ...\nSorry for the inconvenience", true));
    }
}

void				Server::run()
{
  signal(SIGINT, &ctrl_c);
  while (!quit)
    {
      this->initializeSelect();
      if (!quit)
	this->newClient();
      if (!quit)
	this->recvTrameUdp();
      if (!quit)
	this->readAndWriteClient();
      if (!quit)
	this->execCommand();
    }
  this->debug("Shutdown Server ...");
  this->quitAllClient();
  this->debug("GoobBye !");
}
