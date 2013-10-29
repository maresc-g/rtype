//
// IMutex.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 12:50:57 2013 laurent ansel
// Last update Thu Oct 24 13:13:00 2013 laurent ansel
//

#ifndef 			__IMUTEX_HH__
# define 			__IMUTEX_HH__

#include			<iostream>

class				IMutex
{
public:
  virtual ~IMutex(){}
  virtual void			initialize() = 0;
  virtual void			destroy() = 0;
  virtual void			enter() = 0;
  virtual int			tryEnter() = 0;
  virtual void			leave() = 0;
};

#endif
