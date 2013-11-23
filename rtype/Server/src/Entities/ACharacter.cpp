//
// ACharacter.cpp for Acharac in /home/maitre_c/work/rtype/rtype
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Nov  5 10:14:28 2013 antoine maitre
// Last update Sat Nov 23 16:26:02 2013 antoine maitre
//

#include		<iostream>
#include		"Entities/ACharacter.hh"

ACharacter::ACharacter(int const x, int const y, std::string const &path, int const speed, bool const destructible)
  : AEntity(x, y, path, speed, destructible), _life(3), _timeInvincible(0)
{

}

ACharacter::~ACharacter()
{

}

void			ACharacter::setInvincible(int time)
{
  this->_timeInvincible = time;
}

int			ACharacter::getInvincible() const
{
  return (this->_timeInvincible);
}

