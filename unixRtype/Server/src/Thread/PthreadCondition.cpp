//
// PthreadCondition.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 14:19:41 2013 laurent ansel
// Last update Mon Oct 28 16:40:08 2013 laurent ansel
//

#include			"Thread/PthreadCondition.hh"

PthreadCondition::PthreadCondition()
{
}

PthreadCondition::~PthreadCondition()
{
}

int				PthreadCondition::initializeCond()
{
  return (pthread_cond_init(&this->_cond, NULL));
}

int				PthreadCondition::destroyCond()
{
  return (pthread_cond_destroy(&this->_cond));
}

int				PthreadCondition::wakeUp()
{
  return (pthread_cond_signal(&this->_cond));
}

int				PthreadCondition::wakeUpAll()
{
  return (pthread_cond_broadcast(&this->_cond));
}

int				PthreadCondition::waitEvent()
{
  return (pthread_cond_wait(&this->_cond, &this->_mutex));
}
