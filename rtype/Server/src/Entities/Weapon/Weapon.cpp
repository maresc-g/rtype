//
// Weapon.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 14:48:52 2013 guillaume marescaux
// Last update Mon Nov 18 14:18:34 2013 antoine maitre
//

#include		"Entities/Weapon/Weapon.hh"

Weapon::Weapon()
{

}

Weapon::~Weapon()
{

}

AProjectile::eProjec	Weapon::getWeapon() const
{
  return (this->_currentWeapon);
}

void			Weapon::setWeapon(AProjectile::eProjec weapon)
{
  this->_currentWeapon = weapon;
}
