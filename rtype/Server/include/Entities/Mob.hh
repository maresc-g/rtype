//
// Mob.hh for mob in /home/maitre_c/work/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Wed Oct 30 11:14:28 2013 antoine maitre
// Last update Sun Nov 24 16:24:15 2013 alexis mestag
//

#ifndef		__MOB_H__
#define		__MOB_H__

#include	<string>
#include	<iostream>
#include	<sstream>
#include	<fstream>
#include	"ACharacter.hh"
#include	"Entities/Weapon/AProjectile.hh"
#include	"Action/Action.hh"

class		Mob : public ACharacter
{
protected:
  Action	*_action;
  std::string	_name;

public:
  Mob(int const x = 0, int const y = 0, std::string const &path = "", int const speed = 50);
  virtual ~Mob();
  AEntity::eObject getType() const;
  virtual Action const	*getAction();
  std::string const	&getName() const;
};

#endif
