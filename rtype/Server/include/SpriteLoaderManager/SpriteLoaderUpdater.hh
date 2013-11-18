//
// SpriteLoaderUpdater.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Fri Nov  8 22:45:30 2013 laurent ansel
// Last update Mon Nov 18 13:10:56 2013 laurent ansel
//

#ifndef 			__SPRITELOADERUPDATER_HH__
# define 			__SPRITELOADERUPDATER_HH__

#include			<map>
#include			<list>
#include			"Entities/AEntity.hh"
#include			"Thread/Thread.hpp"
#include			"Mutex/Mutex.hpp"
#include			"SpriteLoaderManager/SpriteLoader.hh"
#include			"FileSystem/Directory.hh"
#include			"Inotify/Inotify.hpp"

class				SpriteLoaderUpdater : public Thread
{
private:
  Inotify			*_inotify;
  FileSystem::Directory		*_directory;
  std::list<SpriteLoader *>	*_sprites;
  std::map<std::string, bool>	*_confFiles;
  Mutex				&_mutex;
  bool				&_quit;
public:
  SpriteLoaderUpdater(std::list<SpriteLoader *> *sprites, Mutex &mutex, bool &quit, std::string const &path);
  virtual ~SpriteLoaderUpdater();
  void				run();
  void				destroyUpdater();
private:
  void				updateConf();
};

void				*startSpriteUpdater(void *data);

#endif
