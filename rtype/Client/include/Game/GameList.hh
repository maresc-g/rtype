//
// GameList.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Oct 29 14:57:03 2013 guillaume marescaux
// Last update Tue Oct 29 15:33:33 2013 guillaume marescaux
//

#ifndef 		__GAMELIST_HH__
# define 		__GAMELIST_HH__

#include		<list>
#include		"GameInfo.hh"

class			GameList
{
private:

  // Attributes
  std::list<GameInfo *>	*_games;

public:

  // Ctor / Dtor
  GameList();
  GameList(GameList const &other);
  GameList		&operator=(GameList const &other);
  virtual ~GameList();

  // Methods
  void			addGame(GameInfo *gameInfo);
};

#endif
