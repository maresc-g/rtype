//
// Map.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Nov  4 17:30:57 2013 guillaume marescaux
// Last update Wed Nov  6 16:31:24 2013 guillaume marescaux
//

#ifndef 		__MAP_HH__
# define 		__MAP_HH__

#include		<list>
#include		"Map/Entity.hh"
#include		"Utility/Singleton.hpp"

class			Map : public Singleton<Map>
{
  friend class		Singleton<Map>;

private:

  // Attributes
  std::list<Entity *>	*_map;

private:

  // Ctor / Dtor
  Map();
  Map(Map const &);
  Map			&operator=(Map const &);
  virtual ~Map();

public:

  // Methods
  void			moveEntity(int const id, int const x, int const y);
  void			addEntity(Entity *entity);
  void			removeEntity(int const id);
  void			clear();
  bool			exists(int const id) const;
  void			addDecor(Entity *entity);
};

#endif
