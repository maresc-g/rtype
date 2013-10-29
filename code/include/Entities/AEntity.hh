//
// AEntity.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 13:57:25 2013 guillaume marescaux
// Last update Tue Oct 29 15:16:57 2013 alexis mestag
//

#ifndef 		__AENTITY_HH__
# define 		__AENTITY_HH__

#include		<string>
#include		"Coordinate.hh"

class			AEntity
{
private:
  Coordinate		*_coord;
  std::string		_path;
  int			_speed;
  bool			_destructible;

protected:
  AEntity();
public:
  AEntity(int const x, int const y, std::string const &path, int const speed, bool const destructible);
  AEntity(AEntity const &rhs);
  virtual ~AEntity();

  AEntity		&operator=(AEntity const &rhs);

  bool			checkCollision(AEntity const &other) const;

  void			move(int const x, int const y);
  Coordinate const	*getCoord() const;

  std::string const	&getPath() const;
  void			setPath(std::string const &path);

  int			getSpeed() const;
  void			setSpeed(int const speed);

  bool			getDestructible() const;
  void			setDestructible(bool const &destructible);
};

#endif
