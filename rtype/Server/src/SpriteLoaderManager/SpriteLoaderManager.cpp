//
// SpriteLoaderManager.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Sun Nov 10 11:18:35 2013 laurent ansel
// Last update Wed Nov 13 10:37:03 2013 laurent ansel
//

#include			<fstream>
#include			"SpriteLoaderManager/SpriteLoaderManager.hh"

SpriteLoaderManager::SpriteLoaderManager():
  _sprites(new std::list<SpriteLoader *>),
  _mutex(new Mutex),
  _quit(false),
  _updater(new SpriteLoaderUpdater(_sprites, *_mutex, _quit, "Sprites"))
{
  this->_mutex->initialize();
  this->_updater->start();
}

SpriteLoaderManager::~SpriteLoaderManager()
{
  this->_mutex->enter();
  this->_quit = true;
  this->_mutex->leave();
  this->_updater->destroyUpdater();
  this->_updater->waitThread();
  this->_mutex->destroy();
}

std::string const		SpriteLoaderManager::getContentSprite(size_t const idSprite) const
{
  std::list<SpriteLoader *>::iterator	it;

  this->_mutex->enter();
  for (it = this->_sprites->begin() ; it != this->_sprites->end() && (*it)->getId() != idSprite ; ++it);
  if (it != this->_sprites->end())
    {
      this->_mutex->leave();
      return ((*it)->getContent());
    }
  this->_mutex->leave();
  return ("");
}

std::list<std::string> const	SpriteLoaderManager::getSpriteList() const
{
  std::list<std::string>	list;

  for (auto it = this->_sprites->begin() ; it != this->_sprites->end() ; ++it)
    list.push_back((*it)->getPath());
  return (list);
}
