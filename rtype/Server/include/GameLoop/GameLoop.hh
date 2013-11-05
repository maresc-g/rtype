//
// GameLoop.hh for rtype in /home/maitre_c/work/local/rtype/code/include/GameLoop
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:41:34 2013 antoine maitre
// Last update Tue Nov  5 11:43:09 2013 antoine maitre
//

#ifndef	__GAMELOOP_HH__
#define __GAMELOOP_HH__

#include <unistd.h>
#include "Level/LevelManager.hh"
#include "ClientInfo/ClientInfo.hh"

class	GameLoop
{
  LevelManager *_levelManag;
  int _currentScreen;
public:
  GameLoop();
  virtual ~GameLoop();
  void	loop();
  void	recupScreen();
  void	newPlayer();
  void	deadPlayer();
  void	Initialize();
  void	spawnMob();
  //  void	execCommand(Command* command);
};

#endif
