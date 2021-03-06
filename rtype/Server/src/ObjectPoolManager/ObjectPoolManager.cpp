//
// ObjectPoolManager.cpp for  in /home/ansel_l/Documents/Rtype/work/Server/include/ObjectPoolManager
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Wed Nov  6 17:04:40 2013 laurent ansel
// Last update Sun Nov 24 12:22:39 2013 laurent ansel
//

#include		"ObjectPoolManager/ObjectPoolManager.hh"

ObjectPoolManager::ObjectPoolManager():
  _listEntities(new std::map<AEntity::eObject, std::list<AEntity *> *>),
  _mutex(new Mutex),
  _quit(false)
{
  this->_mutex->initialize();
  this->_mutex->enter();
  (*this->_listEntities)[AEntity::MOB] = new std::list<AEntity *>;
  (*this->_listEntities)[AEntity::ROCKET] = new std::list<AEntity *>;
  (*this->_listEntities)[AEntity::PLAYER] = new std::list<AEntity *>;
  this->_mutex->leave();
  this->_updater = new ObjectPoolUpdater(_listEntities, *_mutex, _quit);
  this->_updater->start();
}

ObjectPoolManager::~ObjectPoolManager()
{
  this->_mutex->enter();
  this->_quit = true;
  this->_mutex->leave();
  this->_updater->waitThread();
  for (auto it = this->_listEntities->begin() ; it != this->_listEntities->end() ; ++it)
    {
      for (auto itObject = it->second->begin() ; itObject != it->second->end() ; ++itObject)
	if ((*itObject))
	  delete *itObject;
      if (it->second)
	delete it->second;
    }
  delete _listEntities;
  delete _updater;
  this->_mutex->destroy();
  delete _mutex;
}

AEntity			*ObjectPoolManager::getCopy(enum AEntity::eObject const type)
{
  this->_mutex->enter();
  std::map<AEntity::eObject, std::list<AEntity *> *>::iterator	it;
  AEntity		*tmp = NULL;

  // std::cout << (*_listEntities)[AEntity::MOB]->size() << std::endl;
  // std::cout << (*_listEntities)[AEntity::PLAYER]->size() << std::endl;
  if ((it = _listEntities->find(type)) != _listEntities->end())
    if (!it->second->empty())
      {
	tmp = it->second->front();
	it->second->pop_front();
      }
  this->_mutex->leave();
  return (tmp);
}
