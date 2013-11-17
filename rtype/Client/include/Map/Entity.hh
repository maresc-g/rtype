//
// Entity.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Nov  4 17:07:33 2013 guillaume marescaux
// Last update Mon Nov 11 14:37:32 2013 guillaume marescaux
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

  enum			eDirection
    {
      LEFT,
      RIGHT,
      UP,
      DOWN,
      LEFT_UP,
      LEFT_DOWN,
      RIGHT_UP,
      RIGHT_DOWN
    };

private:

  // Attributes
  int			_id;
  int			_x;
  int			_y;
  eEntity		_type;
  eDirection		_direction;

public:

  // Ctor / Dtor
  Entity(int const id = 0, int const x = 0, int const y = 0, eEntity const type = END, eDirection const direction = LEFT);
  Entity(Entity const &other);
  Entity		&operator=(Entity const &other);
  virtual ~Entity();

  // Getters / Setters
  int			getId(void) const;
  int			getX(void) const;
  int			getY(void) const;
  eEntity		getType(void) const;
  eDirection		getDirection(void) const;
  void			setId(int const id);
  void			setX(int const x);
  void			setY(int const y);
  void			setType(eEntity const type);
  void			setDirection(eDirection const direction);
};

#endif
