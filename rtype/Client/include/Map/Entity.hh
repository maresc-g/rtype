//
// Entity.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Nov  4 17:07:33 2013 guillaume marescaux
// Last update Mon Nov  4 17:24:34 2013 guillaume marescaux
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
      ENEMY
    };

private:

  // Attributes
  int			_id;
  int			_x;
  int			_y;

public:

  // Ctor / Dtor
  Entity(int const id = 0, int const x = 0, int const y = 0);
  Entity(Entity const &other);
  Entity		&operator=(Entity const &other);
  virtual ~Entity();

  // Getters / Setters
  int			getId(void) const;
  int			getX(void) const;
  int			getY(void) const;
  void			setId(int const id);
  void			setX(int const x);
  void			setY(int const y);
};

#endif
