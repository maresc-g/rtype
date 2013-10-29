//
// WindowsMutex.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 12:51:50 2013 laurent ansel
// Last update Mon Oct 28 16:36:37 2013 laurent ansel
//

#ifndef 			__WINDOWSMUTEX_HH__
# define 			__WINDOWSMUTEX_HH__

#ifdef				_WIN32

#include			<Windows.h>
#include			"Mutex/IMutex.hh"

class				WindowsMutex : public IMutex
{
private:
  CRITICAL_SECTION		_section;
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

