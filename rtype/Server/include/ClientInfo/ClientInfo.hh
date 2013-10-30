//
// ClientInfo.hh for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 15:46:04 2013 laurent ansel
// Last update Tue Oct 29 16:40:30 2013 laurent ansel
//

#ifndef 			__CLIENTINFO_HH__
# define 			__CLIENTINFO_HH__

#include			"Command/Command.hh"
#include			"Socket/SocketClient.hpp"

class				ClientInfo
{
private:
  SocketClient			*_clientInfo;
  std::list<Command *>		*_command;
  std::list<Trame *>		*_write;
public:
  ClientInfo(SocketClient *);
  virtual ~ClientInfo();
  Command const			&getFirstCommand() const;
  void				pushCommand(Trame *trame);
  
};

#endif
