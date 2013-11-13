//
// ACharacter.cpp for Acharac in /home/maitre_c/work/rtype/rtype
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Nov  5 10:14:28 2013 antoine maitre
// Last update Tue Nov 12 15:39:24 2013 antoine maitre
//

#include		"Entities/ACharacter.hh"

ACharacter::ACharacter(int const x, int const y, std::string const &path, int const speed, bool const destructible)
  : AEntity(x, y, path, speed, destructible), _life(3)
{

}

ACharacter::~ACharacter()
{

}

void			ACharacter::collision()
{
  this->_life--;
  if (this->_life <= 0 && this->_destructible == true)
    this->_dead = true;
}
