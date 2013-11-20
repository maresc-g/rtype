//
// LevelManager.hh for level in /home/maitre_c/work/local/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:58:48 2013 antoine maitre
// Last update Wed Nov 20 15:31:39 2013 antoine maitre
//

#ifndef __LEVELMANAGER_HH__
#define __LEVELMANAGER_HH__

#include <list>
#include <string>
#include "Level.hh"

class	LevelManager
{
private:
  std::string			_path;
  std::list<Level *>		_levels;
  Level				*_currentLevel;
  unsigned int			_diff;
  bool				_endGame;
public:
  const std::string		&getPath() const;
  const std::list<Level *>	&getLevels() const;
  const Level			&getCurrentLevel() const;

public:
  LevelManager();
  ~LevelManager();
  
  void Initialize();
  void nextLevel();
  Level *getCurrentLevel();
  bool getEndGame();
  void incAdv();
  Map *getMap();
  int getAdv() const;
  int getPixelAdv() const;
  std::list<AEntity *> &getEnemies();
  std::list<AEntity *> &getPlayers();
  unsigned int getDiff() const;
};

#endif
