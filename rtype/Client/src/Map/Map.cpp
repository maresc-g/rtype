//
// Map.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Nov  4 17:22:47 2013 guillaume marescaux
// Last update Tue Nov  5 10:07:00 2013 guillaume marescaux
//

#include			"Map/Map.hh"

//----------------------------------BEGIN CTOR / DTOR---------------------------------------

Map::Map():
  _entities(new std::list<Entity *>)
{
}

Map::~Map()
{
  for (auto it = _entities->begin() ; it != _entities->end() ; it++)
    {
      delete *it;
    }
  delete _entities;
}

//-----------------------------------END CTOR / DTOR----------------------------------------

//------------------------------------BEGIN METHODS-----------------------------------------

void				Map::moveEntity(int const id, int const x, int const y)
{
  for (auto it = _entities->begin() ; it != _entities->end() ; it++)
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
    _entities->push_back(entity);
}

void				Map::removeEntity(int const id)
{
  for (auto it = _entities->begin() ; it != _entities->end() ; it++)
    {
      if ((*it)->getId() == id)
	{
	  delete *it;
	  _entities->erase(it);
	  break;
	}      
    }
}

//-------------------------------------END METHODS------------------------------------------
