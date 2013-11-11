//
// SpriteLoader.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Sun Nov 10 15:04:52 2013 laurent ansel
// Last update Sun Nov 10 15:48:15 2013 laurent ansel
//

#include		<fstream>
#include		"SpriteLoaderManager/SpriteLoader.hh"

SpriteLoader::SpriteLoader(size_t const id, std::string const &path) :
  _id(id),
  _path(path)
{
  if (path != "")
    {
      std::ifstream	str;

      str.open(path);
      while (str.good())
	_content += str.get();
    }
}

SpriteLoader::~SpriteLoader()
{

}

size_t			SpriteLoader::getId() const
{
  return (this->_id);
}

std::string const	&SpriteLoader::getPath() const
{
  return (this->_path);
}

std::string const	&SpriteLoader::getContent() const
{
  return (this->_content);
}

void			SpriteLoader::setId(size_t const id)
{
  this->_id = id;
}

void			SpriteLoader::setPath(std::string const &path)
{
  this->_path = path;
}
