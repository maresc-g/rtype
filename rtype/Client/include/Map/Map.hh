//
// Map.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Mon Nov  4 17:30:57 2013 guillaume marescaux
// Last update Tue Nov 19 11:19:53 2013 guillaume marescaux
//

#ifndef 		__MAP_HH__
# define 		__MAP_HH__

#include		<list>
#include		"Map/Entity.hh"
#include		"Utility/Singleton.hpp"
#include		"Mutex/Mutex.hpp"

class			Map : public Singleton<Map>
{
  friend class		Singleton<Map>;

private:

  // Attributes
  std::list<Entity *>	*_map;
  std::list<Entity *>	*_entities;
  Mutex			*_mutex;
  unsigned int		_scroll;

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

  // Getters / Setters
  void			setScroll(unsigned int const scroll);
  unsigned int		getScroll(void) const;
  std::list<Entity *> const	&getMap(void) const;
  std::list<Entity *> const	&getEntities(void) const;
};

#endif
