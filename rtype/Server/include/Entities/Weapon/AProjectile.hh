//
// AProjectile.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Oct 28 14:46:24 2013 guillaume marescaux
// Last update Mon Nov 18 10:29:28 2013 antoine maitre
//

#ifndef 		__APROJECTILE_HH__
# define 		__APROJECTILE_HH__

#include		"Entities/AEntity.hh"


class			AProjectile : public AEntity
{
public:
  enum			eProjec
    {
      ROCKET
    };
protected:
  int			_vx;
  int			_vy;
  int			_id;
public:
  AProjectile(int const x, int const y, std::string const &path, int const speed, bool const destructible, int const vx, int const vy);
  ~AProjectile();
  void			move();
  AEntity::eObject	getType() const;
};

#endif
