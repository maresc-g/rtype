//
// main.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 12:58:03 2013 laurent ansel
// Last update Mon Oct 28 16:36:05 2013 laurent ansel
//

#include		"Thread/UnixThread.hh"

IMutex			*mutex = new UnixMutex;

void			*run(void *data)
{
  mutex->enter();
  int			*toto = reinterpret_cast<int *>(data);
  (*toto)--;
  std::cout << *toto << std::endl;
  mutex->leave();
  return (NULL);
}

int			main()
{
  int			titi = 10;
  IThread		*thread = new UnixThread;
  IThread		*thread2 = new UnixThread;

  mutex->initialize();
  thread->createThread(&run, &titi);
  thread2->createThread(&run, &titi);
  std::cout << "begin ..." << std::endl;
  thread->start();
  thread2->start();
  thread->waitThread();
  thread2->waitThread();
  std::cout << "end" << std::endl;
  return (0);
}
