//
// ObjectPoolManager.hh for  in /home/ansel_l/Documents/Rtype/work/Server/include/ObjectPoolManager
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Wed Nov  6 16:40:00 2013 laurent ansel
// Last update Wed Nov  6 18:35:36 2013 laurent ansel
//

#ifndef 			__OBJECTPOOLMANAGER_HH__
# define 			__OBJECTPOOLMANAGER_HH__

#include			"Entities/AEntity.hh"
#include			"Thread/Thread.hpp"
#include			"Utility/Singleton.hpp"
#include			"Mutex/Mutex.hpp"
#include			"ObjectPoolManager/ObjectPoolUpdater.hh"

class				ObjectPoolManager : public Singleton<ObjectPoolManager>
{
  friend class			Singleton<ObjectPoolManager>;

private:
  std::map<AEntity::eObject, std::list<AEntity *> *>	*_listEntities;
  Mutex				*_mutex;
  bool				_quit;
  ObjectPoolUpdater		*_updater;
  ObjectPoolManager();
  virtual ~ObjectPoolManager();
public:
  AEntity			*getCopy(AEntity::eObject const type);
};

#endif
