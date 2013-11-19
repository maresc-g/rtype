//
// Map.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Nov  4 17:22:47 2013 guillaume marescaux
// Last update Tue Nov 19 12:26:16 2013 guillaume marescaux
//

#include			"Map/Map.hh"

//----------------------------------BEGIN CTOR / DTOR---------------------------------------

Map::Map():
  _map(new std::list<Entity *>), _entities(new std::list<Entity *>), _mutex(new Mutex), _scroll(0)
{
  _mutex->initialize();
}

Map::~Map()
{
  _mutex->enter();
  for (auto it = _map->begin() ; it != _map->end() ; it++)
    {
      delete (*it);
    }
  delete _map;
  for (auto it = _entities->begin() ; it != _entities->end() ; it++)
    {
      delete (*it);
    }
  delete _entities;
  _mutex->leave();
  _mutex->destroy();
  delete _mutex;
}

//-----------------------------------END CTOR / DTOR----------------------------------------

//------------------------------------BEGIN METHODS-----------------------------------------

void				Map::moveEntity(int const id, int const x, int const y)
{
  _mutex->enter();
  for (auto it = _entities->begin() ; it != _entities->end() ; it++)
    {
      if ((*it)->getId() == id)
	{
	  (*it)->setX(x);
	  (*it)->setY(y);
	  break;
	}
    }
  _mutex->leave();
}

void				Map::addEntity(Entity *entity)
{
  if (entity)
    {
      _mutex->enter();
      _entities->push_back(entity);
      _mutex->leave();
    }
}

void				Map::addDecor(Entity *entity)
{
  if (entity)
    {
      _mutex->enter();
      _map->push_back(entity);
      _mutex->leave();
    }
}

void				Map::removeEntity(int const id)
{
  _mutex->enter();
  for (auto it = _entities->begin() ; it != _entities->end() ; it++)
    {
      if ((*it)->getId() == id)
	{
	  delete *it;
	  _entities->erase(it);
	  break;
	}      
    }
  _mutex->leave();
}

void				Map::clear()
{
  _mutex->enter();
  for (auto it = _map->begin() ; it != _map->end() ; it++)
    {
      delete *it;
    }
  for (auto it = _entities->begin() ; it != _entities->end() ; it++)
    {
      delete *it;
    }
  _map->clear();
  _mutex->leave();
}

bool				Map::exists(int const id) const
{
  _mutex->enter();
  for (auto it = _entities->begin() ; it != _entities->end() ; it++)
    {
      if ((*it)->getId() == id)
	{
	  _mutex->leave();
	  return (true);
	}
    }
  _mutex->leave();
  return (false);
}

//-------------------------------------END METHODS------------------------------------------

void				Map::setScroll(unsigned int const scroll)
{
  _mutex->enter();
  _scroll = scroll;
  _mutex->leave();
}

unsigned int			Map::getScroll(void) const
{
  unsigned int			tmp;

  _mutex->enter();
  tmp = _scroll;
  _mutex->leave();
  return (tmp);
}

std::list<Entity *> const	&Map::getMap(void) const
{
  std::list<Entity *>		*tmp;

  _mutex->enter();
  tmp = _map;
  _mutex->leave();
  return (*tmp);
}

std::list<Entity *> const	&Map::getEntities(void) const
{
  std::list<Entity *>		*tmp;

  _mutex->enter();
  tmp = _entities;
  _mutex->leave();
  return (*tmp);
}
