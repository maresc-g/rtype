//
// Player.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 14:43:58 2013 guillaume marescaux
// Last update Tue Nov  5 10:55:52 2013 antoine maitre
//

#ifndef 		__PLAYER_HH__
# define 		__PLAYER_HH__

#include		"ACharacter.hh"

class			Player : public ACharacter
{
public:
  Player(int const x, int const y, std::string const &path, int const speed, bool const destructible);
  ~Player();
  eObject		getType() const;
};

#endif
