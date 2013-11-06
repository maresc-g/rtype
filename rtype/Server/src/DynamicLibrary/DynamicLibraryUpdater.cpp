//
// DynamicLibraryUpdater.cpp for RType in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Mon Nov  4 20:05:50 2013 alexis mestag
// Last update Tue Nov  5 21:52:45 2013 alexis mestag
//

#ifndef _WIN32
#include			<unistd.h>
#else
#include			<Windows.h>
#endif
#include			<iostream>
#include			"DynamicLibrary/DynamicLibraryUpdater.hh"

static void			*run(void *data)
{
  DynamicLibraryUpdater		*dlu;
  int				i;

  std::cout << "COUCOU :D" << std::endl;
  dlu = reinterpret_cast<DynamicLibraryUpdater *>(data);
  i = 0;
  while (i < 5)
    {
#ifndef _WIN32
		sleep(dlu->getTimer());
#else
		Sleep(dlu->getTimer());
#endif
      std::cout << "Coucou, I'm watching the '" << dlu->getDirectory().getPath() << "' directory"
		<< std::endl;
      dlu->updateLibraries();
      i++;
    }
  return (NULL);
}

DynamicLibraryUpdater::DynamicLibraryUpdater(unsigned int const sec, std::string const &path) :
  Thread(), _timer(sec), _directory(new FileSystem::Directory(path))
{

}

DynamicLibraryUpdater::~DynamicLibraryUpdater()
{
  delete _directory;
}

void				DynamicLibraryUpdater::startUpdate()
{
  this->createThread(&run, this);
  this->start();
}

void				DynamicLibraryUpdater::updateLibraries()
{
  std::list<FileSystem::Entry *> const	*entries;

  _directory->updateEntries();
  entries = &_directory->getEntries();
  for (auto it = entries->cbegin() ; it != entries->cend() ; ++it)
    {
      std::cout << "\t - " << (*it)->getPath() << std::endl;
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
