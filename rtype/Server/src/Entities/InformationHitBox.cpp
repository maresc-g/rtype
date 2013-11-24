//
// InformationHitbox.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Nov 12 18:52:21 2013 laurent ansel
// Last update Sun Nov 24 12:13:58 2013 laurent ansel
//

#include			<list>
#include			"Entities/InformationHitBox.hh"

InformationHitBox::InformationHitBox(Coordinate const &coord, int const width, int const height):
  _coord(new Coordinate(coord)),
  _origCoord(new Coordinate(coord)),
  _width(width),
  _height(height)
{

}

InformationHitBox::~InformationHitBox()
{
  if (_coord)
    delete _coord;
  if (_origCoord)
    delete _origCoord;
}

InformationHitBox::InformationHitBox(InformationHitBox const &other):
  _coord(new Coordinate(other.getCoordinate())),
  _origCoord(new Coordinate(other.getOrigCoordinate())),
  _width(other._width),
  _height(other._height)
{

}

InformationHitBox		&InformationHitBox::operator=(InformationHitBox const &other)
{
  if (this != &other)
    {
      this->_coord = other._coord;
      this->_origCoord = other._origCoord;
      this->setWidth(other.getWidth());
      this->setHeight(other.getHeight());
    }
  return (*this);
}

Coordinate const		&InformationHitBox::getCoordinate() const
{
  return (*this->_coord);
}

Coordinate const		&InformationHitBox::getOrigCoordinate() const
{
  return (*this->_origCoord);
}

int			InformationHitBox::getWidth() const
{
  return (this->_width);
}

int			InformationHitBox::getHeight() const
{
  return (this->_height);
}

void				InformationHitBox::setCoordinate(Coordinate const &coord)
{
  *this->_coord = coord;
}

void				InformationHitBox::setWidth(int const width)
{
  this->_width = width;
}

void				InformationHitBox::setHeight(int const height)
{
  this->_height = height;
}
