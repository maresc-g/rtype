//
// Donkey.cpp for Donkey in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype/Libraries
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Mon Nov 18 10:34:21 2013 alexis mestag
// Last update Sat Nov 23 16:20:42 2013 alexis mestag
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
  static int			willFire = 0;


  _action->reset();
  _action->setLeft(true);
  if (willFire++ == 100) {
    _action->setFire(true);
    willFire = 0;
  }
  return (_action);
}
