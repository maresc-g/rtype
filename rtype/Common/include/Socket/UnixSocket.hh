//
// UnixSocket.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 13:23:27 2013 laurent ansel
// Last update Wed Oct 30 10:04:05 2013 laurent ansel
//

#ifndef 			__UNIXSOCKET_HH__
# define 			__UNIXSOCKET_HH__

#ifndef _WIN32

#include			<stdio.h>
#include			<unistd.h>
#include			<sys/types.h>
#include			<sys/types.h>
#include			<netdb.h>
#include			<sys/types.h>
#include			<netinet/in.h>
#include			<arpa/inet.h>
#include			<iostream>
#include			"Socket/ISocket.hh"

class				UnixSocket : public ISocket
{
private:
  int				_socket;
public:
  UnixSocket();
  virtual ~UnixSocket();
  virtual int			initialize(std::string const &);
  virtual int			destroy();
  virtual int			bindSocket(int const);
  virtual int			listenSocket();
  virtual SocketClient		*connectToAddr(std::string const &, int const);
  virtual SocketClient		*acceptConnection();
};

#endif

#endif
