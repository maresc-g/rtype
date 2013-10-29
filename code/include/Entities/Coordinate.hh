//
// Coordinate.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 14:12:24 2013 guillaume marescaux
// Last update Mon Oct 28 14:14:29 2013 guillaume marescaux
//

#ifndef 		__COORDINATE_HH__
# define 		__COORDINATE_HH__

class			Coordinate
{
private:

  // Attributs
  int			_x;
  int			_y;

public:

  // Ctor / Dtor
  Coordinate(int x = 0, int y = 0);
  Coordinate(Coordinate const &other);
  Coordinate		&operator=(Coordinate const &other);
  virtual ~Coordinate();

  // Getters / Setters
  int			getX(void) const;
  void			setX(int x);
  int			getY(void) const;
  void			setY(int y);
};

#endif
