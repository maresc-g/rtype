//
// Wall.cpp for  in /home/couillere/cpp/rtype/rtype
// 
// Made by arthur rucquois
// Login   <rucquo_a@epitech.net>
// 
// Started on  Thu Nov 21 13:10:41 2013 arthur rucquois
// Last update Sat Nov 23 00:41:58 2013 laurent ansel
//

#include "Entities/Wall.hh"

AEntity::eObject	Wall::getType() const
{
  return (AEntity::WALL);
}

Wall::Wall(int const x, int const y, std::string const &path):
  AEntity(x, y, path, 0, false)
{
}

Wall::~Wall()
{
}
