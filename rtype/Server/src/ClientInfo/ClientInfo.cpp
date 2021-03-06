//
// ClientInfo.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 15:45:31 2013 laurent ansel
// Last update Sun Nov 24 14:55:14 2013 laurent ansel
//

#ifndef				_WIN32
#include			<unistd.h>
#endif
#include			"ClientInfo/ClientInfo.hh"

ClientInfo::ClientInfo(SocketClient *clientTcp, SocketClient *clientUdp, unsigned int const id):
  _clientInfo(new std::map<std::string, SocketClient *>),
  _command(new std::map<enum ClientInfo::eType, std::list<Command *> *>),
  // _command(new std::list<Command *>),
  // _commandGame(new std::list<Command *>),
  _nbTrame(new std::map<std::string, int>),
  _id(id),
  _mutex(new Mutex),
  _trameId(1),
  _idGame(0),
  _delai(new std::list<std::pair<int, int> >)
{
  this->_mutex->initialize();
  this->_clientInfo->insert(std::make_pair("TCP", clientTcp));
  this->_clientInfo->insert(std::make_pair("UDP", clientUdp));
  this->_nbTrame->insert(std::make_pair("TCP", 0));
  this->_nbTrame->insert(std::make_pair("UDP", 0));
  this->_mutex->enter();
  (*this->_command)[ClientInfo::SERVER] = new std::list<Command *>;
  (*this->_command)[ClientInfo::GAME] = new std::list<Command *>;
  this->_mutex->leave();
}

ClientInfo::~ClientInfo()
{
  if ((*this->_clientInfo)["TCP"])
    {
      (*this->_clientInfo)["TCP"]->closeSocket();
      delete (*this->_clientInfo)["TCP"];
    }
  if ((*this->_clientInfo)["UDP"])
    delete (*this->_clientInfo)["UDP"];
  for (std::list<Command *>::iterator it = (*this->_command)[ClientInfo::GAME]->begin() ; it != (*this->_command)[ClientInfo::GAME]->end() ; ++it)
    if (*it)
      delete *it;
  for (std::list<Command *>::iterator it = (*this->_command)[ClientInfo::SERVER]->begin() ; it != (*this->_command)[ClientInfo::SERVER]->end() ; ++it)
    if (*it)
      delete *it;
  delete this->_command;
  //  delete this->_commandGame;
  delete this->_nbTrame;
  delete this->_clientInfo;
  this->_mutex->destroy();
  delete this->_mutex;
}

bool				ClientInfo::standbyCommand(enum ClientInfo::eType const type) const
{
  this->_mutex->enter();
  if (!(*this->_command)[type]->empty())
    {
      this->_mutex->leave();
      getFirstCommand(type);
      this->_mutex->enter();
    }
  if ((*this->_command)[type]->empty())
    {
      this->_mutex->leave();
      return (false);
    }
  this->_mutex->leave();
  return (true);
}

Command const			*ClientInfo::getFirstCommand(enum ClientInfo::eType const type) const
{
  this->_mutex->enter();
  if ((*this->_command)[type] && !(*this->_command)[type]->empty())
    {
      Command			*command = (*this->_command)[type]->front();

      if (command && command->getAction().empty())
	{
	  if (command)
	    delete command;
	  (*this->_command)[type]->pop_front();
	  if (!(*this->_command)[type]->empty())
	    command = (*this->_command)[type]->front();
	  else
	    command = NULL;
	}
      this->_mutex->leave();
      return (command);
    }
  this->_mutex->leave();
  return (NULL);
}

void				ClientInfo::setCommand()
{
  Trame				*tmp = NULL;
  Command			*command;
  enum ClientInfo::eType	type;

  this->_mutex->enter();
  tmp = CircularBufferManager::getInstance()->popTrame(this->_id, "TCP", CircularBufferManager::READ_BUFFER);
  if (tmp)
    {
      command = new Command(tmp);
      if (command)
	command->trameToAction();
      if (command && command->commandServer())
	type = ClientInfo::SERVER;
      else
	type = ClientInfo::GAME;
      (*this->_command)[type]->push_back(command);
    }
  else
    {
      tmp = CircularBufferManager::getInstance()->popTrame(this->_id, "UDP", CircularBufferManager::READ_BUFFER);
      if (tmp)
	{
	  command = new Command(tmp);
	  if (command)
	    command->trameToAction();
	  if (command && command->commandServer())
	    type = ClientInfo::SERVER;
	  else
	    type = ClientInfo::GAME;
	  (*this->_command)[type]->push_back(command);
	}
    }
  this->_mutex->leave();
}

void				ClientInfo::pushCommand(Trame *trame, enum ClientInfo::eType const type)
{
  this->_mutex->enter();
  (*this->_command)[type]->push_back(new Command(trame));
  this->_mutex->leave();
}

bool				ClientInfo::canWriteSomething(std::string const &proto) const
{
  this->_mutex->enter();
  if ((*this->_nbTrame)[proto] == 0)
    {
      this->_mutex->leave();
      return (false);
    }
  this->_mutex->leave();
  return (true);
}


void				ClientInfo::pushWriteTrame(std::string const &proto, Trame *trame)
{
  this->_mutex->enter();
  if (trame)
    {
      if (trame->isSetEndTrame())
	this->_trameId++;
      CircularBufferManager::getInstance()->pushTrame(trame, CircularBufferManager::WRITE_BUFFER);
      (*this->_nbTrame)[proto]++;
    }
  this->_mutex->leave();
}

void				ClientInfo::writeImmediately(std::string const &proto, Trame *trame)
{
  this->_mutex->enter();
  if (trame)
    {
      trame->getHeader().setTrameId(this->_trameId);
      this->_trameId++;
      (*this->_clientInfo)[proto]->writeSocket(const_cast<char *>(trame->toString().c_str()), trame->toString().size());
      delete trame;
    }
  this->_mutex->leave();
}

void				ClientInfo::writeOneTrame(std::string const &proto)
{
  Trame				*tmp;
  unsigned int			ret;
  std::string			str;

  this->_mutex->enter();
  if ((*this->_nbTrame)[proto] > 0)
    {
      tmp = CircularBufferManager::getInstance()->popTrame(this->_id, proto, CircularBufferManager::WRITE_BUFFER);
      if (tmp)
	{
	  str = tmp->toString();
	  ret = (*this->_clientInfo)[proto]->writeSocket(const_cast<char *>(str.c_str()), str.size());
	  if (ret < str.size())
	    {
	      str = tmp->getContent();
	      str = str.erase(0, ret);
	      tmp->setContent(str);
	      CircularBufferManager::getInstance()->pushFrontTrame(tmp, CircularBufferManager::WRITE_BUFFER);
	      (*this->_nbTrame)[proto]++;
	    }
	  else
	    delete tmp;
	}
      (*this->_nbTrame)[proto]--;
    }
  this->_mutex->leave();
}

int				ClientInfo::readSomethingInSocket(std::string const &proto)
{
  char				tmp[SIZE_BUFFER] = "";
  int				ret;
  std::string			str;
  std::list<Trame *>		*trame = NULL;

  this->_mutex->enter();
  ret = (*this->_clientInfo)[proto]->readSocket(tmp, SIZE_BUFFER);
  if (ret > 0)
    {
      str.append(tmp, ret);
      trame = Trame::cutToListTrame(str);
    }
  if (trame)
    {
      for (auto it = trame->begin() ; it != trame->end() ; ++it)
	{
	  if (ret > 0 && *it)
	    CircularBufferManager::getInstance()->pushTrame(*it, CircularBufferManager::READ_BUFFER);
	  else if (ret > 0 && !(*it))
	    {
	      CircularBufferManager::getInstance()->pushTrame(new Trame(this->_id, this->_trameId, proto, "ERROR TRAME", true), CircularBufferManager::WRITE_BUFFER);
	      (*this->_nbTrame)[proto]++;
	      this->_trameId++;
	    }
	}
      delete trame;
    }
  this->_mutex->leave();
  return (ret);
}

unsigned int			ClientInfo::getIdGame() const
{
  unsigned int			id;

  this->_mutex->enter();
  id = this->_idGame;
  this->_mutex->leave();
  return (id);

}

void				ClientInfo::setIdGame(unsigned int const idGame)
{
  this->_mutex->enter();
  this->_idGame = idGame;
  this->_mutex->leave();
}

Action const			&ClientInfo::getAction(enum ClientInfo::eType const type) const
{
  return (this->getFirstCommand(type)->getAction());
}

void				ClientInfo::setAction(Action const &action, enum ClientInfo::eType const type)
{
  this->_mutex->enter();
  Command			*command = (*this->_command)[type]->front();

  command->setAction(action);
  this->_mutex->leave();
}

void				ClientInfo::setId(unsigned int const id)
{
  this->_mutex->enter();
  this->_id = id;
  this->_mutex->leave();
}

void				ClientInfo::setTrameId(unsigned int const trameId)
{
  this->_mutex->enter();
  this->_trameId = trameId;
  this->_mutex->leave();
}

unsigned int			ClientInfo::getId() const
{
  unsigned int			id;

  this->_mutex->enter();
  id = this->_id;
  this->_mutex->leave();
  return (id);
}

unsigned int			ClientInfo::getTrameId() const
{
  unsigned int			id;

  this->_mutex->enter();
  id = this->_trameId;
  this->_mutex->leave();
  return (id);
}

int				ClientInfo::getFdTcp() const
{
  int				fd;

  this->_mutex->enter();
  fd = (*this->_clientInfo)["TCP"]->getSocket();
  this->_mutex->leave();
  return (fd);
}

void				ClientInfo::setClientUdp(SocketClient *client)
{
  this->_mutex->enter();
  (*this->_clientInfo)["UDP"] = client;
  this->_mutex->leave();
}

bool				ClientInfo::alreadySetUdp() const
{
  this->_mutex->enter();
  if ((*this->_clientInfo)["UDP"])
    {
      this->_mutex->leave();
      return (true);
    }
  this->_mutex->leave();
  return (false);
}

SocketClient			*ClientInfo::getClientTcp() const
{
  SocketClient			*tmp;

  this->_mutex->enter();
  tmp = (*this->_clientInfo)["TCP"];
  this->_mutex->leave();
  return (tmp);
}

SocketClient			*ClientInfo::getClientUdp() const
{
  SocketClient			*tmp;

  this->_mutex->enter();
  tmp = (*this->_clientInfo)["UDP"];
  this->_mutex->leave();
  return (tmp);
}

bool				ClientInfo::actionServer() const
{
  this->_mutex->enter();
  if ((*this->_command)[ClientInfo::SERVER] && !(*this->_command)[ClientInfo::SERVER]->empty())
    {
      Command			*command = (*this->_command)[ClientInfo::SERVER]->front();

      if (command && command->commandServer())
	{
	  this->_mutex->leave();
	  return (true);
	}
    }
  this->_mutex->leave();
  return (false);
}

void				ClientInfo::setDelai(int const second, int const milli)
{
  this->_mutex->enter();
  int				delai[2];

  delai[0] = second;
  delai[1] = milli;
  this->_delai->push_back(std::make_pair(delai[0], delai[1]));
  this->_mutex->leave();
}

void				ClientInfo::getDelai(int delai[2]) const
{
  this->_mutex->enter();
  std::pair<int, int>		tmp;

  if (!this->_delai->empty())
    {
      tmp = this->_delai->front();
      this->_delai->pop_front();
      delai[0] = tmp.first;
      delai[1] = tmp.second;
    }
  else
    {
      delai[0] = -1;
      delai[1] = -1;
    }
  this->_mutex->leave();
}

bool				ClientInfo::availableDelai() const
{
  this->_mutex->enter();
  if (!this->_delai->empty())
    {
      this->_mutex->leave();
      return (true);
    }
  this->_mutex->leave();
  return (false);
}

void				ClientInfo::quitGame()
{
  // Command			*command;

  this->_mutex->enter();
  this->_idGame = 0;
  for (auto it = (*this->_command)[ClientInfo::GAME]->begin() ; it != (*this->_command)[ClientInfo::GAME]->end() ; ++it)
    if ((*it))
      delete *it;
  (*this->_command)[ClientInfo::GAME]->clear();
  // if (this->_command)
  //   {
  //     for (auto it = this->_command->begin() ; it != this->_command->end() ; ++it)
  // 	{
  // 	  if ((*it))
  // 	    {
  // 	      this->_mutex->leave();
  // 	      if (!actionServer())
  // 		{
  // 		  this->_mutex->enter();
  // 		  command = (*it);
  // 		  this->_command->pop_front();
  // 		  delete command;
  // 		  if (this->_command->empty())
  // 		    break;
  // 		  this->_mutex->leave();
  // 		}
  // 	      else
  // 		{
  // 		  this->_mutex->enter();
  // 		  break;
  // 		}
  // 	    }
  // 	  this->_mutex->enter();
  // 	}
  //    }
  this->_mutex->leave();
}
