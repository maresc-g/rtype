//
// Coordinate.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 14:12:24 2013 guillaume marescaux
// Last update Tue Oct 29 14:41:42 2013 alexis mestag
//

#ifndef 		__COORDINATE_HH__
# define 		__COORDINATE_HH__

class			Coordinate
{
private:
  int			_x;
  int			_y;

public:
  Coordinate(int const x = 0, int const y = 0);
  Coordinate(Coordinate const &other);
  Coordinate		&operator=(Coordinate const &other);
  virtual ~Coordinate();

  int			getX(void) const;
  void			setX(int const x);
  int			getY(void) const;
  void			setY(int const y);
};

#endif
