//
// InformationHitbox.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Nov 12 18:36:32 2013 laurent ansel
// Last update Fri Nov 22 10:49:05 2013 alexis mestag
//

#ifndef 			__INFORMATIONHITBOX_HH__
# define 			__INFORMATIONHITBOX_HH__

#include			<list>
#include			"Entities/Coordinate.hh"

class				InformationHitBox
{
private:
  Coordinate			*_coord;
  Coordinate			*_origCoord;
  int				_width;
  int				_height;

public:
  InformationHitBox(Coordinate const &coord, int const width, int const height);
  InformationHitBox(InformationHitBox const &other);
  virtual ~InformationHitBox();
  InformationHitBox		&operator=(InformationHitBox const &other);
  Coordinate const		&getCoordinate() const;
  Coordinate const		&getOrigCoordinate() const;
  int				getWidth() const;
  int				getHeight() const;
  void				setCoordinate(Coordinate const &coord);
  void				setWidth(int const width);
  void				setHeight(int const height);
};

#endif
