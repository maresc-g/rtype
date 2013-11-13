//
// AEntity.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 13:57:25 2013 guillaume marescaux
// Last update Wed Nov 13 16:28:55 2013 laurent ansel
//

#ifndef 		__AENTITY_HH__
# define 		__AENTITY_HH__

#include		<string>
#include		"Coordinate.hh"
#include		"Entities/InformationHitBox.hh"

class			AEntity
{
public:
  enum			eObject
    {
      ROCKET,
      PLAYER,
      MOB
    };

protected:
  unsigned int		_id;
  int			_l;
  int			_L;
  Coordinate		*_coord;
  std::string		_path;
  int			_speed;
  bool			_destructible;
  bool			_dead;
  std::list<InformationHitBox *>	*_hitbox;
  AEntity();
public:
  AEntity(int const x = 0, int const y = 0, std::string const &path = "", int const speed = 50, bool const destructible = false);
  AEntity(AEntity const &rhs);
  virtual ~AEntity();

  AEntity		&operator=(AEntity const &rhs);

  void			collision();
  bool			checkCollision(AEntity const &other) const;

  void			move(int const x, int const y);
  Coordinate const	*getCoord() const;

  std::string const	&getPath() const;
  void			setPath(std::string const &path);

  int			getSpeed() const;
  void			setSpeed(int const speed);

  bool			getDestructible() const;
  void			setDestructible(bool const &destructible);
  int			getLargeur() const;
  int			getLongueur() const;

  std::list<InformationHitBox *> const	&getInformationHitBox() const;
  void			setInformationHitBox(std::list<InformationHitBox *> *list);

  unsigned int		getId() const;
  bool			isDead() const;
};

#endif
