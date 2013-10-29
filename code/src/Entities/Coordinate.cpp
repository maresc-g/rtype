//
// Coordinate.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 14:14:47 2013 guillaume marescaux
// Last update Mon Oct 28 14:19:00 2013 guillaume marescaux
//

#include			"Entities/Coordinate.hh"

//----------------------------------BEGIN CTOR / DTOR-------------------------------------------

Coordinate::Coordinate(int x, int y):
  _x(x), _y(y)
{
}

Coordinate::Coordinate(Coordinate const &other):
  _x(other._x), _y(other._y)
{
}

Coordinate			&Coordinate::operator=(Coordinate const &other)
{
  if (this != &other)
    {
      _x = other._x;
      _y = other._y;
    }
  return (*this);
}

Coordinate::~Coordinate()
{
}

//----------------------------------END CTOR / DTOR-------------------------------------------

//----------------------------------BEGIN GETTERS / SETTERS-----------------------------------

int				Coordinate::getX(void) const { return (_x); }
void				Coordinate::setX(int x) { _x = x; }
int				Coordinate::getY(void) const { return (_y); }
void				Coordinate::setY(int y) { _y = y; }

//-----------------------------------END GETTERS / SETTERS------------------------------------
