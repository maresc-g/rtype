//
// AProjectile.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 14:49:34 2013 guillaume marescaux
// Last update Sat Nov 23 21:16:06 2013 alexis mestag
//

#include			<math.h>
#include			<sstream>
#include			<iostream>
#include			"Entities/Weapon/AProjectile.hh"

static double			getVectorNorm(double const vx, double const vy)
{
  double			norm;

  norm = sqrt(pow(vx, 2) + pow(vy, 2));
  return (norm);
}

AProjectile::AProjectile(int const x, int const y, std::string const &path, int const speed, bool const destructible, int const vx, int const vy)
  : AEntity(x, y, path, speed, destructible), _vx(vx), _vy(vy)
{

}

AProjectile::~AProjectile()
{

}

void				AProjectile::move()
{
  double x1 = (_vx==0) ? (0) :(_vx / this->_speed);
  double y2 = (_vy==0) ? (0) :(_vy / this->_speed);

  AEntity::move(static_cast<int>(this->getPosX() + x1), static_cast<int>(this->getPosY() + y2));
}

void				AProjectile::setVector(int const vx, int const vy)
{
  static double const	origX = 1;
  static double const	origY = 0;
  Coordinate const	*itC;
  Coordinate		toCalc(0, 0);
  double		scal;
  double		cosinus;
  double		sinus;
  
  _vx = vx;
  _vy = vy;
  scal = static_cast<double>(vx) * origX + static_cast<double>(vy) * origY;
  cosinus = scal / (getVectorNorm(vx, vy) * getVectorNorm(origX, origY));
  sinus = sqrt(1.0 - pow(cosinus, 2)) * (vy > 0 ? -1 : 1);
  // std::cout << "Scal = " << scal << " => " << "(" << cosinus << ", " << sinus << ")" << std::endl;
  if (_hitbox)
    for (auto it = this->_hitbox->begin() ; it != this->_hitbox->end() ; ++it)
      {
	itC = &(*it)->getOrigCoordinate();
	toCalc.setX(itC->getX() * cosinus + itC->getY() * sinus);
	toCalc.setY(-itC->getX() * sinus + itC->getY() * cosinus);
	(*it)->setCoordinate(toCalc);
      }
}

AEntity::eObject		AProjectile::getType() const
{
  return (AEntity::PROJECTILE);
}

AProjectile::operator		std::string() const
{
  Coordinate const		*itC;
  std::ostringstream		stream;

  stream << "Entity " << "" << std::endl;
  for (auto it = _hitbox->cbegin() ; it != _hitbox->cend() ; ++it)
    {
      itC = &(*it)->getCoordinate();
      stream << "\t - (" << itC->getX() << ", " << itC->getY() << ")" << std::endl;
    }
  return (stream.str());
}
