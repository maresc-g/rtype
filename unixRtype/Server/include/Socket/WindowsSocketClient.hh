//
// WindowsSocketClient.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 15:22:49 2013 laurent ansel
// Last update Mon Oct 28 16:37:58 2013 laurent ansel
//

#ifndef			__WINDOWSSOCKETCLIENT_HH__
#define			__WINDOWSSOCKETCLIENT_HH__

#ifdef _WIN32

#include		<WinSock2.h>
#include		"Socket/ISocketClient.hh"

#pragma comment(lib, "ws2_32.lib")

class			WindowsSocketClient : public ISocketClient
{
private:
  SOCKET		_socket;
public:
  WindowsSocketClient(SOCKET const);
  virtual ~WindowsSocketClient();
  virtual int		readSocket(std::string &, int const);
  virtual int		writeSocket(char *, int const);
  virtual void		closeSocket();
};

#endif

#endif
