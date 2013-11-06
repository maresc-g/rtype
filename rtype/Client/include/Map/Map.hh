//
// Map.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Nov  4 17:30:57 2013 guillaume marescaux
// Last update Tue Nov  5 14:07:34 2013 guillaume marescaux
//

#ifndef 		__MAP_HH__
# define 		__MAP_HH__

#include		<map>
#include		<list>
#include		"Map/Entity.hh"
#include		"Utility/Singleton.hpp"

class			Map : public Singleton<Map>
{
  friend class		Singleton<Map>;

public:

  enum			eMap
    {
      ENTITY,
      DECOR
    };

private:

  // Attributes
  std::map<eMap, std::list<Entity *>*>	*_map;

private:

  // Ctor / Dtor
  Map();
  Map(Map const &);
  Map			&operator=(Map const &);
  virtual ~Map();

public:

  // Methods
  void			moveEntity(int const id, int const x, int const y, eMap const type);
  void			addEntity(Entity *entity, eMap const type);
  void			removeEntity(int const id, eMap const type);
  void			clear(eMap const type);
  bool			exists(int const id, eMap const type) const;
  void			addDecor(Entity *entity);
};

#endif
