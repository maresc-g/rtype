//
// GameLibraries.cpp for RType in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Mon Nov  4 20:18:29 2013 alexis mestag
// Last update Sun Nov 24 22:47:36 2013 alexis mestag
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

IDynamicLibrary			*GameLibraries::operator[](std::string const &lib)
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

IDynamicLibrary			*GameLibraries::getLibrary(std::string const &lib)
{
  auto				it = _libraries->find(lib);
  IDynamicLibrary		*ret = NULL;

  if (it != _libraries->end())
    ret = it->second;
  return (ret);
  // return ((*_libraries)[lib]);
}

void				GameLibraries::setLibrary(IDynamicLibrary &lib)
{
  std::map<std::string, IDynamicLibrary *>::const_iterator it;

  if ((it = _libraries->find(lib.getPath())) != _libraries->cend())
    {
      delete it->second;
    }
  (*_libraries)[lib.getPath()] = &lib;
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

IDynamicLibrary			*GameLibraries::getRandomLibrary()
{
  auto it = _libraries->cbegin();
  long int			size;
  long int			idx;
  long int			i;

  size = _libraries->size();
  if (!size)
    return (NULL);
  idx = rand() % size;
  i = 0;
  for (; it != _libraries->end() && i < idx ; ++it)
    i++;
  return (it != _libraries->end() ? it->second : NULL);
}

void				GameLibraries::removeLibrary(IDynamicLibrary const &lib)
{
  for (auto it = _libraries->begin() ; it != _libraries->end() ; ++it)
    {
      if (it->second->getPath() == lib.getPath()) {
	delete it->second;
	_libraries->erase(it);
	break;
      }
    }
}

Mob				*GameLibraries::getRandomInstance()
{
  IDynamicLibrary		*lib = this->getRandomLibrary();
  Mob				*(*getInstance)();
  Mob				*mob = NULL;

  if (lib)
    {
      getInstance = reinterpret_cast<Mob *(*)()>(lib->getSymbol("getInstance"));
      if (getInstance)
	mob = getInstance();
      else
	this->removeLibrary(*lib);
    }
  return (mob);
}

void				GameLibraries::deleteInstance(Mob *mob)
{
  IDynamicLibrary		*lib = this->getLibrary("Libraries/" +
							mob->getName() +
							#ifdef _WIN32
							".dll"
							#else
							".so"
							#endif
							);
  void				(*deleteInstance)(void *);

  if (lib)
    {
      deleteInstance = reinterpret_cast<void (*)(void *)>(lib->getSymbol("deleteInstance"));
      if (deleteInstance)
	deleteInstance(mob);
    }
}

void				GameLibraries::loadLibraries()
{
  bool				ok;

  for (auto it = _libraries->begin() ; it != _libraries->end() ; ++it)
    {
      ok = (it->second)->load();
      if (!ok)
	{
	  delete it->second;
	  it = _libraries->erase(it);
	  if (!_libraries->empty())
	    --it;
	}
    }
}

void				GameLibraries::clear()
{
  for (auto it = _libraries->begin() ; it != _libraries->end() ; ++it)
    {
      delete it->second;
    }
  _libraries->clear();
}
