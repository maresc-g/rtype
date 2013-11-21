//
// Server.cpp for  in /home/ansel_l/Documents/Rtype/work/Server/include
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 20:02:48 2013 laurent ansel
// Last update Thu Nov 21 15:13:25 2013 laurent ansel
//

#include			<list>
#include			<sstream>
#include			<signal.h>
#include			"GameLoop/GameLoopManager.hh"
#include			"Server/Server.hh"
#include			"CircularBufferManager/CircularBufferManager.hh"
#include			"SpriteLoaderManager/SpriteLoaderManager.hh"

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
  ObjectPoolManager::getInstance();
  SpriteLoaderManager::getInstance();
  DynamicLibraryManager::getInstance();
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
  GameLoopManager::deleteInstance();
  ObjectPoolManager::deleteInstance();
  SpriteLoaderManager::deleteInstance();
  DynamicLibraryManager::deleteInstance();
}

void				Server::debug(std::string const &str) const
{
#ifdef DEBUG_SERVER
  std::cout << str << std::endl;
#else
  (void)str;
#endif
}

void				Server::initializeSelect() const
{
  bool				timeout = false;
  int				delai[2] = {0, 0};

  this->_select->clear();
  this->_select->pushFd((*this->_socket)["TCP"]->getSocket().getSocket(), Select::READ);
  this->_select->pushFd((*this->_socket)["UDP"]->getSocket().getSocket(), Select::READ);
  for (std::list<ClientInfo *>::iterator it = this->_client->begin() ; it != this->_client->end() ; ++it)
    {
      if ((*it)->getIdGame() > 0 && !timeout)
	{
	  timeout = true;
	  delai[0] = 0;
	  delai[1] = 800;
	}
      this->_select->pushFd((*it)->getFdTcp(), Select::READ);
      if ((*it)->canWriteSomething("TCP"))
	{
	  this->_select->pushFd((*it)->getFdTcp(), Select::WRITE);
	  timeout = true;
	}
      if ((*it)->canWriteSomething("UDP"))
	{
	  this->_select->pushFd((*this->_socket)["UDP"]->getSocket().getSocket(), Select::WRITE);
	  timeout = true;
	}
    }
  if (!timeout)
    {
      delai[0] = 1;
      delai[1] = 0;
    }
  this->_select->setTimeout(delai[0], delai[1]);
  this->debug("Run Select ...");
  this->_select->runSelect(true);
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
	  this->_client->back()->pushWriteTrame("TCP", new Trame(this->_clientId, 0, "TCP", "BIENVENUE", true));
	  this->_clientId++;
	}
    }
}

void				Server::recvTrameUdp()
{
  char				tmp[SIZE_BUFFER] = "";
  Trame				*trame;
  std::string			str;
  int				ret;

  if (this->_select->isSet((*this->_socket)["UDP"]->getSocket().getSocket(), Select::READ))
    {
      this->debug("Recv UDP trame ...");
      if ((ret = (*this->_socket)["UDP"]->getSocket().readSocket(tmp, SIZE_BUFFER)) > 0)
	{
	  this->debug("Done");
	  str.append(tmp, ret);
	  trame = Trame::toTrame(str);
	  if (trame->getContent().find("INITIALIZE") != std::string::npos)
	    {
	      this->debug("Initialize UDP ...");
	      for (std::list<ClientInfo *>::iterator it = this->_client->begin() ; it != this->_client->end() ; ++it)
		if ((*it)->getId() == trame->getHeader().getId() && !(*it)->alreadySetUdp())
		  {
		    (*it)->setClientUdp(new SocketClient((*this->_socket)["UDP"]->getSocket().getSocket(), "UDP", (*this->_socket)["UDP"]->getSocket().getAddr()));
		    trame->getHeader().setTrameId(0);
		    trame->getHeader().setProto("TCP");
		    trame->setContent("CHECK" + std::string(END_TRAME));
		    (*it)->pushWriteTrame("TCP", trame);
		  }
	      this->debug("Done");
	    }
	  else
	    CircularBufferManager::getInstance()->pushTrame(trame, CircularBufferManager::READ_BUFFER);
	}
    }
}

std::list<ClientInfo *>::iterator	&Server::deleteClient(std::list<ClientInfo *>::iterator &it)
{
  ClientInfo				*tmp = *it;

#ifdef DEBUG_SERVER
  std::cout << "delete client " << tmp->getId() << " ..." << std::endl;
#endif
  GameLoopManager::getInstance()->deletePlayer(tmp);
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

bool				Server::manageQuit(std::list<ClientInfo *>::iterator &it, Action &action)
{
  bool				ret = false;

  if (action.getQuitGame())
    {
      if (GameLoopManager::getInstance()->deletePlayer(*it))
	{
	  ret = true;
	  action.setQuitGame(false);
	  this->debug("Client Quit Game");
	}
      else
	this->debug("Game Not Exist");
    }
  if (action.getQuitAll())
    {
      action.setQuitAll(false);
      it = this->deleteClient(it);
      this->debug("Client Quit All");
      ret = true;
    }
  return (ret);
}

bool				Server::manageGame(std::list<ClientInfo *>::iterator &it, Action &action)
{
  bool				ret = false;
  size_t			id;

  if (action.getGameList())
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
	      (*it)->pushWriteTrame("UDP", (*itT));
	    }
	  delete trame;
	}
      action.setGameList(false);
    }
  if (action.getJoin())
    {
      std::istringstream	str(action.getParam());

      str >> id;
      action.setJoin(false);
      if (GameLoopManager::getInstance()->addPlayerInGame(*it, id))
	{
	  this->debug("Join Game");
	  ret = true;
	  this->sendListSprite((*it));
	  (*it)->pushWriteTrame("TCP", new Trame((*it)->getId(), (*it)->getTrameId(), "TCP", "LAUNCHGAME", true));
	}
      else
      	(*it)->pushWriteTrame("TCP", new Trame((*it)->getId(), (*it)->getTrameId(), "TCP", "KO", true));
    }
  if (action.getCreate() && !action.getParam().empty())
    {
      this->debug("Create Game");
      id = GameLoopManager::getInstance()->pushNewGame(action.getParam());
      action.setCreate(false);
      ret = true;
      this->sendListSprite((*it));
      if (GameLoopManager::getInstance()->addPlayerInGame(*it, id))
	{
	  if (GameLoopManager::getInstance()->runGame(id))
	    (*it)->pushWriteTrame("TCP", new Trame((*it)->getId(), (*it)->getTrameId(), "TCP", "LAUNCHGAME", true));
	  else
	    (*it)->pushWriteTrame("TCP", new Trame((*it)->getId(), (*it)->getTrameId(), "TCP", "KO", true));
	}
      else
	(*it)->pushWriteTrame("TCP", new Trame((*it)->getId(), (*it)->getTrameId(), "TCP", "KO", true));
    }
  return (ret);
}

bool				Server::manageSprite(std::list<ClientInfo *>::iterator &it, Action &action)
{
  bool				ret = false;

  if (action.getGetSprite())
    {
#ifdef SEND_SPRITE_ACTIVATE
      std::ostringstream	tmp;
      Trame *trame;

      tmp << "CONTENTFILE " << SpriteLoaderManager::getInstance()->getContentFile(action.getParam());
      trame = new Trame((*it)->getId(), (*it)->getTrameId(), "TCP", tmp.str(), true);
      (*it)->pushWriteTrame("TCP", trame);
#else
      (void)it;
#endif
      action.setGetSprite(false);
    }
  return (ret);
}

void				Server::execCommand()
{
  Action			action;

  for (std::list<ClientInfo *>::iterator it = this->_client->begin() ; it != this->_client->end() && !this->_client->empty() ; ++it)
    {
      if (*it)
	{
	  this->debug("New Command ...");
	  (*it)->setCommand();
	  this->debug("Done");
	  this->debug("Check Command ...");
	  if ((*it)->actionServer() && (*it)->standbyCommand())
	    {
	      action = (*it)->getAction();
	      if (!this->manageQuit(it, action))
		{
		  this->manageGame(it, action);
		  this->manageSprite(it, action);
		}
	      (*it)->setAction(action);
	    }
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
      (*it)->writeImmediately("TCP", new Trame(this->_clientId, 0, "TCP", "SERVERQUITTED", true));
    }
}

void				Server::sendListSprite(ClientInfo *client)
{
#ifdef SEND_SPRITE_ACTIVATE
  std::list<std::string>	listSprite = SpriteLoaderManager::getInstance()->getSpriteList();
  std::list<std::string>	listConf = SpriteLoaderManager::getInstance()->getConfClientList();
  std::ostringstream		str;
  std::list<Trame *>		*trame;

  str << "SPRITE";
  for (auto it = listSprite.begin() ; it != listSprite.end() ; ++it)
    str << " " << (*it);
  for (auto it = listConf.begin() ; it != listConf.end() ; ++it)
    if ((*it) != "")
      str << " " << (*it);
  trame = Trame::ToListTrame(client->getId(), client->getTrameId(), "TCP", str.str());
  if (trame)
    {
      for (std::list<Trame *>::iterator it = trame->begin() ; it != trame->end() ; ++it)
	client->pushWriteTrame("TCP", (*it));
      delete trame;
    }
#else
  (void)client;
#endif
}

void				Server::sendSprite(ClientInfo *client, std::string const &sprite, std::string const &proto)
{
#ifdef SEND_SPRITE_ACTIVATE
  std::list<Trame *>		*trame;

  trame = Trame::ToListTrame(client->getId(), client->getTrameId(), proto, sprite);
  if (trame)
    {
      for (std::list<Trame *>::iterator it = trame->begin() ; it != trame->end() ; ++it)
	{
	  this->debug((*it)->toString());
	  client->pushWriteTrame(proto, (*it));
	}
      delete trame;
    }
#else
  (void)client;
  (void)sprite;
  (void)proto;
#endif
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
