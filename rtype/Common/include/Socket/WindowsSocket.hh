//
// WindowsSocket.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 13:23:52 2013 laurent ansel
// Last update Wed Oct 30 10:04:13 2013 laurent ansel
//

#ifndef 			__WINDOWSSOCKET_HH__
# define 			__WINDOWSSOCKET_HH__

#ifdef _WIN32

#include			<iostream>
#include			<WinSock2.h>
#include			"Socket/ISocket.hh"

class				WindowsSocket : public ISocket
{
private:
  SOCKET			_socket;
  WSADATA			_wsaData;
public:
  WindowsSocket();
  virtual ~WindowsSocket();
  virtual int			initialize(std::string const &);
  virtual int			destroy();
  virtual int			bindSocket(int const);
  virtual int			listenSocket();
  virtual SocketClient		*connectToAddr(std::string const &, int const);
  virtual SocketClient		*acceptConnection();
};

#endif

#endif
