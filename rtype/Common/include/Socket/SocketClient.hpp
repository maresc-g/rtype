//
// SocketClient.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 14:57:01 2013 laurent ansel
// Last update Tue Oct 29 16:16:14 2013 laurent ansel
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
  SocketClient(int const socket):
#ifdef _WIN32
    WindowsSocketClient(socket)
#else
    UnixSocketClient(socket)
#endif
  {}
  virtual ~SocketClient()
  {}
};

#endif
