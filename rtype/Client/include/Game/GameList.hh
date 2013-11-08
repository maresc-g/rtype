//
// GameList.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Oct 29 14:57:03 2013 guillaume marescaux
// Last update Fri Nov  8 14:27:51 2013 guillaume marescaux
//

#ifndef 		__GAMELIST_HH__
# define 		__GAMELIST_HH__

#include		<list>
#include		"GameInfo.hh"
#include		"Utility/Singleton.hpp"

class			GameList : public Singleton<GameList>
{
  friend class		Singleton<GameList>;

private:

  // Attributes
  std::list<GameInfo *>	*_games;

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
};

#endif
