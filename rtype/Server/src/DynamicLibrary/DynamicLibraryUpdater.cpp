//
// DynamicLibraryUpdater.cpp for RType in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Mon Nov  4 20:05:50 2013 alexis mestag
// Last update Wed Nov 13 13:37:39 2013 alexis mestag
//

#include			<unistd.h>
#include			<iostream>
#include			"DynamicLibrary/DynamicLibraryManager.hh"
#include			"DynamicLibrary/DynamicLibraryUpdater.hh"
#include			"DynamicLibrary/DynamicLibrary.hh"

static void			*run(void *data)
{
  DynamicLibraryUpdater		*dlu;

  dlu = reinterpret_cast<DynamicLibraryUpdater *>(data);
  do
    {
      std::cout << "The directory '" << dlu->getDirectory().getPath()
		<< "' has been modified" << std::endl;
      dlu->updateLibraries();
      dlu->getInotify().waitEvent(dlu->getDirectory().getPath());
      std::cout << "Thread : event received !" << std::endl;
    } while (dlu->getCanUpdate());
  return (NULL);
}

DynamicLibraryUpdater::DynamicLibraryUpdater(std::string const &path) :
  Thread(), _directory(new FileSystem::Directory(path)), _inotify(new Inotify),
  _mtx(new Mutex), _canUpdate(false)
{
  _mtx->initialize();
}

DynamicLibraryUpdater::~DynamicLibraryUpdater()
{
  delete _directory;
  _inotify->destroyInotify();
  delete _inotify;
  _mtx->destroy();
  delete _mtx;
}

void				DynamicLibraryUpdater::startUpdate()
{
  _inotify->initInotify();
  _inotify->addWatch(_directory->getPath(), IInotify::ALL_EVENT);
  this->setCanUpdate(true);
  this->createThread(&run, this);
  this->start();
}

void				DynamicLibraryUpdater::stopUpdate()
{
  this->setCanUpdate(false);
  _inotify->rmWatch(_directory->getPath());
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

Inotify				&DynamicLibraryUpdater::getInotify()
{
  return (*_inotify);
}

void				DynamicLibraryUpdater::setCanUpdate(bool const canUpdate)
{
  _mtx->enter();
  std::cout << "Mutex locked for setter" << std::endl;
  _canUpdate = canUpdate;
  _mtx->leave();
  std::cout << "Mutex unlocked for setter" << std::endl;
}

bool				DynamicLibraryUpdater::getCanUpdate() const
{
  bool				ret;

  _mtx->enter();
  std::cout << "Mutex locked for getter" << std::endl;
  ret = _canUpdate;
  _mtx->leave();
  std::cout << "Mutex unlocked for getter" << std::endl;
  return (ret);
}
