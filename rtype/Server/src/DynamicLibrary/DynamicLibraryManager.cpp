//
// DynamicLibraryManager.cpp for RType in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Mon Nov  4 19:51:02 2013 alexis mestag
// Last update Tue Nov 12 17:55:47 2013 alexis mestag
//

#include			"DynamicLibrary/DynamicLibraryManager.hh"

DynamicLibraryManager::DynamicLibraryManager() :
  Singleton(), _libraries(new GameLibraries), _mtx(new Mutex)
{
  this->_mtx->initialize();
}

DynamicLibraryManager::DynamicLibraryManager(DynamicLibraryManager const &rhs) :
  Singleton(), _libraries(new GameLibraries), _mtx(new Mutex)
{
  this->_mtx->initialize();
  *this = rhs;
}

DynamicLibraryManager::~DynamicLibraryManager()
{
  delete _libraries;
  _mtx->destroy();
  delete _mtx;
}

DynamicLibraryManager		&DynamicLibraryManager::operator=(DynamicLibraryManager const &rhs)
{
  if (this != &rhs)
    {
    }
  return (*this);
}

GameLibraries			&DynamicLibraryManager::getGameLibrariesCopy() const
{
  GameLibraries			*ret;

  _mtx->enter();
  ret = &_libraries->getDeepCopy();
  _mtx->leave();
  return (*ret);
}

void				DynamicLibraryManager::setLibrary(IDynamicLibrary &lib)
{
  _mtx->enter();
  _libraries->setLibrary(lib);
  _mtx->leave();
}
