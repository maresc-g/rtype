//
// Donkey.cpp for Donkey in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype/Libraries
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Mon Nov 18 10:34:21 2013 alexis mestag
// Last update Sat Nov 23 11:20:17 2013 laurent ansel
//

#include			<time.h>
#include			"AI/Donkey.hh"

Donkey::Donkey() :
  Mob(0, 0, "Res/Sprites/mob1.png", 2)
{
}

Donkey::~Donkey()
{

}

Action const			*Donkey::getAction() const
{
  // static bool			start = true;
  // static double			duration = 0;
  // time_t			timer;
  // time_t			timerEnd;

  // if (start)
  //   {
  //     time(&timer);
  //     duration = 0;
  //     start = false;
  //   }
  // time(&timerEnd);
  _action->reset();
  _action->setLeft(true);
  // std::cout << "TIME = " << (double)timer << std::endl;
  // std::cout << "TIME = " << (double)timerEnd << std::endl;
  // duration += difftime(timerEnd, timer);
  // std::cout << "DURATION = " << duration << std::endl;
  // if (duration > 500000000)
  //   {
  //     //      _action->setFire(true);
  //     start = true;
  //   }
  return (_action);
}
