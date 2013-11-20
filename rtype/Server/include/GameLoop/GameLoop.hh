//
// GameLoop.hh for rtype in /home/maitre_c/work/local/rtype/code/include/GameLoop
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:41:34 2013 antoine maitre
// Last update Wed Nov 20 16:49:39 2013 antoine maitre
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
  bool				_criticalError;
  Mutex				*_mutex;
public:
  GameLoop(std::string const &name, unsigned int const id);
  virtual ~GameLoop();
private:
  void				sendScreen(std::list<AEntity *> &list);
  void				spawnMob();
  void				destroyDeadEntities(std::list<AEntity *> &enemies, std::list<AEntity *> &players);
public:
  void				sendDeadEntity(unsigned int);
  void				sendScroll(unsigned int scroll);
  void				sendClient(const std::string &, const std::string &);
  void				sendEntity(AEntity *);
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
};

#endif
