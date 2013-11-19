//
// ObjectPoolUpdater.cpp for  in /home/ansel_l/Documents/Rtype/work/Server/include/ObjectPoolManager
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Wed Nov  6 17:17:27 2013 laurent ansel
// Last update Mon Nov 18 22:29:04 2013 laurent ansel
//

#ifndef	_WIN32
#include			<unistd.h>
#else
#include			<Windows.h>
#endif
#include			"Entities/Mob.hh"
#include			"Entities/Weapon/Rocket.hh"
#include			"ObjectPoolManager/ObjectPoolUpdater.hh"

ObjectPoolUpdater::ObjectPoolUpdater(std::map<AEntity::eObject, std::list<AEntity *> *> *list, Mutex &mutex, bool &quit) :
  Thread(),
  _listCopy(list),
  _entity(new std::map<AEntity::eObject, AEntity *>),
  _mutex(mutex),
  _quit(quit)
{
  (*this->_entity)[AEntity::MOB] = new Mob(0, 0, "", 0);
  this->createThread(&startUpdater, this);
}

ObjectPoolUpdater::~ObjectPoolUpdater()
{

}

void				ObjectPoolUpdater::run()
{
  std::map<AEntity::eObject, AEntity *>::iterator	itEntity;
  size_t			size;
  size_t			nbObject;

  this->_mutex.enter();
  while (!_quit)
    {
      size = 0;
      nbObject = this->_entity->size();
      itEntity = this->_entity->begin();
      for (auto it = this->_listCopy->begin() ; it != this->_listCopy->end() ; ++it)
	{
	  size += it->second->size();
	  if (it->second->size() < MAX_OBJECT)
	    it->second->push_back(itEntity->second);
	  ++itEntity;
	}
      if (!_quit)
	{
	  this->_mutex.leave();
	  if (nbObject && size / nbObject > 50)
	    {
#ifndef _WIN32
	      sleep(1);
#else
	      Sleep(1000);
#endif
	    }
	  else
	    {
#ifndef _WIN32
	      usleep(5000);
#else
	      Sleep(5);
#endif
	    }
	}
      this->_mutex.enter();
    }
  this->_mutex.leave();
}

void				*startUpdater(void *data)
{
  ObjectPoolUpdater		*tmp = reinterpret_cast<ObjectPoolUpdater *>(data);

  if (tmp)
    tmp->run();
  return (NULL);
}
