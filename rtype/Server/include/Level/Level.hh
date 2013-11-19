//
// Level.hh for level in /home/maitre_c/work/local/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 16:17:37 2013 antoine maitre
// Last update Tue Nov 19 13:42:27 2013 antoine maitre
//
 
#ifndef	__LEVEL_HH__
#define __LEVEL_HH__

#include <iostream>
#include <fstream>
#include <string>
#include "Level/Map.hh"

class	Level
{
  unsigned int	_diff;
  Map	*_map;
  std::string _path;
  bool _finish;
  int _adv;
public:
  Level(int diff);
  ~Level();
  Map *getMap();
  void Initialize();
  bool getEnd();
  unsigned int getDiff();
  void incAdv();
  unsigned int getAdv() const;
  std::list<AEntity *> &getEnemies();
  std::list<AEntity *> &getPlayers();
};

#endif
