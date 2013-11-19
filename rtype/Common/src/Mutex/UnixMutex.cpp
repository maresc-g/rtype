//
// UnixMutex.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 13:04:52 2013 laurent ansel
// Last update Tue Nov 19 12:55:35 2013 laurent ansel
//

#ifndef			_WIN32

#include		"Mutex/UnixMutex.hh"

UnixMutex::UnixMutex():
  _init(false)
{
}

UnixMutex::~UnixMutex()
{

}

void			UnixMutex::initialize()
{
  this->_init = true;
  pthread_mutex_init(&this->_mutex, NULL);
}

void			UnixMutex::destroy()
{
  if (this->_init)
    pthread_mutex_destroy(&this->_mutex);
}

void			UnixMutex::enter()
{
  if (this->_init)
    pthread_mutex_lock(&this->_mutex);
}

int			UnixMutex::tryEnter()
{
  if (this->_init)
    return (pthread_mutex_trylock(&this->_mutex));
  return (-1);
}

void			UnixMutex::leave()
{
  if (this->_init)
    pthread_mutex_unlock(&this->_mutex);
}

#endif
