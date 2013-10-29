//
// ISocket.hh for  in /home/ansel_l/Documents/Rtype/rtype
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 16:36:48 2013 laurent ansel
// Last update Mon Oct 28 16:37:33 2013 laurent ansel
//

#ifndef 			__ISOCKET_HH__
# define 			__ISOCKET_HH__

#include			<string>
#include			"Socket/ISocketClient.hh"

class				ISocket
{
public:
  virtual ~ISocket(){}
  virtual int			initialize(std::string const &) = 0;
  virtual int			destroy() = 0;
  virtual int			bindSocket(int const) = 0;
  virtual int			listenSocket() = 0;
  virtual ISocketClient		*connectToAddr(std::string const &, int const) = 0;
  virtual ISocketClient		*acceptConnection() = 0;
};

#endif
