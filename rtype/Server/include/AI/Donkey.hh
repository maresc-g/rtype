//
// Donkey.hh for Donkey in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype/Libraries
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Mon Nov 18 10:33:23 2013 alexis mestag
// Last update Mon Nov 18 13:16:28 2013 alexis mestag
//

#ifndef			__DONKEY_HH__
# define		__DONKEY_HH__

#include		"Action/Action.hh"
#include		"Entities/Mob.hh"

class			Donkey : public Mob
{
public:
  Donkey();
  virtual ~Donkey();
  virtual Action const	*getAction() const;
};

extern "C"
{
  #ifdef	_WIN32
  __declspec( dllexport )
  #endif
  Donkey		*getInstance() {
    return (new Donkey);
  }
}

#endif
