//
// Weapon.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 14:44:11 2013 guillaume marescaux
// Last update Mon Nov 18 10:33:31 2013 antoine maitre
//

#ifndef 		__WEAPON_HH__
# define 		__WEAPON_HH__

#include		"AProjectile.hh"

class			Weapon
{
  AProjectile::eProjec	_currentWeapon;
public:
  Weapon();
  ~Weapon();
  AProjectile::eProjec	getWeapon() const;
  void			setWeapon(AProjectile::eProjec _weapon);
};

#endif
