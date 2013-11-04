//
// Map.hh for map in /home/maitre_c/work/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 17:15:50 2013 antoine maitre
// Last update Wed Oct 30 17:39:20 2013 antoine maitre
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

class	Map
{
  std::vector<std::string> *_map;
  std::list<Mob *> _staticEntities;
  std::list<Mob *> _dynamicEntities;
  int _x;
  int _y;
public:
  Map(std::string path);
  ~Map();
  std::list<Mob *> getDynamicEntities();
  std::list<Mob *> getStaticEntities();
  std::vector<std::string> *getMap();
  void setStaticEntitiesMap();
};

#endif
