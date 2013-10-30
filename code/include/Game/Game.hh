//
// Game.hh for rtype in /home/maitre_c/work/local/rtype/code/include/Game
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:41:34 2013 antoine maitre
// Last update Wed Oct 30 09:49:33 2013 antoine maitre
//

#ifndef	__GAME_HH__
#define __GAME_HH__

#include "Level/LevelManager.hh"

class	Game
{
  LevelManager *_levelManag;
public:
  Game();
  ~Game();
  void	loop();
  void	newPlayer();
  void	deadPlayer();
  //  void	execCommand(Command* command);
};

#endif
