//
// Map.hh for map in /home/maitre_c/work/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 17:15:50 2013 antoine maitre
// Last update Thu Nov  7 16:05:15 2013 antoine maitre
//

#ifndef	__MAP_HH__
#define __MAP_HH__

#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include "Entities/Mob.hh"
#include "Entities/Player.hh"
#include "Entities/Weapon/AProjectile.hh"

#define SCREENX 80
#define SCREENY 80

class	Map
{
  std::vector<std::string> *_map;
  std::list<AEntity *> _enemies;
  std::list<AEntity *> _players;
  std::list<AEntity *> _enemiesStatic;
  //  std::list<AProjectile *> _proj;
  int _x;
  int _y;
public:
  Map(std::string path);
  ~Map();
  std::list<AEntity *> &getEnemies();
  std::list<AEntity *> &getPlayers();
  std::vector<std::string> *getMap();
  void setEnemies();
  int getPosX() const;
  int getPosY() const;
};

#endif
