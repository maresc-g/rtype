//
// ISocketClient.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 15:24:56 2013 laurent ansel
// Last update Thu Oct 31 13:16:11 2013 laurent ansel
//

#ifndef 			__ISOCKETCLIENT_HH__
# define 			__ISOCKETCLIENT_HH__

#include			<string>

#define	SIZE_BUFFER		4096

class				ISocketClient
{
public:
  virtual ~ISocketClient(){}
  virtual int			readSocket(char *buf, int const size) = 0;
  virtual int			writeSocket(char *buf, int const size) = 0;
  virtual void			closeSocket() const = 0;
  virtual int			getSocket() const = 0;
  virtual void			setAddr(struct sockaddr_in *addr) = 0;
};

#endif
