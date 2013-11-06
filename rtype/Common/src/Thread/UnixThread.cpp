//
// UnixThread.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 13:25:46 2013 laurent ansel
// Last update Wed Nov  6 10:43:30 2013 laurent ansel
//

#ifndef			_WIN32

#include		"Thread/UnixThread.hh"

UnixThread::UnixThread():
  _cond(new PthreadCondition), _func(NULL), _start(false)
{

}

UnixThread::~UnixThread()
{
  if (this->_cond)
    {
      this->_cond->destroyCond();
      delete this->_cond;
    }
}

bool			UnixThread::getStart() const
{
  return (this->_start);
}

int			UnixThread::start()
{
  this->_start = true;
  return (this->_cond->wakeUp());
}

static void		*tmpThread(void *data)
{
  UnixThread		*thread = reinterpret_cast<UnixThread *>(data);

  if (thread->getCond())
    {
      while (!thread->getStart())
	thread->getCond()->waitEvent();
      return (thread->getFunc()(thread->getData()));
    }
  return (NULL);
}

int			UnixThread::createThread(void *(*func)(void *), void *data)
{
  this->_func = func;
  this->_data = data;
  this->_cond->initializeCond();
  return (pthread_create(&this->_thread, NULL, &tmpThread, this));
}

void			UnixThread::destroyThread()
{
  pthread_exit(&this->_thread);
}

int			UnixThread::waitThread()
{
  return (pthread_join(this->_thread, NULL));
}

PthreadCondition	*UnixThread::getCond()
{
  return (this->_cond);
}

CallBack		UnixThread::getFunc()
{
  return (this->_func);
}

void			*UnixThread::getData()
{
  return (this->_data);
}

#endif
