//
// Wall.hh for  in /home/couillere/cpp/rtype/rtype
// 
// Made by arthur rucquois
// Login   <rucquo_a@epitech.net>
// 
// Started on  Thu Nov 21 12:31:10 2013 arthur rucquois
// Last update Fri Nov 22 11:23:12 2013 arthur rucquois
//

#ifndef		__WALL_H__
#define		__WALL_H__

#include	<string>
#include	<iostream>
#include	<sstream>
#include	<fstream>
#include	"AEntity.hh"

class			Wall : public AEntity
{
public:
  AEntity::eObject	getType() const;
  Wall(int const x, int const y, std::string const &path);
  virtual ~Wall();
};

#endif
