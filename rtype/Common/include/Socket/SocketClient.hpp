//
// SocketClient.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 14:57:01 2013 laurent ansel
// Last update Wed Oct 30 11:39:24 2013 laurent ansel
//

#ifndef 			__SOCKETCLIENT_HH__
# define 			__SOCKETCLIENT_HH__

#ifdef	_WIN32
#include		"Socket/WindowsSocketClient.hh"
#else
#include		"Socket/UnixSocketClient.hh"
#endif

#ifdef _WIN32
class			SocketClient : public	WindowsSocketClient
#else
class			SocketClient : public	UnixSocketClient
#endif
{
public:
  SocketClient(int const socket, std::string const &protocole):
#ifdef _WIN32
    WindowsSocketClient(socket, protocole)
#else
    UnixSocketClient(socket, protocole)
#endif
  {}
  virtual ~SocketClient()
  {}
};

#endif
