//
// SFFontLoader.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Tue Oct 29 14:18:45 2013 cyril jourdain
// Last update Wed Nov  6 14:12:49 2013 cyril jourdain
//

#include			<algorithm>
#include			"Graphic/SFGraphics/Ressources/SFFontLoader.hh"

SFFontLoader::SFFontLoader() :
  _fontMap(new std::map<std::string, sf::Font>)
{
}

SFFontLoader::~SFFontLoader()
{
  if (_fontMap)
    delete _fontMap;
}

void				SFFontLoader::loadFont(std::string const &path,
						       std::string const &name)
{
  (*_fontMap)[name].loadFromFile(path);
}

sf::Font			&SFFontLoader::getFont(std::string const &name) const
{
  return (*_fontMap)[name];
}
