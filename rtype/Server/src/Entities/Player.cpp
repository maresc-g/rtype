//
// Player.cpp for Player in /home/maitre_c/work/rtype/rtype
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Nov  5 10:38:05 2013 antoine maitre
// Last update Mon Nov 18 10:35:03 2013 antoine maitre
//

#include "Entities/Player.hh"

Player::Player(int const x, int const y, std::string const &path, int const speed, bool const destructible)
  : ACharacter(x, y, path, speed, destructible)
{
  this->_weapon.setWeapon(AProjectile::ROCKET);
}

Player::~Player()
{

}

AEntity::eObject		Player::getType() const
{
  return (PLAYER);
}
