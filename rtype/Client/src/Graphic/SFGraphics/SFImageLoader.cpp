//
// SFImageLoader.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Nov  6 13:31:55 2013 cyril jourdain
// Last update Fri Nov 22 15:18:51 2013 cyril jourdain
//

#include		"Graphic/SFGraphics/Ressources/SFImageLoader.hh"

SFImageLoader::SFImageLoader()
{
}

SFImageLoader::~SFImageLoader()
{
  // Delete stuff
}

sf::Texture		*SFImageLoader::operator[](std::string const &index)
{
  if (_images[index])
    return (_images[index]);
  else
    return NULL;
}

void			SFImageLoader::loadImage(std::string const &path,
						 std::string const &name)
{
  if (!(_images)[name])
    {
      (_images)[name] = new sf::Texture();
      ((_images)[name])->loadFromFile(path);
    }
  else
    return;
}
