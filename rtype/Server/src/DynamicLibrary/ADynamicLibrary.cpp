//
// ADynamicLibrary.cpp for RType in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Mon Nov  4 21:23:06 2013 alexis mestag
// Last update Mon Nov  4 21:28:40 2013 alexis mestag
//

#include			"DynamicLibrary/ADynamicLibrary.hh"

ADynamicLibrary::ADynamicLibrary() :
  _path("")
{
  
}

ADynamicLibrary::ADynamicLibrary(std::string const &path) :
  _path(path)
{

}

ADynamicLibrary::ADynamicLibrary(ADynamicLibrary const &rhs)
{
  *this = rhs;
}

ADynamicLibrary::~ADynamicLibrary()
{

}

ADynamicLibrary			&ADynamicLibrary::operator=(ADynamicLibrary const &rhs)
{
  if (this != &rhs)
    {
      this->setPath(rhs.getPath());
    }
  return (*this);
}

std::string const		&ADynamicLibrary::getPath() const
{
  return (_path);
}

void				ADynamicLibrary::setPath(std::string const &path)
{
  _path = path;
}
