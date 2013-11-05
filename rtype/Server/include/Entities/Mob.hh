//
// Mob.hh for mob in /home/maitre_c/work/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Wed Oct 30 11:14:28 2013 antoine maitre
// Last update Wed Oct 30 12:38:33 2013 antoine maitre
//

#ifndef	__MOB_H__
#define __MOB_H__

#include	<string>
#include	<iostream>
#include	<sstream>
#include	<fstream>
#include	"AEntity.hh"

class	Mob : public AEntity
{
public:
  Mob(int const x, int const y, std::string const &path, int const speed, bool const destructible);
  ~Mob();
};

#endif
