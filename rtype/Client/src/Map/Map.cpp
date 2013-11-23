//
// Map.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Nov  4 17:22:47 2013 guillaume marescaux
// Last update Sat Nov 23 23:59:17 2013 guillaume marescaux
//

#include			"Map/Map.hh"

//----------------------------------BEGIN CTOR / DTOR---------------------------------------

Map::Map():
  _entities(new std::list<Entity *>), _mutex(new Mutex), _scroll(0)
{
  _mutex->initialize();
}

Map::~Map()
{
  _mutex->enter();
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

void				Map::moveEntity(int const id, int const x, int const y, std::string const &direction)
{
  _mutex->enter();
  for (auto it = _entities->begin() ; it != _entities->end() ; it++)
    {
      if ((*it)->getId() == id)
	{
	  (*it)->setX(x);
	  (*it)->setY(y);
	  (*it)->setDirection(direction);
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

void				Map::removeEntity(int const id)
{
  _mutex->enter();
  for (auto it = _entities->begin() ; it != _entities->end() ; it++)
    {
      if ((*it)->getId() == id)
	{
	  _entities->push_back(new Entity((*it)->getId(), (*it)->getX(), (*it)->getY(), "explosion"));
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
  for (auto it = _entities->begin() ; it != _entities->end() ; it++)
    {
      delete *it;
    }
  _entities->clear();
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

std::list<Entity *>		*Map::copyList(std::list<Entity*> const &toCopy) const
{
  std::list<Entity *>		*ret = new std::list<Entity *>;
  Entity			*tmp;

  for (auto it = toCopy.begin() ; it != toCopy.end() ; it++)
    {
      tmp = new Entity(**it);
      tmp->setTime((*it)->getClock().getElapsedTime().asSeconds());
      ret->push_back(tmp);
    }
  return (ret);
}

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

std::list<Entity *>		*Map::getEntities(void) const
{
  std::list<Entity *>		*tmp = new std::list<Entity *>;

  _mutex->enter();
  for (auto it = _entities->begin() ; it != _entities->end() ; it++)
    {
      if ((*it)->getInvincible() && (*it)->getClock().getElapsedTime().asSeconds() >= 1.5)
	(*it)->setInvincible(false);
      if ((*it)->getType() == "explosion" && (*it)->getClock().getElapsedTime().asSeconds() >= 1)
	{
	  delete *it;
	  it = _entities->erase(it);
	}
    }
  tmp = this->copyList(*_entities);
  _mutex->leave();
  return (tmp);
}

Entity const			*Map::getEntityById(int const id) const
{
  for (auto it = _entities->begin() ; it != _entities->end() ; it++)
    {
      if ((*it)->getId() == id)
	return (*it);
    }
  return (NULL);
}

void				Map::setInvincible(int const id, bool const invincible)
{
  for (auto it = _entities->begin() ; it != _entities->end() ; it++)
    {
      if ((*it)->getId() == id)
	(*it)->setInvincible(invincible);
    }
}
