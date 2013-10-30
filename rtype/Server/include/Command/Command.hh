//
// Command.hh for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 15:58:12 2013 laurent ansel
// Last update Tue Oct 29 16:03:04 2013 laurent ansel
//

#ifndef 			__COMMAND_HH__
# define 			__COMMAND_HH__

#include			"CircularBufferManager/CircularBufferManager.hh"

class				Command
{
private:
  Trame				*_trame;
public:
  Command(Trame *trame);
  virtual ~Command();
};

#endif
