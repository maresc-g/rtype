//
// SpriteLoaderManager.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Fri Nov  8 22:44:27 2013 laurent ansel
// Last update Sat Nov 16 11:54:23 2013 laurent ansel
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
  std::list<SpriteLoader *>	*_update;
  Mutex				*_mutex;
  bool				_quit;
  SpriteLoaderUpdater		*_updater;
  SpriteLoaderManager();
  virtual ~SpriteLoaderManager();
public:
  std::string const		getContentSprite(size_t const idSprite) const;
  std::string const		getSprite(std::string const &sprite) const;
  std::string const		getConfSprite(std::string const &name);
  std::list<std::string> const	getSpriteList() const;
  std::list<std::string> const	getSpriteUpdate() const;
  std::list<std::string> const	getConfClientUpdate() const;
  bool				isUpdate() const;
  void				alreadyUpdate();
};

#endif
