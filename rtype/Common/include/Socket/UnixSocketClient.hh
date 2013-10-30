//
// UnixSocketClient.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 15:22:40 2013 laurent ansel
// Last update Mon Oct 28 16:37:42 2013 laurent ansel
//

#ifndef 			__UNIXSOCKETCLIENT_HH__
# define 			__UNIXSOCKETCLIENT_HH__

#ifndef _WIN32

#include			<unistd.h>
#include			<sys/types.h>
#include			<sys/types.h>
#include			<netdb.h>
#include			<sys/types.h>
#include			<netinet/in.h>
#include			<arpa/inet.h>
#include			"Socket/ISocketClient.hh"

class				UnixSocketClient : public ISocketClient
{
private:
  int				_socket;
public:
  UnixSocketClient(int const);
  virtual ~UnixSocketClient();
  virtual int			readSocket(std::string &, int const);
  virtual int			writeSocket(char *, int const);
  virtual void			closeSocket();
};

#endif

#endif
