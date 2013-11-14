//
// ACharacter.cpp for Acharac in /home/maitre_c/work/rtype/rtype
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Nov  5 10:14:28 2013 antoine maitre
// Last update Thu Nov 14 12:56:21 2013 arthur rucquois
//

#include		"Entities/ACharacter.hh"

ACharacter::ACharacter(int const x, int const y, std::string const &path, int const speed, bool const destructible)
  : AEntity(x, y, path, speed, destructible), _life(3)
{

}

ACharacter::~ACharacter():
  _offFrames(0)
{
}

void			ACharacter::collision()
{
  if (this->_offFrames <= 0)
    {
      this->_life--;
      if (this->_life <= 0 && this->_destructible == true)
	this->_dead = true;
      else
	this->_offFrames = 20;
    }
}

void			ACharacter::decOffFrames()
{
  if (this->_offFrames > 0)
    this->_offFrames--;
}
