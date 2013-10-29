//
// AEntity.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 13:57:25 2013 guillaume marescaux
// Last update Mon Oct 28 14:24:51 2013 guillaume marescaux
//

#ifndef 		__AENTITY_HH__
# define 		__AENTITY_HH__

#include		<string>
#include		"Coordinate.hh"

class			AEntity
{
private:

  // Attributs
  Coordinate		*_coord;
  std::string		_path;
  int			_speed;
  bool			_destructible;

public:

  // Ctor / Dtor
};

#endif
