//
// WindowsDynamicLibrary.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Nov  4 10:20:55 2013 laurent ansel
// Last update Mon Nov  4 10:21:12 2013 laurent ansel
//

#include		<iostream>
#include		"DynamicLibrary/WindowsDynamicLibrary.hh"

#ifdef _WIN32

WindowsDynamicLibrary::WindowsDynamicLibrary() :
  _path(""), _lib(NULL)
{
}

WindowsDynamicLibrary::WindowsDynamicLibrary(std::string const &path) :
  _path(path)
{

}

WindowsDynamicLibrary::WindowsDynamicLibrary(WindowsDynamicLibrary const &rhs)
{
  *this = rhs;
}

WindowsDynamicLibrary::~WindowsDynamicLibrary()
{
  if (_lib)
    this->destroy();
}

WindowsDynamicLibrary	&WindowsDynamicLibrary::operator=(WindowsDynamicLibrary const &rhs)
{
  if (this != &rhs)
    {

    }
  return (*this);
}

bool		WindowsDynamicLibrary::load()
{
  bool	ret = true;
  _lib = LoadLibrary(_path.c_str());
  if (!_lib) {
    std::cerr << GetLastError() << std::endl;
    ret = false;
  }
  return (ret);
}

void		WindowsDynamicLibrary::destroy()
{
  FreeLibrary(_lib);
  _lib = NULL;
}

void		*WindowsDynamicLibrary::getSymbol(std::string const &sym)
{
  void	*symbol;

  symbol = GetProcAddress(_lib, sym.c_str());
  if (!symbol) {
    std::cerr << GetLastError() << std::endl;
  }
  return (symbol);
}

#endif
