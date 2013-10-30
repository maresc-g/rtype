//
// Map.hh for map in /home/maitre_c/work/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 17:15:50 2013 antoine maitre
// Last update Wed Oct 30 10:54:39 2013 antoine maitre
//

#ifndef	__MAP_HH__
#define __MAP_HH__

#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class	Map
{
  std::vector<std::string> *_map;
public:
  Map(std::string path);
  ~Map();
  std::vector<std::string> *getMap();
};

#endif
