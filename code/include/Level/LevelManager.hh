//
// LevelManager.hh for level in /home/maitre_c/work/local/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:58:48 2013 antoine maitre
// Last update Wed Oct 30 17:20:55 2013 antoine maitre
//

#ifndef __LEVELMANAGER_HH__
#define __LEVELMANAGER_HH__

#include <list>
#include <string>
#include "Level.hh"

class	LevelManager
{
  int _diff;
  std::list<Level *> _levels;
  Level *_currentLevel;
  bool _endGame;
public:
  LevelManager();
  ~LevelManager();
  void Initialize();
  void nextLevel();
  Level *getCurrentLevel();
  bool getEndGame();
};

#endif
