//
// ClientInfo.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 15:45:31 2013 laurent ansel
// Last update Tue Oct 29 16:40:24 2013 laurent ansel
//

#include			"ClientInfo/ClientInfo.hh"

ClientInfo::ClientInfo(SocketClient *client):
  _clientInfo(client),
  _command(new std::list<Command *>),
  _write(new std::list<Trame *>)
{

}

ClientInfo::~ClientInfo()
{

}

Command const			&ClientInfo::getFirstCommand() const
{
  Command			*command = this->_command->front();

  this->_command->pop_front();
  return (*command);
}

void				ClientInfo::pushCommand(Trame *trame)
{
  this->_command->push_back(new Command(trame));
}
