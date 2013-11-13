//
// GameList.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Oct 29 14:57:03 2013 guillaume marescaux
// Last update Wed Nov 13 10:15:30 2013 guillaume marescaux
//

#ifndef 		__GAMELIST_HH__
# define 		__GAMELIST_HH__

#include		<list>
#include		"GameInfo.hh"
#include		"Utility/Singleton.hpp"
#include		"Mutex/Mutex.hpp"

class			GameList : public Singleton<GameList>
{
  friend class		Singleton<GameList>;

private:

  // Attributes
  std::list<GameInfo *>	*_games;
  Mutex			*_mutex;

private:

  // Ctor / Dtor
  GameList();
  GameList(GameList const &other);
  GameList		&operator=(GameList const &other);
  virtual ~GameList();

public:

  // Methods
  void			addGame(GameInfo *gameInfo);
  void			removeGame(std::string const &id);
  void			clear();
  std::list<GameInfo *> const	&getGames(void) const;
};

#endif
