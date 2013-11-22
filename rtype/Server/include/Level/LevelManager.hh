//
// LevelManager.hh for level in /home/maitre_c/work/local/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:58:48 2013 antoine maitre
// Last update Fri Nov 22 10:57:23 2013 arthur rucquois
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
  int getPosAdv() const;
  std::list<AEntity *> &getEnemies();
  std::list<AEntity *> &getPlayers();
  std::list<AEntity *> &getWalls();
  std::list<AEntity *> &getInactiveWalls();
  std::list<AEntity *>::iterator const	&spawnWall(std::list<AEntity *>::iterator &it);
  unsigned int getDiff() const;
};

#endif
