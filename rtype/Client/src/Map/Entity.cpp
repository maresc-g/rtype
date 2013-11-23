//
// Entity.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Nov  4 17:23:41 2013 guillaume marescaux
// Last update Sat Nov 23 21:27:38 2013 guillaume marescaux
//

#include <iostream>
#include			"Map/Entity.hh"

//----------------------------------BEGIN CTOR / DTOR---------------------------------------

Entity::Entity(int const id, int const x, int const y, std::string const &type, std::string const &direction, bool const invincible):
  _id(id), _x(x), _y(y), _type(type), _direction(direction), _invincible(invincible), _clock(new sf::Clock), _time(0)
{
}

Entity::Entity(Entity const &other):
  _clock(NULL)
{
  *this = other;
}

Entity				&Entity::operator=(Entity const &other)
{
  if (this != &other)
    {
      _id = other._id;
      _x = other._x;
      _y = other._y;
      _type = other._type;
      _direction = other._direction;
      _invincible = other._invincible;
      if (_clock)
	delete _clock;
      _clock = new sf::Clock;
      _time = other._time;
    }
  return (*this);
}

Entity::~Entity()
{
  delete _clock;
}

//-----------------------------------END CTOR / DTOR----------------------------------------

//-------------------------------BEGIN GETTERS / SETTERS------------------------------------

int				Entity::getId(void) const { return (_id); }
int				Entity::getX(void) const { return (_x); }
int				Entity::getY(void) const { return (_y); }
std::string const		&Entity::getType(void) const { return (_type); }
std::string const		&Entity::getDirection(void) const { return (_direction); }
bool				Entity::getInvincible(void) const { return (_invincible); }
sf::Clock const			&Entity::getClock(void) const { return (*_clock); }
float				Entity::getTime(void) const { return (_time); }
void				Entity::setId(int const id) { _id = id; }
void				Entity::setX(int const x) { _x = x; }
void				Entity::setY(int const y) { _y = y; }
void				Entity::setType(std::string const &type) { _type = type; }
void				Entity::setDirection(std::string const &direction) { _direction = direction; }
void				Entity::setInvincible(bool const invincible)
{
  if (invincible)
    _clock->restart();
  _invincible = invincible;
}
void				Entity::setTime(float const time) { _time = time; }

//--------------------------------END GETTERS / SETTERS-------------------------------------

