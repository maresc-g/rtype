//
// Map.hh for map in /home/maitre_c/work/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 17:15:50 2013 antoine maitre
// Last update Sun Nov 24 11:54:31 2013 laurent ansel
//

#ifndef	__MAP_HH__
#define __MAP_HH__

#include			<stdlib.h>
#include			<string>
#include			<vector>
#include			<fstream>
#include			<iostream>
#include			<list>
#include			<sstream>
#include			"Entities/Mob.hh"
#include			"Entities/Player.hh"
#include			"Entities/Weapon/AProjectile.hh"
#include			"Entities/Wall.hh"

#define				SCREENX 80
#define				SCREENY 80

class						Map
{
  std::vector<std::vector<unsigned int>>	*_map;
  std::list<AEntity *>				_enemies;
  std::list<AEntity *>				_players;
  std::list<AEntity *>				_walls;
  std::list<AEntity *>				_inactiveWalls;
  std::list<AEntity *>				_enemiesStatic;
  //  std::list<AProjectile *> _proj;
  int						_x;
  int						_y;
public:
  Map(std::string path);
  ~Map();
  std::list<AEntity *>				&getEnemies();
  std::list<AEntity *>				&getPlayers();
  std::list<AEntity *>				&getWalls();
  std::list<AEntity *>				&getInactiveWalls();
  std::list<AEntity *>::iterator const		&spawnWall(std::list<AEntity *>::iterator &it);
  std::vector<std::vector<unsigned int>>	*getMap();
  void						setEntities(int adv);
  void						tryToSet(std::list<AEntity *>&, std::list<AEntity *>&, int);
  int						getPosX() const;
  int						getPosY() const;
};

#endif
