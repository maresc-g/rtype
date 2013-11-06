//
// Map.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Nov  4 17:22:47 2013 guillaume marescaux
// Last update Wed Nov  6 16:32:58 2013 guillaume marescaux
//

#include			"Map/Map.hh"

//----------------------------------BEGIN CTOR / DTOR---------------------------------------

Map::Map():
  _map(new std::list<Entity *>)
{
}

Map::~Map()
{
  for (auto it = _map->begin() ; it != _map->end() ; it++)
    {
      delete (*it);
    }
  delete _map;
}

//-----------------------------------END CTOR / DTOR----------------------------------------

//------------------------------------BEGIN METHODS-----------------------------------------

void				Map::moveEntity(int const id, int const x, int const y)
{
  for (auto it = _map->begin() ; it != _map->end() ; it++)
    {
      if ((*it)->getId() == id)
	{
	  (*it)->setX(x);
	  (*it)->setY(y);
	  break;
	}
    }
}

void				Map::addEntity(Entity *entity)
{
  if (entity)
    _map->push_back(entity);
}

void				Map::removeEntity(int const id)
{
  for (auto it = _map->begin() ; it != _map->end() ; it++)
    {
      if ((*it)->getId() == id)
	{
	  delete *it;
	  _map->erase(it);
	  break;
	}      
    }
}

void				Map::clear()
{
  for (auto it = _map->begin() ; it != _map->end() ; it++)
    {
      delete *it;
    }
  _map->clear();
}

bool				Map::exists(int const id) const
{
  for (auto it = _map->begin() ; it != _map->end() ; it++)
    {
      if ((*it)->getId() == id)
	return (true);
    }
  return (false);
}

//-------------------------------------END METHODS------------------------------------------
