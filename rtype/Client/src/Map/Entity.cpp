//
// Entity.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Nov  4 17:23:41 2013 guillaume marescaux
// Last update Mon Nov 11 15:19:14 2013 guillaume marescaux
//

#include			"Map/Entity.hh"

//----------------------------------BEGIN CTOR / DTOR---------------------------------------

Entity::Entity(int const id, int const x, int const y, eEntity const type, eDirection direction):
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
Entity::eEntity			Entity::getType(void) const { return (_type); }
Entity::eDirection		Entity::getDirection(void) const { return (_direction); }
void				Entity::setId(int const id) { _id = id; }
void				Entity::setX(int const x) { _x = x; }
void				Entity::setY(int const y) { _y = y; }
void				Entity::setType(eEntity const type) { _type = type; }
void				Entity::setDirection(eDirection const direction) { _direction = direction; }

//--------------------------------END GETTERS / SETTERS-------------------------------------

