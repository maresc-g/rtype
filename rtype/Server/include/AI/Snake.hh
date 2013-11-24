//
// Snake.hh for Snake in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Sat Nov 23 22:01:15 2013 alexis mestag
// Last update Sun Nov 24 21:26:40 2013 alexis mestag
//

#ifndef			__SNAKE_HH__
# define		__SNAKE_HH__

#include		"Action/Action.hh"
#include		"Entities/Mob.hh"

class			Snake : public Mob
{
private:
  int			_loops;
  void			(Action::*_set)(bool const);
  int			_willFire;
  int			_v[2];

public:
  Snake();
  virtual ~Snake();
  virtual Action const	*getAction();
  virtual void		getProjectileVector(int &, int &) const;
};

extern "C"
{
  #ifdef	_WIN32
  __declspec(dllexport)
  #endif
  Snake			*getInstance() {
    return (new Snake);
  }

  #ifdef	_WIN32
  __declspec(dllexport)
  #endif
  void			deleteInstance(void *snake) {
    Snake		*s;

    s = reinterpret_cast<Snake *>(snake);
    delete s;
  }
}

#endif
