//
// UnixThread.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 13:22:02 2013 laurent ansel
// Last update Tue Nov 12 20:06:11 2013 alexis mestag
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
  bool				_start;
public:
  UnixThread();
  virtual ~UnixThread();
  virtual int			start();
  virtual int			createThread(void *(*func)(void*), void *);
  virtual void			destroyThread();
  virtual int			cancelThread();
  virtual int			waitThread();
  PthreadCondition		*getCond();
  CallBack			getFunc();
  void				*getData();
  bool				getStart() const;
};

#endif

#endif
