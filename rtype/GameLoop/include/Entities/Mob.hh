//
// Mob.hh for mob in /home/maitre_c/work/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Wed Oct 30 11:14:28 2013 antoine maitre
// Last update Tue Nov  5 10:50:00 2013 antoine maitre
//

#ifndef	__MOB_H__
#define __MOB_H__

#include	<string>
#include	<iostream>
#include	<sstream>
#include	<fstream>
#include	"ACharacter.hh"

class	Mob : public ACharacter
{
public:
  Mob(int const x, int const y, std::string const &path, int const speed, bool const destructible);
  ~Mob();
  eObject getType() const;
};

#endif
