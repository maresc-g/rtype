//
// SFFontLoader.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Tue Oct 29 13:56:05 2013 cyril jourdain
// Last update Wed Nov  6 13:23:36 2013 cyril jourdain
//

#include			<SFML/Graphics.hpp>
#include			<map>
#include			<memory>
#include			<iostream>
#include			"Utility/Singleton.hpp"

class				SFFontLoader : public Singleton<SFFontLoader>
{
  friend class Singleton<SFFontLoader>;

private:
  std::map<std::string, sf::Font>	*_fontMap;

public:
  void			loadFont(std::string const &path, std::string const &name);
  sf::Font		&getFont(std::string const &name) const;

private:
  SFFontLoader();
  virtual ~SFFontLoader();

};
