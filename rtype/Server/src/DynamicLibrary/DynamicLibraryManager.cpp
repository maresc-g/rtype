//
// DynamicLibraryManager.cpp for RType in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Mon Nov  4 19:51:02 2013 alexis mestag
// Last update Tue Nov  5 11:33:55 2013 alexis mestag
//

#include			"DynamicLibrary/DynamicLibraryManager.hh"

DynamicLibraryManager::DynamicLibraryManager() :
  Singleton(), _libraries(new GameLibraries)
{

}

DynamicLibraryManager::DynamicLibraryManager(DynamicLibraryManager const &rhs) :
  Singleton(), _libraries(new GameLibraries)
{
  *this = rhs;
}

DynamicLibraryManager::~DynamicLibraryManager()
{
  delete _libraries;
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
  return (_libraries->getDeepCopy());
}
