//
// GameLoopManager.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Nov  5 10:47:42 2013 laurent ansel
// Last update Thu Nov 21 16:42:38 2013 laurent ansel
//

#ifndef 			__GAMELOOPMANAGER_HH__
# define 			__GAMELOOPMANAGER_HH__

#include			<list>
#include			"Mutex/Mutex.hpp"
#include			"Utility/Singleton.hpp"
#include			"GameLoop/GameLoop.hh"

class				GameLoopManager : public Singleton<GameLoopManager>
{
  friend class			Singleton<GameLoopManager>;

private:
  unsigned int			_idGame;
  std::list<GameLoop *>		*_listGame;
  Mutex				*_mutex;
  GameLoopManager();
  virtual ~GameLoopManager();
public:
  unsigned int			pushNewGame(std::string const &name);
  bool				runGame(unsigned int const idGame);
  std::string			listInfoGame();
  void				quitAllGame();
  bool				addPlayerInGame(ClientInfo *client, unsigned int const idGame);
  bool				deletePlayer(ClientInfo *client);
  void				quitGame(unsigned int const id);
};

void				*startGame(void *data);

#endif
