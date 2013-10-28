//
// UnixMutex.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 13:00:53 2013 laurent ansel
// Last update Mon Oct 28 16:36:30 2013 laurent ansel
//

#ifndef 			__UNIXMUTEX_HH__
# define 			__UNIXMUTEX_HH__

#ifndef				_WIN32

#include			<pthread.h>
#include			"Mutex/IMutex.hh"

class				UnixMutex : public IMutex
{
protected:
  pthread_mutex_t		_mutex;
public:
  UnixMutex();
  virtual ~UnixMutex();
  virtual void			initialize();
  virtual void			destroy();
  virtual void			enter();
  virtual int			tryEnter();
  virtual void			leave();
};

#endif

#endif
