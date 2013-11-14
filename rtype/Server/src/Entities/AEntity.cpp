//
// AEntity.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 13:57:28 2013 guillaume marescaux
// Last update Wed Nov 13 12:49:43 2013 antoine maitre
//

#include		"Entities/AEntity.hh"

static unsigned int	id = 0;

AEntity::AEntity()
{

}

AEntity::AEntity(int const x, int const y, std::string const &path,
		 int const speed, bool const destructible) :
  _id(id++), _coord(new Coordinate(x, y)), _path(path),
  _speed(speed), _destructible(destructible), _dead(false)
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

void			AEntity::collision()
{
  if (this->_destructible == true)
    this->_dead = true;
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

unsigned int		AEntity::getId() const
{
  return (this->_id);
}

bool			AEntity::isDead() const
{
  return (this->_dead);
}

void			AEntity::setDead(bool dead)
{
  this->_dead = dead;
}
