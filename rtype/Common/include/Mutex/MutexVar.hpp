//
// MutexVar.hpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Thu Nov 14 18:56:32 2013 guillaume marescaux
// Last update Fri Nov 15 14:15:06 2013 guillaume marescaux
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
  {}

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
