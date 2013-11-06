//
// GameLoop.hh for rtype in /home/maitre_c/work/local/rtype/code/include/GameLoop
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:41:34 2013 antoine maitre
// Last update Wed Nov  6 14:27:32 2013 antoine maitre
//

#ifndef	__GAMELOOP_HH__
#define __GAMELOOP_HH__

#ifndef _WIN32
#include <unistd.h>
#else
#define _WINSOCKAPI_ 
#include	<Windows.h>
#endif
#include	"ClientInfo/ClientInfo.hh"
#include	"Level/LevelManager.hh"
#include	"GameLoop/PlayerInfo.hh"

class	GameLoop
{
  LevelManager *_levelManag;
  std::list<PlayerInfo *> _clients;
public:
  GameLoop();
  virtual ~GameLoop();
  void	loop();
  void	recupScreen();
  void	newPlayer();
  void	deadPlayer();
  void	Initialize(ClientInfo *client);
  void	spawnMob();
  unsigned int		getId() const;
  std::string		getName() const;
  unsigned int		getNumPlayer() const;
  bool			setPlayer(ClientInfo *client);
  void			quitGame();
  bool			deletePlayer(ClientInfo *client);
  unsigned int		getLevel() const;
 //  void	execCommand(Command* command);
};

#endif
