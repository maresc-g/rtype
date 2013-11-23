//
// Player.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 14:43:58 2013 guillaume marescaux
// Last update Sat Nov 23 16:25:50 2013 antoine maitre
//

#ifndef 		__PLAYER_HH__
# define 		__PLAYER_HH__

#include		"ACharacter.hh"
#include		<string>

class			Player : public ACharacter
{
private:
  int			_numPlayer;
public:
  Player(int const x, int const y, std::string const &path, int const speed, bool const destructible);
  virtual ~Player();
  AEntity::eObject	getType() const;
  void			setNum(int const num);
  int			getNum() const;
  virtual void		collision();
};

#endif
