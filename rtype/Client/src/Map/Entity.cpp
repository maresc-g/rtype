//
// Entity.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Nov  4 17:23:41 2013 guillaume marescaux
// Last update Mon Nov  4 17:34:18 2013 guillaume marescaux
//

#include			"Map/Entity.hh"

//----------------------------------BEGIN CTOR / DTOR---------------------------------------

Entity::Entity(int const id, int const x, int const y):
  _id(id), _x(x), _y(y)
{
}

Entity::Entity(Entity const &other):
  _id(other._id), _x(other._x), _y(other._y)
{
}

Entity				&Entity::operator=(Entity const &other)
{
  if (this != &other)
    {
      _id = other._id;
      _x = other._x;
      _y = other._y;
    }
  return (*this);
}

Entity::~Entity() {}

//-----------------------------------END CTOR / DTOR----------------------------------------

//-------------------------------BEGIN GETTERS / SETTERS------------------------------------

int				Entity::getId(void) const { return (_id); }
int				Entity::getX(void) const { return (_x); }
int				Entity::getY(void) const { return (_y); }
void				Entity::setId(int const id) { _id = id; }
void				Entity::setX(int const x) { _x = x; }
void				Entity::setY(int const y) { _y = y; }

//--------------------------------END GETTERS / SETTERS-------------------------------------

