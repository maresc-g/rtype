//
// ACharacter.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 14:43:43 2013 guillaume marescaux
// Last update Mon Nov 18 10:28:33 2013 antoine maitre
//

#ifndef 		__ACHARACTER_HH__
# define 		__ACHARACTER_HH__

#include		<string>
#include		"AEntity.hh"
#include		"Weapon/Weapon.hh"

class			ACharacter : public AEntity
{
protected:
  int			_life;
  int			_timeInvincible;
  Weapon		_weapon;

public:
  ACharacter(int const x, int const y, std::string const &path, int const speed, bool const destructible);
  virtual		~ACharacter();
  void			collision();
  void			decOffFrames();
};

#endif
