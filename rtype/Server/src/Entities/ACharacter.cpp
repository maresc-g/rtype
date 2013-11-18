//
// ACharacter.cpp for Acharac in /home/maitre_c/work/rtype/rtype
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Nov  5 10:14:28 2013 antoine maitre
// Last update Mon Nov 18 14:53:11 2013 antoine maitre
//

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

void			ACharacter::collision()
{
  if (this->_timeInvincible == 0)
    {
      this->_life--;
      this->_timeInvincible = 40;
      if (this->_life <= 0 && this->_destructible == true)
	this->_dead = true;
    }
}
