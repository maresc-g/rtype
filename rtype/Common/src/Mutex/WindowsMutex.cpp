//
// WindowsMutex.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 12:57:22 2013 laurent ansel
// Last update Wed Nov  6 10:34:29 2013 laurent ansel
//

#ifdef _WIN32

#include		"Mutex/WindowsMutex.hh"

WindowsMutex::WindowsMutex()
{
}

WindowsMutex::~WindowsMutex()
{

}

void			WindowsMutex::initialize()
{
  this->_init = true;
  InitializeCriticalSection(&_section);
}

void			WindowsMutex::destroy()
{
  if (this->_init)
    DeleteCriticalSection(&_section);
}

void			WindowsMutex::enter()
{
  if (this->_init)
    EnterCriticalSection(&_section);
}

int			WindowsMutex::tryEnter()
{
  if (this->_init)
    return (TryEnterCriticalSection(&_section));
  return (-1);
}

void			WindowsMutex::leave()
{
  if (this->_init)
    LeaveCriticalSection(&_section);
}

#endif
