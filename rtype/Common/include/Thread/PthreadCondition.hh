//
// PthreadCondition.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 14:15:23 2013 laurent ansel
// Last update Mon Oct 28 16:38:17 2013 laurent ansel
//

#ifndef 			__PTHREADCONDITION_HH__
# define 			__PTHREADCONDITION_HH__

#include			<pthread.h>
#include			"Mutex/UnixMutex.hh"

class				PthreadCondition : protected UnixMutex
{
private:
  pthread_cond_t		_cond;
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
