//
// Server.hh for  in /home/ansel_l/Documents/Rtype/work/Server/include
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 20:01:50 2013 laurent ansel
// Last update Tue Oct 29 15:08:10 2013 laurent ansel
//

#ifndef 			__SERVER_HH__
# define 			__SERVER_HH__

#include			"Socket/Socket.hpp"
#include			"Mutex/Mutex.hpp"
#include			"Thread/Thread.hpp"
#include			"Select/Select.hh"

class				Server
{
private:
  Select			*_select;
public:
  Server();
  virtual ~Server();
  void				run();
};

#endif
