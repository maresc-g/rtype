//
// Rocket.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 14:46:36 2013 guillaume marescaux
// Last update Mon Nov 18 10:43:46 2013 antoine maitre
//

#ifndef 		__ROCKET_HH__
# define 		__ROCKET_HH__

#include		"AProjectile.hh"

class			Rocket : public AProjectile
{
public:
  Rocket(int const x, int const y, std::string const &path, int const speed, bool const destructible, int const vx, int const vy);
  virtual ~Rocket();
};

#endif
