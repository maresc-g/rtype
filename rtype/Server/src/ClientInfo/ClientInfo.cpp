//
// ClientInfo.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 15:45:31 2013 laurent ansel
// Last update Sat Nov  2 16:54:01 2013 laurent ansel
//

#include			"ClientInfo/ClientInfo.hh"

ClientInfo::ClientInfo(SocketClient *clientTcp, SocketClient *clientUdp, unsigned int const id):
  _clientInfo(new std::map<std::string, SocketClient *>),
  _command(new std::list<Command *>),
  _nbTrame(new std::map<std::string, int>),
  _id(id),
  _mutex(new Mutex)
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
}

Command const			&ClientInfo::getFirstCommand() const
{
  Command			*command = this->_command->front();

  this->_mutex->enter();
  this->_command->pop_front();
  this->_mutex->leave();
  return (*command);
}

void				ClientInfo::setCommand()
{
  this->_mutex->enter();
  // if ((*this->_nbTrame)["TCP"] > 0 || (*this->_nbTrame)["UDP"] > 0)
  //   {

  //   }
  this->_mutex->leave();
}

void				ClientInfo::pushCommand(Trame *trame)
{
  this->_mutex->enter();
  this->_command->push_back(new Command(trame));
  this->_mutex->leave();
}

void				ClientInfo::setId(unsigned int const id)
{
  this->_mutex->enter();
  this->_id = id;
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

int				ClientInfo::getFdTcp() const
{
  int				fd;

  this->_mutex->enter();
  fd = (*this->_clientInfo)["TCP"]->getSocket();
  this->_mutex->leave();
  return (fd);
}

bool				ClientInfo::writeSomething() const
{
  this->_mutex->enter();
  if ((*this->_nbTrame)["TCP"] == 0)
    {
      this->_mutex->leave();
      return (false);
    }
  this->_mutex->leave();
  return (true);
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

void				ClientInfo::wantWrite(std::string const &proto, Trame *trame)
{
  this->_mutex->enter();
  CircularBufferManager::getInstance()->pushTrame(trame, CircularBufferManager::WRITE_BUFFER);
  (*this->_nbTrame)[proto]++;
  this->_mutex->leave();
}

void				ClientInfo::writeOneTrame(std::string const &proto)
{
  Trame				*tmp;

  this->_mutex->enter();
  if ((*this->_nbTrame)[proto] > 0)
    {
      tmp = CircularBufferManager::getInstance()->popTrame(this->_id, proto, CircularBufferManager::WRITE_BUFFER);
      if (tmp)
	{
	  (*this->_clientInfo)[proto]->writeSocket(const_cast<char *>(tmp->toString().c_str()), tmp->toString().size());
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
  Trame				*trame;

  this->_mutex->enter();
  ret = (*this->_clientInfo)[proto]->readSocket(tmp, SIZE_BUFFER);
  str = tmp;
  trame = Trame::toTrame(str);
  if (ret > 0)
    CircularBufferManager::getInstance()->pushTrame(trame, CircularBufferManager::READ_BUFFER);
  this->_mutex->leave();
  return (ret);
}
