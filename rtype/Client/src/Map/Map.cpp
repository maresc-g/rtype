//
// Map.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Nov  4 17:22:47 2013 guillaume marescaux
// Last update Tue Nov  5 14:14:45 2013 guillaume marescaux
//

#include			"Map/Map.hh"

//----------------------------------BEGIN CTOR / DTOR---------------------------------------

Map::Map():
  _map(new std::map<eMap, std::list<Entity *>*>)
{
}

Map::~Map()
{
  for (auto it = _map->begin() ; it != _map->end() ; it++)
    {
      for (auto itList = (*it).second->begin() ; itList != (*it).second->end() ; itList++)
	delete *itList;
      delete (*it).second;
    }
  delete _map;
}

//-----------------------------------END CTOR / DTOR----------------------------------------

//------------------------------------BEGIN METHODS-----------------------------------------

void				Map::moveEntity(int const id, int const x, int const y, eMap const type)
{
  for (auto it = (*_map)[type]->begin() ; it != (*_map)[type]->end() ; it++)
    {
      if ((*it)->getId() == id)
	{
	  (*it)->setX(x);
	  (*it)->setY(y);
	  break;
	}
    }
}

void				Map::addEntity(Entity *entity, eMap const type)
{
  if (entity)
    (*_map)[type]->push_back(entity);
}

void				Map::removeEntity(int const id, eMap const type)
{
  for (auto it = (*_map)[type]->begin() ; it != (*_map)[type]->end() ; it++)
    {
      if ((*it)->getId() == id)
	{
	  delete *it;
	  (*_map)[type]->erase(it);
	  break;
	}      
    }
}

void				Map::clear(eMap const type)
{
  for (auto it = (*_map)[type]->begin() ; it != (*_map)[type]->end() ; it++)
    {
      delete *it;
    }
  (*_map)[type]->clear();
}

bool				Map::exists(int const id, eMap const type) const
{
  for (auto it = (*_map)[type]->begin() ; it != (*_map)[type]->end() ; it++)
    {
      if ((*it)->getId() == id)
	return (true);
    }
  return (false);
}

//-------------------------------------END METHODS------------------------------------------
