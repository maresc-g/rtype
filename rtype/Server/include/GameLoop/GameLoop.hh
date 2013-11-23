//
// GameLoop.hh for rtype in /home/maitre_c/work/local/rtype/code/include/GameLoop
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:41:34 2013 antoine maitre
// Last update Sat Nov 23 18:10:11 2013 laurent ansel
//

#ifndef	__GAMELOOP_HH__
#define __GAMELOOP_HH__


#ifndef		_WIN32
#include		<unistd.h>
#else
#define		_WINSOCKAPI_
#include		<Windows.h>
#endif

#include		<string>
#include		"DynamicLibrary/DynamicLibraryManager.hh"
#include		"ObjectPoolManager/ObjectPoolManager.hh"
#include		"ClientInfo/ClientInfo.hh"
#include		"ObjectPoolManager/ObjectPoolManager.hh"
#include		"Entities/AEntity.hh"
#include		"Level/LevelManager.hh"
#include		"GameLoop/PlayerInfo.hh"
#include		"Thread/Thread.hpp"
#include		"Mutex/Mutex.hpp"

class			GameLoop : public Thread
{
private:
  GameLibraries			*_library;
  LevelManager			*_levelManag;
  std::list<PlayerInfo *>	*_clients;
  int				_rate;
  std::string			_name;
  unsigned int			_id;
  bool				_criticalError;
  Mutex				*_mutex;
  unsigned int			_idEntity;
public:
  GameLoop(std::string const &name, unsigned int const id);
  virtual ~GameLoop();
private:
  void				sendScreen(std::list<AEntity *> &list);
  void				spawnMob();
  void				spawnWalls();
  void				destroyDeadEntities(std::list<AEntity *> &enemies, std::list<AEntity *> &players);
public:
  bool				newPlayer(ClientInfo *newClient);
  void				playerDeath(PlayerInfo *deadPlayer);
  void				loop();
  void				Initialize();
  unsigned int			getId() const;
  std::string			getName() const;
  unsigned int			getNumPlayer() const;
  void				quitGame();
  bool				deletePlayer(ClientInfo *client);
  unsigned int			getLevel() const;
  bool				checkActiveClient();
private:
  void				sendDeadEntity(unsigned int) const;
  void				sendScroll(unsigned int scroll) const;
  void				sendClient(const std::string &, const std::string &) const;
  void				sendEntity(AEntity *) const;
  void				scrolling();
  void				action() const;
  void				quitClients();
  void				execAction(Action const &action, AEntity *entity, int const adv, Map *map);
  void				sendLostLife(unsigned int const id) const;
  void				moveAllEntities(bool &);
  void				removeEntities();
  void				actionEntities();
  void				lostLifePlayer() const;
  void				endLoop();
};

#endif
