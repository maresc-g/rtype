//
// Mob.cpp for mob in /home/maitre_c/work/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Wed Oct 30 11:19:56 2013 antoine maitre
// Last update Mon Nov 18 22:20:35 2013 laurent ansel
//

#include "Entities/Mob.hh"

Mob::Mob(int const x, int const y, std::string const &path, int const speed)
  : ACharacter(x, y, path, speed, true), _action(new Action)
{
  this->_weapon.setWeapon(AProjectile::ROCKET);
}

Mob::~Mob()
{
  delete _action;
}

AEntity::eObject		Mob::getType() const
{
  return (AEntity::MOB);
}

Action const			*Mob::getAction() const
{
  _action->reset();
  return (_action);
}
