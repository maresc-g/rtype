//
// Donkey.cpp for Donkey in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype/Libraries
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Mon Nov 18 10:34:21 2013 alexis mestag
// Last update Sat Nov 23 22:27:31 2013 alexis mestag
//

#include			"AI/Donkey.hh"

Donkey::Donkey() :
  Mob(0, 0, "Res/Sprites/mob1.png", 2), _willFire(rand() % 51)
{
  _v[0] = -30;
  _v[1] = 0;
}

Donkey::~Donkey()
{

}

Action const			*Donkey::getAction()
{
  static int			ys[3] = {-30, 0, 30};

  _action->reset();
  _action->setLeft(true);
  if (_willFire++ == 50) {
    int				y = rand() % 3;

    _v[1] = ys[y];
    _action->setFire(true);
    _willFire = 0;
  }
  return (_action);
}

void				Donkey::getProjectileVector(int &vx, int &vy) const
{
  vx = _v[0];
  vy = _v[1];
}
