//
// PthreadCondition.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 14:19:41 2013 laurent ansel
// Last update Wed Nov  6 10:42:08 2013 laurent ansel
//

#include			"Thread/PthreadCondition.hh"

PthreadCondition::PthreadCondition():
  _init(false)
{
}

PthreadCondition::~PthreadCondition()
{
}

int				PthreadCondition::initializeCond()
{
  this->_init = true;
  this->initialize();
  return (pthread_cond_init(&this->_cond, NULL));
}

int				PthreadCondition::destroyCond()
{
  if (this->_init)
    {
      this->destroy();
      return (pthread_cond_destroy(&this->_cond));
    }
  return (-1);
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
