//
// ISocketClient.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 15:24:56 2013 laurent ansel
// Last update Mon Oct 28 15:51:10 2013 laurent ansel
//

#ifndef 			__ISOCKETCLIENT_HH__
# define 			__ISOCKETCLIENT_HH__

#include			<string>

#define	SIZE_BUFFER		4096

class				ISocketClient
{
public:
  virtual ~ISocketClient(){}
  virtual int			readSocket(std::string &, int const) = 0;
  virtual int			writeSocket(char *, int const) = 0;
  virtual void			closeSocket() = 0;
};

#endif
