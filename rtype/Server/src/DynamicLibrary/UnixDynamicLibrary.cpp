//
// UnixDynamicLibrary.cpp for RType in /home/mestag_a/Documents/Projets/Tek3/RType/DynamicLibrary
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Sat Nov  2 16:55:11 2013 alexis mestag
// Last update Mon Nov  4 10:21:30 2013 laurent ansel
//

#ifndef _WIN32

#include		<iostream>
#include		<dlfcn.h>
#include		"DynamicLibrary/UnixDynamicLibrary.hh"

UnixDynamicLibrary::UnixDynamicLibrary() :
  _path(""), _lib(NULL)
{

}

UnixDynamicLibrary::UnixDynamicLibrary(std::string const &path) :
  _path(path), _lib(NULL)
{

}

UnixDynamicLibrary::UnixDynamicLibrary(UnixDynamicLibrary const &rhs)
{
  *this = rhs;
}

UnixDynamicLibrary	&UnixDynamicLibrary::operator=(UnixDynamicLibrary const &rhs)
{
  if (this != &rhs)
    {
    }
  return (*this);
}

UnixDynamicLibrary::~UnixDynamicLibrary()
{
  if (_lib)
    this->destroy();
}

bool			UnixDynamicLibrary::load()
{
  bool			ret = true;

  _lib = dlopen(_path.c_str(), RTLD_LAZY);
  if (!_lib)
    {
      std::cerr << dlerror() << std::endl;
      ret = false;
    }
  return (ret);
}

void			UnixDynamicLibrary::destroy()
{
  dlclose(_lib);
  _lib = NULL;
}

void			*UnixDynamicLibrary::getSymbol(std::string const &sym)
{
  void			*symbol;

  symbol = dlsym(_lib, sym.c_str());
  if (!symbol)
    std::cerr << dlerror() << std::endl;
  return (symbol);
}

#endif
