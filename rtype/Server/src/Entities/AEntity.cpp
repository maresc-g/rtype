//
// AEntity.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 13:57:28 2013 guillaume marescaux
// Last update Sun Nov 24 23:18:37 2013 laurent ansel
//

#include		<iostream>
#include		"Entities/AEntity.hh"

AEntity::AEntity()
{

}

AEntity::AEntity(int const x, int const y, std::string const &path,
		 int const speed, bool const destructible) :
  _moveX(0),
  _moveY(0),
  _pixelX(0),
  _pixelY(0),
  _coord(new Coordinate(x, y)),
  _path(path),
  _speed(speed),
  _destructible(destructible),
  _dead(false),
  _hitbox(new std::list<InformationHitBox *>),
  _spawnProjectile(new Coordinate(0, 0))
{
  static unsigned int	_idEntity = 0;

  _id = _idEntity++;
}

AEntity::AEntity(AEntity const &rhs)
{
  *this = rhs;
}

AEntity::~AEntity()
{
  delete _coord;
  delete _spawnProjectile;
  for (auto it = _hitbox->begin() ; it != _hitbox->end() ; ++it)
    if ((*it))
      delete *it;
  delete this->_hitbox;
}

AEntity			&AEntity::operator=(AEntity const &rhs)
{
  if (this != &rhs)
    {
      this->move(rhs.getCoord()->getX(), rhs.getCoord()->getY());
      this->setPath(rhs.getPath());
      this->setSpeed(rhs.getSpeed());
      this->setDestructible(rhs.getDestructible());
      if (this->_hitbox)
	{
	  for (auto it = this->_hitbox->begin() ; it != this->_hitbox->end() ; ++it)
	    delete *it;
	  delete this->_hitbox;
	}
      else
	this->_hitbox = new std::list<InformationHitBox *>;
      for (auto it = rhs.getInformationHitBox().begin() ; it != rhs.getInformationHitBox().end() ; ++it)
	this->_hitbox->push_back(new InformationHitBox(*(*it)));
      if (this->_spawnProjectile)
	delete this->_spawnProjectile;
      _spawnProjectile = new Coordinate(rhs.getSpawnProjectile());
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
  _moveX = x - this->getPosX() + this->_moveX;
  _moveY = y - this->getPosY() + this->_moveY;
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

int			AEntity::getHeight() const
{
  return (this->_height);
}

int			AEntity::getWidth() const
{
  return (this->_width);
}

std::list<InformationHitBox *> const	&AEntity::getInformationHitBox() const
{
  return (*this->_hitbox);
}

void			AEntity::setInformationHitBox(std::list<InformationHitBox *> *list)
{
  if (list)
    {
      if (!_hitbox)
	_hitbox = new std::list<InformationHitBox *>;
      _hitbox->clear();
      for (auto it = list->begin() ; it != list->end() ; ++it)
	if ((*it))
	  this->_hitbox->push_back(new InformationHitBox(*(*it)));
    }
  //  this->_hitbox = list;
}

void			AEntity::setId(unsigned int const id)
{
  this->_id = id;
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

unsigned int		AEntity::getLife() const
{
  return (this->_life);
}

void			AEntity::setLife(unsigned int const life)
{
  this->_life = life;
}

void			AEntity::setWidth(int const width)
{
  this->_width = width;
}

void			AEntity::setHeight(int const height)
{
  this->_height = height;
}

Coordinate const	&AEntity::getSpawnProjectile() const
{
  return (*this->_spawnProjectile);
}

void			AEntity::setSpawnProjectile(Coordinate *coord)
{
  if (coord)
    *this->_spawnProjectile = *coord;
}

AEntity::eObject	AEntity::getType() const
{
  return (AEntity::NOTHING);
}

int			AEntity::getPixelX() const
{
  return (this->_pixelX);
}

int			AEntity::getPixelY() const
{
  return (this->_pixelY);
}

int			AEntity::getPosX()
{
  return (this->_coord->getX() * 10 + this->_pixelX);
}

int			AEntity::getPosY()
{
  return (this->_coord->getY() * 10 + this->_pixelY);
}

bool			AEntity::moveToPixel()
{
  bool			ret = true;

  if (!this->_moveX && !this->_moveY)
    ret = false;
  else
    {
      if (this->_moveX)
	{
	  if (this->_moveX > 0)
	    {
	      this->_pixelX = this->_pixelX + this->_speed;
	      this->_moveX = this->_moveX - this->_speed;
	      if (this->_moveX < 0)
		this->_moveX = 0;
	    }
	  else
	    {
	      this->_pixelX = this->_pixelX - this->_speed;
	      this->_moveX = this->_moveX + this->_speed;
	      if (this->_moveX > 0)
		this->_moveX = 0;
	    }
	  this->_pixelX = this->_coord->getX() * 10 + this->_pixelX;
	  this->_coord->setX(this->_pixelX / 10);
	  this->_pixelX = this->_pixelX % 10;
	}
      if (this->_moveY)
	{
	  if (this->_moveY > 0)
	    {
	      this->_pixelY = this->_pixelY + this->_speed;
	      this->_moveY = this->_moveY - this->_speed;
	      if (this->_moveY < 0)
		this->_moveY = 0;
	    }
	  else
	    {
	      this->_pixelY = this->_pixelY - this->_speed;
	      this->_moveY = this->_moveY + this->_speed;
	      if (this->_moveY > 0)
		this->_moveY = 0;
	    }
	  this->_pixelY = this->_coord->getY() * 10 + this->_pixelY;
	  this->_coord->setY(this->_pixelY / 10);
	  this->_pixelY = this->_pixelY % 10;
	}
    }
  return (ret);
}

void			AEntity::movePos(int x, int y)
{
  this->_coord->setX(x / 10);
  this->_pixelX = x % 10;
  this->_coord->setY(y / 10);
  this->_pixelY = y % 10;
}

void			AEntity::resetMove()
{
  this->_moveX = 0;
  this->_moveY = 0;
}

void			AEntity::getProjectileVector(int &vx, int &vy) const
{
  vx = 30;
  vy = 0;
}
