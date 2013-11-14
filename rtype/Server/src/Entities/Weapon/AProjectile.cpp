//
// AProjectile.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 14:49:34 2013 guillaume marescaux
// Last update Thu Nov 14 11:34:31 2013 antoine maitre
//

#include			"Entities/Weapon/AProjectile.hh"

AProjectile::AProjectile(int const x, int const y, std::string const &path, int const speed, bool const destructible, int const vx, int const vy)
  : AEntity(x, y, path, speed, destructible), _vx(vx), _vy(vy)
{
  
}

AProjectile::~AProjectile()
{

}

void				AProjectile::move()
{
  AEntity::move(this->_coord->getX() + _vx, this->_coord->getY() + _vy);
}
