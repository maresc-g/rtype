//
// Inotify.hpp for  in /home/ansel_l/testInotify/include/Inotify
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Sat Nov  9 17:48:58 2013 laurent ansel
// Last update Sat Nov  9 18:37:21 2013 laurent ansel
//

#ifndef 			__INOTIFY_HPP__
# define 			__INOTIFY_HPP__

#ifndef	_WIN32
#include			"Inotify/UnixInotify.hh"
#else
#include			"Inotify/WindowsInotify.hh"
#endif

class				UnixInotify;
class				IInotify;

#ifndef	_WIN32
class				Inotify : public UnixInotify
#else
class				Inotify : public WindowsInotify
#endif
{
public:
  Inotify():
#ifdef	_WIN32
    WindowsInotify()
#else
    UnixInotify()
#endif
  {}
  virtual ~Inotify()
  {}


};

#endif
