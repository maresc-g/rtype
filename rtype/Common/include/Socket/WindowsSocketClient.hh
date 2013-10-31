//
// WindowsSocketClient.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 15:22:49 2013 laurent ansel
// Last update Thu Oct 31 10:39:38 2013 laurent ansel
//

#ifndef			__WINDOWSSOCKETCLIENT_HH__
# define		__WINDOWSSOCKETCLIENT_HH__

#ifdef _WIN32

#include		<WinSock2.h>
#include		"Socket/ISocketClient.hh"

#pragma comment(lib, "ws2_32.lib")

class			WindowsSocketClient : public ISocketClient
{
private:
  SOCKET		_socket;
  std::string		_proto;
public:
  WindowsSocketClient(SOCKET const fd, std::string const &protocole);
  virtual ~WindowsSocketClient();
  virtual int		readSocket(std::string &data, int const size);
  virtual int		writeSocket(char *data, int const size);
  virtual void		closeSocket() const;
  virtual int		getSocket() const;
};

#endif

#endif
