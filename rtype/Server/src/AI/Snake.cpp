//
// Snake.cpp for Snake in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Sat Nov 23 22:03:59 2013 alexis mestag
// Last update Sun Nov 24 21:30:31 2013 alexis mestag
//

#include			<math.h>
#include			"AI/Snake.hh"

static void				(Action::*setTab[2])(bool const) = {
  &Action::setUp,
  &Action::setDown
};

Snake::Snake() :
  Mob(0, 0, "Res/Sprites/mob1.png", 2), _loops(0), _set(setTab[0]), _willFire(rand() % 51)
{
  _name = "Snake";

  _v[0] = -30;
  _v[1] = 0;
}

Snake::~Snake()
{
}

Action const			*Snake::getAction()
{
  static int			ys[3] = {-30, 0, 30};

  _action->reset();
  _action->setLeft(true);
  if (_loops++ == 30)
    {
      this->_set = this->_set == setTab[0] ? setTab[1] : setTab[0];
      _loops = 0;
    }
  (_action->*this->_set)(true);
  if (_willFire++ == 50) {
    int				y = rand() % (sizeof(ys) / sizeof(*ys));

    _v[1] = ys[y];
    _action->setFire(true);
    _willFire = 0;
  }
  return (_action);
}

void				Snake::getProjectileVector(int &vx, int &vy) const
{
  vx = _v[0];
  vy = _v[1];
}
