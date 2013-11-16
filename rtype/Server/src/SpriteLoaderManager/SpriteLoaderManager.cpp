//
// SpriteLoaderManager.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Sun Nov 10 11:18:35 2013 laurent ansel
// Last update Sat Nov 16 16:57:13 2013 laurent ansel
//

#include			<sstream>
#include			<fstream>
#include			"SpriteLoaderManager/SpriteLoaderManager.hh"

SpriteLoaderManager::SpriteLoaderManager():
  _sprites(new std::list<SpriteLoader *>),
  _update(new std::list<SpriteLoader *>),
  _mutex(new Mutex),
  _quit(false),
  _updater(new SpriteLoaderUpdater(_sprites, _update, *_mutex, _quit, "Res/Sprites"))
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
  for (auto it = _sprites->begin() ; it != _sprites->end() ; ++it)
    if ((*it))
      delete *it;
  delete _sprites;
  delete _update;
  delete _updater;
  delete _mutex;
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

std::string const		SpriteLoaderManager::getSprite(std::string const &sprite) const
{
  std::list<SpriteLoader *>::iterator	it;
  std::ostringstream		str;

  this->_mutex->enter();
  for (it = this->_sprites->begin() ; it != this->_sprites->end() && (*it)->getPath() != sprite ; ++it);
  if (it != this->_sprites->end())
    {
      str << sprite << ";" << (*it)->getContent();
      this->_mutex->leave();
      return (str.str());
    }
  this->_mutex->leave();
  return ("");
}

std::string const		SpriteLoaderManager::getConfSprite(std::string const &name)
{
  std::list<SpriteLoader *>::iterator	it;
  std::ostringstream		str;

  this->_mutex->enter();
  for (it = this->_sprites->begin() ; it != this->_sprites->end() && (*it)->getPath() != name ; ++it);
  if (it != this->_sprites->end())
    {
      str << (*it)->getNameConfClient() << ";" << (*it)->getContentConfClient();
      this->_mutex->leave();
      return (str.str());
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

bool				SpriteLoaderManager::isUpdate() const
{
  this->_mutex->enter();
  if (this->_update->size() > 0)
    {
      this->_mutex->leave();
      return (true);
    }
  this->_mutex->leave();
  return (false);
}

std::list<std::string> const	SpriteLoaderManager::getSpriteUpdate() const
{
  std::list<std::string>	list;
  std::ostringstream		str;

  this->_mutex->enter();
  for (auto it = this->_update->begin() ; it != this->_update->end() ; ++it)
    {
      str << (*it)->getPath() << ";" << (*it)->getContent();
      list.push_back(str.str());
      str.str("");
    }
  this->_mutex->leave();
  return (list);
}

std::list<std::string> const	SpriteLoaderManager::getConfClientUpdate() const
{
  std::list<std::string>	list;
  std::ostringstream		str;

  this->_mutex->enter();
  for (auto it = this->_update->begin() ; it != this->_update->end() ; ++it)
    {
      str << (*it)->getNameConfClient() << ";" << (*it)->getContentConfClient();
      list.push_back(str.str());
      str.str("");
    }
  this->_mutex->leave();
  return (list);
}

void				SpriteLoaderManager::alreadyUpdate()
{
  this->_mutex->enter();
  this->_update->clear();
  this->_mutex->leave();
}
