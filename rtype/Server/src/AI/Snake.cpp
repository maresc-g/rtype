//
// Snake.cpp for Snake in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Sat Nov 23 22:03:59 2013 alexis mestag
// Last update Sat Nov 23 22:27:23 2013 alexis mestag
//

#include			"AI/Snake.hh"

Snake::Snake() :
  Mob(0, 0, "Res/Sprites/mob1.png", 2)
{
  _v[0] = -30;
  _v[1] = 0;
}

Snake::~Snake()
{

}

Action const			*Snake::getAction()
{
  _action->reset();
  _action->setLeft(true);
  return (_action);
}

void				Snake::getProjectileVector(int &vx, int &vy) const
{
  vx = _v[0];
  vy = _v[1];
}
