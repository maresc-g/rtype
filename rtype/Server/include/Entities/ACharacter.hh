//
// ACharacter.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 14:43:43 2013 guillaume marescaux
// Last update Sat Nov 23 16:26:03 2013 antoine maitre
//

#ifndef 		__ACHARACTER_HH__
# define 		__ACHARACTER_HH__

#include		<string>
#include		"AEntity.hh"
#include		"Weapon/Weapon.hh"

class			ACharacter : public AEntity
{
protected:
  unsigned int		_life;
  int			_timeInvincible;
  Weapon		_weapon;

public:
  ACharacter(int const x, int const y, std::string const &path, int const speed, bool const destructible);
  virtual		~ACharacter();
  void			setInvincible(int time);
  int			getInvincible() const;
  void			decOffFrames();
};

#endif
