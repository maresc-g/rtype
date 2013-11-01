//
// Map.hh for map in /home/maitre_c/work/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 17:15:50 2013 antoine maitre
// Last update Fri Nov  1 10:46:09 2013 arthur rucquois
//

#ifndef	__MAP_HH__
#define __MAP_HH__

class	Map
{
private:
  std::vector<AEntity *>		items;
  std::vector<Mob *>			mobs;
  std::vector<Player *>			players;
  std::vector<AProjectile *>		projectiles;
public:
  void					addItem(const AEntity *item);
  const std::vector<AEntity *>		&getItems() const;
  const std::vector<AMob *>		&getEnemies() const;
  const std::vector<APlayer *>		&getPlayers() const;
  const std::vector<AProjectile *>	&getProjectiles() const;
public:
  Map();
  ~Map();
};

#endif
