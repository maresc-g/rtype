//
// AEntity.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 13:57:28 2013 guillaume marescaux
// Last update Wed Oct 30 12:39:55 2013 antoine maitre
//

#include		"Entities/AEntity.hh"

AEntity::AEntity()
{

}

AEntity::AEntity(int const x, int const y, std::string const &path,
		 int const speed, bool const destructible) :
  _coord(new Coordinate(x, y)), _path(path),
  _speed(speed), _destructible(destructible)
{

}

AEntity::AEntity(AEntity const &rhs)
{
  *this = rhs;
}

AEntity::~AEntity()
{
  delete _coord;
}

AEntity			&AEntity::operator=(AEntity const &rhs)
{
  if (this != &rhs)
    {
      this->move(rhs.getCoord()->getX(), rhs.getCoord()->getY());
      this->setPath(rhs.getPath());
      this->setSpeed(rhs.getSpeed());
      this->setDestructible(rhs.getDestructible());
    }
  return (*this);
}

bool			AEntity::checkCollision(AEntity const &) const
{
  return (false);
}

void			AEntity::move(int const x, int const y)
{
  _coord->setX(x);
  _coord->setY(y);
}

Coordinate const	*AEntity::getCoord() const
{
  return (_coord);
}

std::string const	&AEntity::getPath() const
{
  return (_path);
}

void			AEntity::setPath(std::string const &path)
{
  _path = path;
}

int			AEntity::getSpeed() const
{
  return (_speed);
}

void			AEntity::setSpeed(int const speed)
{
  _speed = speed;
}

bool			AEntity::getDestructible() const
{
  return (_destructible);
}

void			AEntity::setDestructible(bool const &destructible)
{
  _destructible = destructible;
}

int			AEntity::getLargeur() const
{
  return (this->_L);
}

int			AEntity::getLongueur() const
{
  return (this->_l);
}
