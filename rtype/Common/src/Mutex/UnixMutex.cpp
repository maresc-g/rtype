//
// UnixMutex.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 13:04:52 2013 laurent ansel
// Last update Fri Nov  1 15:55:32 2013 laurent ansel
//

#ifndef			_WIN32

#include		"Mutex/UnixMutex.hh"

UnixMutex::UnixMutex()
{
}

UnixMutex::~UnixMutex()
{

}

void			UnixMutex::initialize()
{
  pthread_mutex_init(&this->_mutex, NULL);
}

void			UnixMutex::destroy()
{
  pthread_mutex_destroy(&this->_mutex);
}

void			UnixMutex::enter()
{
  pthread_mutex_lock(&this->_mutex);
}

int			UnixMutex::tryEnter()
{
  return (pthread_mutex_trylock(&this->_mutex));
}

void			UnixMutex::leave()
{
  pthread_mutex_unlock(&this->_mutex);
}

#endif
