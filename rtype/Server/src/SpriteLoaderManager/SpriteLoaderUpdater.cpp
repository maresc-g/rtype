//
// SpriteLoaderUpdater.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Sun Nov 10 11:40:04 2013 laurent ansel
// Last update Thu Nov 14 23:53:14 2013 laurent ansel
//

#include			<list>
#include			<iostream>
#include			<algorithm>
#include			"SpriteLoaderManager/SpriteLoaderUpdater.hh"

SpriteLoaderUpdater::SpriteLoaderUpdater(std::list<SpriteLoader *> *sprites, std::list <SpriteLoader *> *update, Mutex &mutex, bool &quit, std::string const &path) :
  Thread(),
  _inotify(new Inotify),
  _directory(new FileSystem::Directory(path)),
  _sprites(sprites),
  _update(update),
  _confFiles(new std::map<std::string, bool>),
  _mutex(mutex),
  _quit(quit)
{
  this->_inotify->initInotify();
  this->_inotify->addWatch(path, IInotify::ALL_EVENT);
  this->createThread(&startSpriteUpdater, this);
}

SpriteLoaderUpdater::~SpriteLoaderUpdater()
{
  this->_inotify->destroyInotify();
  delete _inotify;
  delete this->_directory;
  delete this->_confFiles;
}

void				SpriteLoaderUpdater::updateConf()
{
  size_t			pos;

  for (auto it = this->_confFiles->begin() ; it != this->_confFiles->end() ; ++it)
    {
      if (!it->second)
	{
	  this->_mutex.enter();
	  for (auto itSprite = this->_sprites->begin() ; itSprite != this->_sprites->end() ; ++itSprite)
	    {
	      if ((pos = (*itSprite)->getPath().rfind(".")) != std::string::npos)
		{
		  if (!it->first.compare(0, it->first.size() - std::string(".confClient").size(), (*itSprite)->getPath().substr(0, pos)))
		    {
		      it->second = true;
		      (*itSprite)->setNameConfClient(it->first);
		    }
		  else if (!it->first.compare(0, it->first.size() - std::string(".conf").size(), (*itSprite)->getPath().substr(0, pos)))
		    {
		      it->second = true;
		      (*itSprite)->setConfFile(it->first);
		      break;
		    }
		}
	    }
	  this->_mutex.leave();
	}
    }
}

void				SpriteLoaderUpdater::run()
{
  std::list<FileSystem::Entry *>	list;
  std::list<SpriteLoader *>::iterator	itSprite;
  std::pair<enum IInotify::eInotify, std::string>	event;

  this->_mutex.enter();
  while (!_quit)
    {
      this->_mutex.leave();
      this->_directory->updateEntries();
      list = this->_directory->getEntries();
      for (auto it = list.begin() ; it != list.end() ; ++it)
	{
	  this->_mutex.enter();
	  for (itSprite = this->_sprites->begin() ; itSprite != this->_sprites->end() && (*itSprite)->getPath() != (*it)->getPath() ; ++itSprite);
	  if (itSprite == this->_sprites->end() && (*it)->getType() == FileSystem::FILE && ((*it)->getPath().find(".confclient") != std::string::npos || (*it)->getPath().find(".conf") != std::string::npos))
	    (*this->_confFiles)[(*it)->getPath()] = (this->_confFiles->find((*it)->getPath()) != this->_confFiles->end() && (*this->_confFiles)[(*it)->getPath()] ? true : false);
	  else if (itSprite == this->_sprites->end() && (*it)->getType() == FileSystem::FILE)
      	    this->_sprites->push_back(new SpriteLoader(this->_sprites->size(), (*it)->getPath()));
	  this->_mutex.leave();
	}
      this->updateConf();
      this->_inotify->waitEvent(this->_directory->getPath());
      event = this->_inotify->getEvent(this->_directory->getPath());
      this->_mutex.enter();
      if (event.first == IInotify::DELETEFILE)
	for (itSprite = this->_sprites->begin() ; itSprite != this->_sprites->end() ; ++itSprite)
	  if ((*itSprite)->getPath().find(event.second) != std::string::npos)
	    {
	      delete *itSprite;
	      itSprite = this->_sprites->erase(itSprite);
	      break;
	    }
    }
  this->_mutex.leave();
}

void				SpriteLoaderUpdater::destroyUpdater()
{
  this->_inotify->rmWatch(this->_directory->getPath());
}

void				*startSpriteUpdater(void *data)
{
  SpriteLoaderUpdater		*tmp = reinterpret_cast<SpriteLoaderUpdater *>(data);

  if (tmp)
    tmp->run();
  return (NULL);
}
