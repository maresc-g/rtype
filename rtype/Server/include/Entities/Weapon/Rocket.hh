//
// Rocket.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 14:46:36 2013 guillaume marescaux
// Last update Sat Nov 23 23:13:31 2013 antoine maitre
//

#ifndef 		__ROCKET_HH__
# define 		__ROCKET_HH__

#include		"Entities/Player.hh"
#include		"AProjectile.hh"

class			Rocket : public AProjectile
{
  Player		*_daddy;
public:
  Rocket(int const x, int const y, std::string const &path, int const speed, bool const destructible, int const vx, int const vy);
  virtual ~Rocket();
  AEntity::eObject	getType() const;
  virtual void		collision();
  void			whoIsMyDaddy(Player *);
};

#endif
