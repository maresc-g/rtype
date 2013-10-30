//
// UnixSocketClient.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 15:22:40 2013 laurent ansel
// Last update Wed Oct 30 11:40:18 2013 laurent ansel
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
  std::string			_proto;
public:
  UnixSocketClient(int const fd, std::string const &protocole);
  virtual ~UnixSocketClient();
  virtual int			readSocket(std::string &data, int const size);
  virtual int			writeSocket(char *data, int const size);
  virtual void			closeSocket();
};

#endif

#endif
