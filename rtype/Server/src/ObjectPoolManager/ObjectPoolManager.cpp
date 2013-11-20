//
// ObjectPoolManager.cpp for  in /home/ansel_l/Documents/Rtype/work/Server/include/ObjectPoolManager
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Wed Nov  6 17:04:40 2013 laurent ansel
// Last update Wed Nov 20 18:29:23 2013 antoine maitre
//

#include		"ObjectPoolManager/ObjectPoolManager.hh"

ObjectPoolManager::ObjectPoolManager():
  _listEntities(new std::map<AEntity::eObject, std::list<AEntity *> *>),
  _mutex(new Mutex),
  _quit(false),
  _updater(new ObjectPoolUpdater(_listEntities, *_mutex, _quit))
{
  this->_mutex->initialize();
  this->_mutex->enter();
  (*this->_listEntities)[AEntity::MOB] = new std::list<AEntity *>;
  (*this->_listEntities)[AEntity::ROCKET] = new std::list<AEntity *>;
  (*this->_listEntities)[AEntity::PLAYER] = new std::list<AEntity *>;
  this->_mutex->leave();

  this->_updater->start();
}

ObjectPoolManager::~ObjectPoolManager()
{
  this->_mutex->enter();
  this->_quit = true;
  this->_mutex->leave();
  this->_updater->waitThread();
  this->_mutex->destroy();
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
