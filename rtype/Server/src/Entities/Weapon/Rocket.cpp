//
// Rocket.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 14:50:16 2013 guillaume marescaux
// Last update Sun Nov 24 00:50:10 2013 antoine maitre
//

#include			"Entities/Weapon/Rocket.hh"

Rocket::Rocket(int const x, int const y, std::string const &path, int const speed, bool const destructible, int const vx, int const vy)
  : AProjectile(x, y, path, speed, destructible, 30, 0), _daddy(NULL)
{
  (void)vx;
  (void)vy;
}

Rocket::~Rocket()
{

}

AEntity::eObject	Rocket::getType() const
{
  return (AEntity::ROCKET);
}

void			Rocket::collision()
{
  AEntity::collision();
  if (this->_daddy)
    this->_daddy->setScore(this->_daddy->getScore() + 10);
}

void			Rocket::whoIsMyDaddy(Player *bigDaddy)
{
  this->_daddy = bigDaddy;
}
