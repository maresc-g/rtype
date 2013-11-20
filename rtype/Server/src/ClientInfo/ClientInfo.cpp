//
// ClientInfo.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 15:45:31 2013 laurent ansel
// Last update Wed Nov 20 18:31:08 2013 laurent ansel
//

#include			<unistd.h>
#include			"ClientInfo/ClientInfo.hh"

ClientInfo::ClientInfo(SocketClient *clientTcp, SocketClient *clientUdp, unsigned int const id):
  _clientInfo(new std::map<std::string, SocketClient *>),
  _command(new std::list<Command *>),
  _nbTrame(new std::map<std::string, int>),
  _id(id),
  _mutex(new Mutex),
  _trameId(1),
  _idGame(0)
{
  this->_mutex->initialize();
  this->_clientInfo->insert(std::make_pair("TCP", clientTcp));
  this->_clientInfo->insert(std::make_pair("UDP", clientUdp));
  this->_nbTrame->insert(std::make_pair("TCP", 0));
  this->_nbTrame->insert(std::make_pair("UDP", 0));
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
  for (std::list<Command *>::iterator it = this->_command->begin() ; it != this->_command->end() ; ++it)
    if (*it)
      delete *it;
  delete this->_command;
  delete this->_nbTrame;
  delete this->_clientInfo;
  this->_mutex->destroy();
  delete this->_mutex;
}

bool				ClientInfo::standbyCommand() const
{
  this->_mutex->enter();
  if (!this->_command->empty())
    {
      this->_mutex->leave();
      getFirstCommand();
      this->_mutex->enter();
    }
  if (this->_command->empty())
    {
      this->_mutex->leave();
      return (false);
    }
  this->_mutex->leave();
  return (true);
}

Command const			*ClientInfo::getFirstCommand() const
{
  this->_mutex->enter();
  Command			*command = this->_command->front();

  if (command && command->getAction().empty())
    {
      if (command)
	delete command;
      this->_command->pop_front();
      if (!this->_command->empty())
	command = this->_command->front();
      else
	command = NULL;
    }
  this->_mutex->leave();
  return (command);
}

void				ClientInfo::setCommand()
{
  Trame				*tmp = NULL;

  this->_mutex->enter();
  tmp = CircularBufferManager::getInstance()->popTrame(this->_id, "TCP", CircularBufferManager::READ_BUFFER);
  if (tmp)
    {
      this->_command->push_back(new Command(tmp));
      this->_command->back()->trameToAction();
    }
  else
    {
      tmp = CircularBufferManager::getInstance()->popTrame(this->_id, "UDP", CircularBufferManager::READ_BUFFER);
      if (tmp)
	{
	  this->_command->push_back(new Command(tmp));
	  this->_command->back()->trameToAction();
	}
    }
  this->_mutex->leave();
}

void				ClientInfo::pushCommand(Trame *trame)
{
  this->_mutex->enter();
  this->_command->push_back(new Command(trame));
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

Action const			&ClientInfo::getAction() const
{
  return (this->getFirstCommand()->getAction());
}

void				ClientInfo::setAction(Action const &action)
{
  this->_mutex->enter();
  Command			*command = this->_command->front();
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
