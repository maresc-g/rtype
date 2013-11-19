//
// MutexVar.hpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Thu Nov 14 18:56:32 2013 guillaume marescaux
// Last update Tue Nov 19 13:02:26 2013 laurent ansel
//

#ifndef 		__MUTEXVAR_HPP__
# define 		__MUTEXVAR_HPP__

#include		"Mutex/Mutex.hpp"

template<class T>
class			MutexVar
{
private:

  // Attributes
  Mutex			*_mutex;
  T			_var;

public:
  MutexVar(T var):
    _mutex(new Mutex), _var(var)
  {
    _mutex->initialize();
  }

  virtual ~MutexVar()
  {
    _mutex->destroy();
    delete _mutex;
  }

  void			setVar(T var)
  {
    _mutex->enter();
    _var = var;
    _mutex->leave();
  }

  T			getVar(void) const
  {
    T			tmp;

    _mutex->enter();
    tmp = _var;
    _mutex->leave();
    return (tmp);
  }
};

#endif
