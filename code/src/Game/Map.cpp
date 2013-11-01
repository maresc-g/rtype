//
// Map.cpp for game in /home/maitre_c/work/rtype/code/src/Game
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 17:15:04 2013 antoine maitre
// Last update Fri Nov  1 10:46:11 2013 arthur rucquois
//

#include "Game/Map.hh"

void		Map::addItem(const AEntity *item)
{
  this->items.push_back(item);
  switch (item->getEObject())
    {
    case PLAYER:
      this->players.push_back(item);
    case ROCKET:
      this->projectiles.push_back(item);
    case MOB:
      this->enemies.push_back(item);
    break;
    }
}

const std::vector<AEntity *>		&Map::getItems() const
{
  return (this->items);
}

const std::vector<Mob *>		&Map::getMobs() const
{
  return (this->mobs);
}

const std::vector<Player *>		&Map::getPlayers() const
{
  return (this->players);
}

const std::vector<AProjectile *>	&Map::getProjectiles() const
{
  return (this->projectiles);
}
