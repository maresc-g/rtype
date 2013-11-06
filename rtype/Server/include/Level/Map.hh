//
// Map.hh for map in /home/maitre_c/work/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 17:15:50 2013 antoine maitre
// Last update Wed Nov  6 12:23:38 2013 antoine maitre
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

class	Map
{
  std::vector<std::string> *_map;
  std::list<Mob *> _enemies;
  std::list<Player *> _players;
  std::list<AProjectile *> _proj;
  int _x;
  int _y;
public:
  Map(std::string path);
  ~Map();
  std::list<Mob *> &getEnemies();
  std::list<Player *> &getPlayers();
  std::vector<std::string> *getMap();
  void setEnemies();
  int getPosX() const;
  int getPosY() const;
};

#endif
