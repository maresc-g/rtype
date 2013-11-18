//
// Mob.hh for mob in /home/maitre_c/work/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Wed Oct 30 11:14:28 2013 antoine maitre
// Last update Mon Nov 18 13:59:03 2013 antoine maitre
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
private:
  Action	*_action;

public:
  Mob(int const x, int const y, std::string const &path, int const speed);
  virtual ~Mob();
  AEntity::eObject getType() const;
  virtual Action const	*getAction() const;
};

#endif
