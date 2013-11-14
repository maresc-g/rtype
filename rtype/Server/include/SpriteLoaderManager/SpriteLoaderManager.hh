//
// SpriteLoaderManager.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Fri Nov  8 22:44:27 2013 laurent ansel
// Last update Wed Nov 13 13:43:37 2013 laurent ansel
//

#ifndef 			__SPRITELOADERMANAGER_HH__
# define 			__SPRITELOADERMANAGER_HH__

#include			<list>
#include			"Thread/Thread.hpp"
#include			"Utility/Singleton.hpp"
#include			"Mutex/Mutex.hpp"
#include			"SpriteLoaderManager/SpriteLoaderUpdater.hh"

class				SpriteLoaderManager : public Singleton<SpriteLoaderManager>
{
  friend class			Singleton<SpriteLoaderManager>;

private:
  std::list<SpriteLoader *>	*_sprites;
  Mutex				*_mutex;
  bool				_quit;
  SpriteLoaderUpdater		*_updater;
  SpriteLoaderManager();
  virtual ~SpriteLoaderManager();
public:
  std::string const		getContentSprite(size_t const idSprite) const;
  std::list<std::string> const	getSpriteList() const;
};

#endif
