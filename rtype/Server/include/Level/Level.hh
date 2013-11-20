//
// Level.hh for level in /home/maitre_c/work/local/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 16:17:37 2013 antoine maitre
// Last update Wed Nov 20 15:33:52 2013 antoine maitre
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
  int _pixelAdv;
public:
  Level(int diff);
  ~Level();
  Map *getMap();
  void Initialize();
  bool getEnd();
  unsigned int getDiff();
  void incAdv();
  unsigned int getAdv() const;
  int getPixelAdv() const;
  std::list<AEntity *> &getEnemies();
  std::list<AEntity *> &getPlayers();
};

#endif
