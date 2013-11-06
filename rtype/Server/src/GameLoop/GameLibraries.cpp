//
// GameLibraries.cpp for RType in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Mon Nov  4 20:18:29 2013 alexis mestag
// Last update Tue Nov  5 13:29:06 2013 alexis mestag
//

#include			"GameLoop/GameLibraries.hh"

GameLibraries::GameLibraries() :
  _libraries(new std::map<std::string, IDynamicLibrary *>)
{

}

GameLibraries::GameLibraries(GameLibraries const &rhs) :
  _libraries(NULL)
{
  *this = rhs;
}

GameLibraries::~GameLibraries()
{
  if (_libraries)
    this->destroyLibraries();
}

GameLibraries			&GameLibraries::operator=(GameLibraries const &rhs)
{
  if (this != &rhs)
    this->setLibrariesFromDeepCopy(rhs.getLibrariesDeepCopy());
  return (*this);
}

IDynamicLibrary			&GameLibraries::operator[](std::string const &lib)
{
  return (this->getLibrary(lib));
}

void				GameLibraries::destroyLibraries()
{
  for (auto it = _libraries->begin() ; it != _libraries->end() ; ++it)
    delete it->second;
  delete _libraries;
  _libraries = NULL;
}

void				GameLibraries::addLibrary(IDynamicLibrary &lib)
{
  (*_libraries)[lib.getPath()] = &lib;
}

IDynamicLibrary			&GameLibraries::getLibrary(std::string const &lib)
{
  return (*(*_libraries)[lib]);
}

void				GameLibraries::setLibrariesFromDeepCopy(std::map<std::string, IDynamicLibrary *> &libraries)
{
  if (_libraries)
    this->destroyLibraries();
  _libraries = &libraries;
}

std::map<std::string, IDynamicLibrary *>	&GameLibraries::getLibrariesDeepCopy() const
{
  std::map<std::string, IDynamicLibrary *>	&ref = *_libraries;
  std::map<std::string, IDynamicLibrary *>	*ret;

  ret = new std::map<std::string, IDynamicLibrary *>;
  for (auto it = ref.begin() ; it != ref.end() ; ++it)
    {
      (*ret)[it->first] = &it->second->getDeepCopy();
    }
  return (*ret);
}

GameLibraries			&GameLibraries::getDeepCopy() const
{
  return (*new GameLibraries(*this));
}
