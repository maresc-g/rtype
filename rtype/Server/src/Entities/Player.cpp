//
// Player.cpp for Player in /home/maitre_c/work/rtype/rtype
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Nov  5 10:38:05 2013 antoine maitre
// Last update Thu Nov 21 10:33:30 2013 laurent ansel
//

#include "Entities/Player.hh"

Player::Player(int const x, int const y, std::string const &path, int const speed, bool const destructible)
  : ACharacter(x, y, path, speed, destructible),
    _numPlayer(0)
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

void				Player::setNum(int const num)
{
  this->_numPlayer = num;
}

int				Player::getNum() const
{
  return (this->_numPlayer);
}
