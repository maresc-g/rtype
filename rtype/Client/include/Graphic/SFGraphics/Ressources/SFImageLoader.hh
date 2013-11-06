//
// ImageLoader.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Oct 26 18:22:00 2013 cyril jourdain
// Last update Wed Nov  6 13:23:46 2013 cyril jourdain
//

#ifndef 		__SFIMAGELOADER_HH__
# define 		__SFIMAGELOADER_HH__

#include		<map>
#include		<iostream>
#include		<SFML/Graphics.hpp>
#include		<SFML/System.hpp>
#include		"Utility/Singleton.hpp"

class			SFImageLoader : public Singleton<SFImageLoader>
{
  friend class Singleton<SFImageLoader>;

private:
  std::map<std::string, sf::Texture *>	_images;

private:
  SFImageLoader();
  virtual ~SFImageLoader();

public:
  sf::Texture	*operator[](std::string const &index);

public:
  void		loadImage(std::string const &path, std::string const &name);

};

#endif
