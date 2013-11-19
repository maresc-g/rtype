//
// ObjectPoolUpdater.hh for  in /home/ansel_l/Documents/Rtype/work/Server/include/ObjectPoolManager
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Wed Nov  6 16:51:50 2013 laurent ansel
// Last update Tue Nov 19 13:54:10 2013 laurent ansel
//

#ifndef 			__OBJECTPOOLUPDATER_HH__
# define 			__OBJECTPOOLUPDATER_HH__

#include			<map>
#include			<list>
#include			"Entities/AEntity.hh"
#include			"Entities/Player.hh"
#include			"Thread/Thread.hpp"
#include			"Mutex/Mutex.hpp"

#define	MAX_OBJECT		100

class				ObjectPoolUpdater : public Thread
{
private:
  std::map<AEntity::eObject, std::list<AEntity *> *>	*_listCopy;
  std::map<AEntity::eObject, AEntity *>	*_entity;
  Mutex				&_mutex;
  bool				&_quit;
public:
  ObjectPoolUpdater(std::map<AEntity::eObject, std::list<AEntity *> *> *list, Mutex &mutex, bool &quit);
  virtual ~ObjectPoolUpdater();
  void				run();
};

void				*startUpdater(void *data);

#endif
