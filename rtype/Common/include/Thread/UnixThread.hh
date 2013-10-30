//
// UnixThread.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 13:22:02 2013 laurent ansel
// Last update Mon Oct 28 16:38:27 2013 laurent ansel
//

#ifndef 			__UNIXTHREAD_HH__
# define 			__UNIXTHREAD_HH__

#ifndef				_WIN32

#include			<pthread.h>
#include			"Thread/IThread.hh"
#include			"Thread/PthreadCondition.hh"

typedef void *(*CallBack)(void *);

class				UnixThread : public IThread
{
private:
  pthread_t			_thread;
  PthreadCondition		*_cond;
  void				*(*_func)(void *);
  void				*_data;
public:
  UnixThread();
  virtual ~UnixThread();
  virtual int			start();
  virtual int			createThread(void *(*func)(void*), void *);
  virtual void			destroyThread();
  virtual int			waitThread();
  PthreadCondition		*getCond();
  CallBack			getFunc();
  void				*getData();

};

#endif

#endif
