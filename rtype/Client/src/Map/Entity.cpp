//
// Entity.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Nov  4 17:23:41 2013 guillaume marescaux
// Last update Thu Nov 21 13:04:03 2013 guillaume marescaux
//

#include			"Map/Entity.hh"

//----------------------------------BEGIN CTOR / DTOR---------------------------------------

Entity::Entity(int const id, int const x, int const y, std::string const &type, std::string const &direction):
  _id(id), _x(x), _y(y), _type(type), _direction(direction)
{
}

Entity::Entity(Entity const &other):
  _id(other._id), _x(other._x), _y(other._y), _type(other._type), _direction(other._direction)
{
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
    }
  return (*this);
}

Entity::~Entity() {}

//-----------------------------------END CTOR / DTOR----------------------------------------

//-------------------------------BEGIN GETTERS / SETTERS------------------------------------

int				Entity::getId(void) const { return (_id); }
int				Entity::getX(void) const { return (_x); }
int				Entity::getY(void) const { return (_y); }
std::string const		&Entity::getType(void) const { return (_type); }
std::string const		&Entity::getDirection(void) const { return (_direction); }
void				Entity::setId(int const id) { _id = id; }
void				Entity::setX(int const x) { _x = x; }
void				Entity::setY(int const y) { _y = y; }
void				Entity::setType(std::string const &type) { _type = type; }
void				Entity::setDirection(std::string const &direction) { _direction = direction; }

//--------------------------------END GETTERS / SETTERS-------------------------------------

