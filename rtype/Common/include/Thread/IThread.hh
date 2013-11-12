//
// IThread.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 12:53:00 2013 laurent ansel
// Last update Tue Nov 12 20:05:58 2013 alexis mestag
//

#ifndef 			__ITHREAD_HH__
# define 			__ITHREAD_HH__

#include			<iostream>

class				IThread
{
public:
  virtual ~IThread(){}
  virtual int			start() = 0;
  virtual int			createThread(void *(*func)(void*), void *) = 0;
  virtual void			destroyThread() = 0;
  virtual int			cancelThread() = 0;
  virtual int			waitThread() = 0;
};

#endif
