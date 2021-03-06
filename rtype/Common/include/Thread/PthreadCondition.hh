//
// PthreadCondition.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 14:15:23 2013 laurent ansel
// Last update Wed Nov  6 10:41:44 2013 laurent ansel
//

#ifndef 			__PTHREADCONDITION_HH__
# define 			__PTHREADCONDITION_HH__

#ifndef _WIN32

#include			<pthread.h>
#include			"Mutex/UnixMutex.hh"

class				PthreadCondition : protected UnixMutex
{
private:
  pthread_cond_t		_cond;
  bool				_init;
public:
  PthreadCondition();
  virtual ~PthreadCondition();
  int				initializeCond();
  int				destroyCond();
  int				wakeUp();
  int				wakeUpAll();
  int				waitEvent();
};

#endif

#endif