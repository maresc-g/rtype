//
// DynamicLibraryUpdater.cpp for RType in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Mon Nov  4 20:05:50 2013 alexis mestag
// Last update Tue Nov 12 19:51:16 2013 alexis mestag
//

#include			<unistd.h>
#include			<iostream>
#include			"DynamicLibrary/DynamicLibraryManager.hh"
#include			"DynamicLibrary/DynamicLibraryUpdater.hh"
#include			"DynamicLibrary/DynamicLibrary.hh"

static void			*run(void *data)
{
  DynamicLibraryUpdater		*dlu;
  int				i;

  std::cout << "COUCOU :D" << std::endl;
  dlu = reinterpret_cast<DynamicLibraryUpdater *>(data);
  i = 0;
  while (i < 10)
    {
      // sleep(dlu->getTimer());
      dlu->getInotify().waitEvent(dlu->getDirectory().getPath());
      std::cout << "The directory '" << dlu->getDirectory().getPath()
		<< "' has been modified" << std::endl;
      dlu->updateLibraries();
      i++;
    }
  return (NULL);
}

DynamicLibraryUpdater::DynamicLibraryUpdater(unsigned int const sec, std::string const &path) :
  Thread(), _timer(sec), _directory(new FileSystem::Directory(path)), _inotify(new Inotify)
{

}

DynamicLibraryUpdater::~DynamicLibraryUpdater()
{
  delete _directory;
  _inotify->destroyInotify();
  delete _inotify;
}

void				DynamicLibraryUpdater::startUpdate()
{
  _inotify->initInotify();
  _inotify->addWatch(_directory->getPath(), IInotify::ALL_EVENT);
  this->createThread(&run, this);
  this->start();
}

void				DynamicLibraryUpdater::updateLibraries()
{
  DynamicLibraryManager		*dlm = DynamicLibraryManager::getInstance();
  DynamicLibrary		*lib;
  std::list<FileSystem::Entry *> const	*entries;

  _directory->updateEntries();
  entries = &_directory->getEntries();
  for (auto it = entries->cbegin() ; it != entries->cend() ; ++it)
    {
      if ((*it)->getType() == FileSystem::FILE
	  /* && filename matches pattern ? */)
	{
	  lib = new DynamicLibrary((*it)->getPath());
	  dlm->setLibrary(*lib);
	  std::cout << "\t - " << (*it)->getPath() << std::endl;
	}
    }
}

FileSystem::Directory const	&DynamicLibraryUpdater::getDirectory() const
{
  return (*_directory);
}

unsigned int			DynamicLibraryUpdater::getTimer() const
{
  return (_timer);
}

void				DynamicLibraryUpdater::setTimer(unsigned int const timer)
{
  _timer = timer;
}

Inotify				&DynamicLibraryUpdater::getInotify()
{
  return (*_inotify);
}
