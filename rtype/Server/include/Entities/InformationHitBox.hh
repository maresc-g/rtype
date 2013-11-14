//
// InformationHitbox.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Nov 12 18:36:32 2013 laurent ansel
// Last update Wed Nov 13 16:42:49 2013 laurent ansel
//

#ifndef 			__INFORMATIONHITBOX_HH__
# define 			__INFORMATIONHITBOX_HH__

#include			<list>
#include			"Entities/Coordinate.hh"

class				InformationHitBox
{
private:
  Coordinate			*_coord;
  int				_width;
  int				_height;
public:
  InformationHitBox(Coordinate const &coord, int const width, int const height);
  InformationHitBox(InformationHitBox const &other);
  virtual ~InformationHitBox();
  InformationHitBox		&operator=(InformationHitBox const &other);
  Coordinate const		&getCoordinate() const;
  int				getWidth() const;
  int				getHeight() const;
  void				setCoordinate(Coordinate const &coord);
  void				setWidth(int const width);
  void				setHeight(int const height);
};

#endif
