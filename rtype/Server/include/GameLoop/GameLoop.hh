//
// GameLoop.hh for rtype in /home/maitre_c/work/local/rtype/code/include/GameLoop
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:41:34 2013 antoine maitre
// Last update Tue Nov 19 11:17:50 2013 arthur rucquois
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
  LevelManager			*_levelManag;
  std::list<PlayerInfo *>	*_clients;
  int				_rate;
  std::string			_name;
  unsigned int			_id;
  Mutex				*_mutex;
public:
  GameLoop(std::string const &name, unsigned int const id);
  virtual ~GameLoop();
private:
  void				recupScreen();
  void				spawnMob();
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
};

#endif
