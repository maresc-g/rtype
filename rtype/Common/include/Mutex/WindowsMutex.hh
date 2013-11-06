//
// WindowsMutex.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 12:51:50 2013 laurent ansel
// Last update Wed Nov  6 10:34:40 2013 laurent ansel
//

#ifndef 			__WINDOWSMUTEX_HH__
# define 			__WINDOWSMUTEX_HH__

#ifdef				_WIN32

#define _WINSOCKAPI_ 
#include			<Windows.h>
#include			"Mutex/IMutex.hh"

class				WindowsMutex : public IMutex
{
private:
  CRITICAL_SECTION		_section;
  bool				_init;
public:
  WindowsMutex();
  virtual ~WindowsMutex();
  virtual void			initialize();
  virtual void			destroy();
  virtual void			enter();
  virtual int			tryEnter();
  virtual void			leave();
};

#endif

#endif

