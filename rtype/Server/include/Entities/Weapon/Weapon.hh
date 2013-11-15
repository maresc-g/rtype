//
// Weapon.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 14:44:11 2013 guillaume marescaux
// Last update Fri Nov 15 14:30:51 2013 antoine maitre
//

#ifndef 		__WEAPON_HH__
# define 		__WEAPON_HH__

#include		"AProjectile.hh"

class			Weapon
{
  AProjectile		*_currentWeapon;
public:
  Weapon(AProjectile *weapon=NULL);
  ~Weapon();
  AProjectile		*getWeapon() const;
  void			setWeapon(AProjectile *);
};

#endif
