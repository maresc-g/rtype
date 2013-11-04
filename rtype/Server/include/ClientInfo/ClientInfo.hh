//
// ClientInfo.hh for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 15:46:04 2013 laurent ansel
// Last update Sat Nov  2 17:22:45 2013 laurent ansel
//

#ifndef 			__CLIENTINFO_HH__
# define 			__CLIENTINFO_HH__

#include			<map>
#include			<utility>
#include			"Mutex/Mutex.hpp"
#include			"Command/Command.hh"
#include			"Socket/SocketClient.hpp"

class				ClientInfo
{
private:
  std::map<std::string, SocketClient *>	*_clientInfo;
  std::list<Command *>		*_command;
  std::map<std::string, int>	*_nbTrame;
  unsigned int			_id;
  Mutex				*_mutex;
public:
  ClientInfo(SocketClient *clientTcp, SocketClient *clientUdp = NULL, unsigned int const id = 0);
  virtual ~ClientInfo();
  Command const			&getFirstCommand() const;
  void				pushCommand(Trame *trame);
  void				setCommand();
  void				setId(unsigned int const id);
  unsigned int			getId() const;
  int				getFdTcp() const;
  bool				writeSomething() const;
  void				setClientUdp(SocketClient *client);
  bool				alreadySetUdp() const;
  SocketClient			*getClientTcp() const;
  SocketClient			*getClientUdp() const;
  void				wantWrite(std::string const &proto, Trame *trame);
  void				wantWriteImmediately(std::string const &proto, Trame *trame) const;
  void				writeOneTrame(std::string const &proto);
  int				readSomethingInSocket(std::string const &proto);
};

#endif
