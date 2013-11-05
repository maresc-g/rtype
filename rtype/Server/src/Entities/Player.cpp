//
// Player.cpp for Player in /home/maitre_c/work/rtype/rtype
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Nov  5 10:38:05 2013 antoine maitre
// Last update Tue Nov  5 10:56:57 2013 antoine maitre
//

#include "Entities/Player.hh"

Player::Player(int const x, int const y, std::string const &path, int const speed, bool const destructible)
  : ACharacter(x, y, path, speed, destructible)
{

}

Player::~Player()
{

}

eObject		Player::getType() const
{
  return (PLAYER);
}
