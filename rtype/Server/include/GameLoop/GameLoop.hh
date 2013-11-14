//
// GameLoop.hh for rtype in /home/maitre_c/work/local/rtype/code/include/GameLoop
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:41:34 2013 antoine maitre
// Last update Thu Nov 14 12:08:36 2013 arthur rucquois
//

#ifndef	__GAMELOOP_HH__
#define __GAMELOOP_HH__

#ifndef		_WIN32
#include		<unistd.h>
#else
#define		_WINSOCKAPI_ 
#include		<Windows.h>
#endif

#include		"ClientInfo/ClientInfo.hh"
#include		"Level/LevelManager.hh"
#include		"GameLoop/PlayerInfo.hh"
#include		"Thread/Thread.hpp"
#include		"Mutex/Mutex.hpp"

class			GameLoop : public Thread, public Mutex
{
private:
  LevelManager			*_levelManag;
  std::list<PlayerInfo *>	_clients;
  int				_rate;

public:
  GameLoop();
  virtual ~GameLoop();
  void				loop();
  void				recupScreen();
  void				newPlayer();
  void				deadPlayer();
  void				Initialize(ClientInfo *client);
  void				spawnMob();
  void				destroyDeadEntities(std::list<AEntity *> &enemies, std::list<AEntity *> &players);
  unsigned int			getId() const;
  std::string			getName() const;
  unsigned int			getNumPlayer() const;
  bool				setPlayer(ClientInfo *client);
  void				quitGame();
  bool				deletePlayer(ClientInfo *client);
  unsigned int			getLevel() const;
 //  void	execCommand(Command* command);
};

#endif
