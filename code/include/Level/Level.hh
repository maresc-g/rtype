//
// Level.hh for level in /home/maitre_c/work/local/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 16:17:37 2013 antoine maitre
// Last update Wed Oct 30 10:12:23 2013 antoine maitre
//
 
#ifndef	__LEVEL_HH__
#define __LEVEL_HH__

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Level/Map.hh"

class	Level
{
  int	_diff;
  Map	*_map;
  int	_currentScreen;
public:
  Level(int diff);
  ~Level();
};

#endif
