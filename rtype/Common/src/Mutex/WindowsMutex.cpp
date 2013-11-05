//
// WindowsMutex.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 12:57:22 2013 laurent ansel
// Last update Mon Oct 28 16:38:55 2013 laurent ansel
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
  InitializeCriticalSection(&_section);
}

void			WindowsMutex::destroy()
{
  DeleteCriticalSection(&_section);
}

void			WindowsMutex::enter()
{
  EnterCriticalSection(&_section);
}

int			WindowsMutex::tryEnter()
{
  return (TryEnterCriticalSection(&_section));
}

void			WindowsMutex::leave()
{
  LeaveCriticalSection(&_section);
}

#endif
