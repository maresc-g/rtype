//
// AProjectile.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 14:49:34 2013 guillaume marescaux
// Last update Mon Nov 18 10:49:21 2013 antoine maitre
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
  double x1 = (_vx==0)?(0):(this->_speed / (_vx + _vy) * _vx);
  double y2 = (_vy==0)?(0):(this->_speed / (_vx + _vy) * _vy);

  AEntity::move(static_cast<int>(x1), static_cast<int>(y2));
}

AEntity::eObject		AProjectile::getType() const
{
  return (AEntity::PROJECTILE);
}
