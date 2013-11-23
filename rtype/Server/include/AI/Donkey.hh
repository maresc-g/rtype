//
// Donkey.hh for Donkey in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype/Libraries
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Mon Nov 18 10:33:23 2013 alexis mestag
// Last update Sat Nov 23 18:59:43 2013 alexis mestag
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
  virtual void		getProjectileVector(int &, int &) const;
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
