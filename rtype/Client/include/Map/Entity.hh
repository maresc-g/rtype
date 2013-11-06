//
// Entity.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Nov  4 17:07:33 2013 guillaume marescaux
// Last update Tue Nov  5 13:21:47 2013 guillaume marescaux
//

#ifndef 		__ENTITY_HH__
# define 		__ENTITY_HH__

class			Entity
{
public:

  enum			eEntity
    {
      PLAYER1,
      PLAYER2,
      PLAYER3,
      PLAYER4,
      PROJECTILE,
      ENEMY,
      END
    };

private:

  // Attributes
  int			_id;
  int			_x;
  int			_y;
  eEntity		_type;

public:

  // Ctor / Dtor
  Entity(int const id = 0, int const x = 0, int const y = 0, eEntity const type = END);
  Entity(Entity const &other);
  Entity		&operator=(Entity const &other);
  virtual ~Entity();

  // Getters / Setters
  int			getId(void) const;
  int			getX(void) const;
  int			getY(void) const;
  eEntity		getType(void) const;
  void			setId(int const id);
  void			setX(int const x);
  void			setY(int const y);
  void			setType(eEntity const type);
};

#endif
