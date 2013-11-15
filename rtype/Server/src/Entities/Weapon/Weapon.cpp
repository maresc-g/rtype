//
// Weapon.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 14:48:52 2013 guillaume marescaux
// Last update Fri Nov 15 14:31:42 2013 antoine maitre
//

#include		"Entities/Weapon/Weapon.hh"

Weapon::Weapon(AProjectile *weapon)
  : _currentWeapon(weapon)
{

}

Weapon::~Weapon()
{

}

AProjectile		*Weapon::getWeapon() const
{
  return (this->_currentWeapon);
}

void			Weapon::setWeapon(AProjectile *weapon)
{
  this->_currentWeapon = weapon;
}
