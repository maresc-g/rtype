//
// SFRessourcesManager.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Tue Oct 29 13:32:32 2013 cyril jourdain
// Last update Wed Nov 20 15:35:06 2013 cyril jourdain
//

#ifndef 		__SFRESSOURCESMANAGER_HH__
# define 		__SFRESSOURCESMANAGER_HH__

#include			"Utility/Singleton.hpp"
#include			"Graphic/SFGraphics/Ressources/SFImageLoader.hh"
#include			"Graphic/SFGraphics/Ressources/SFFontLoader.hh"
#include			"Graphic/Graphics/Sprites/AnimatedSprite.hh"

class				SFRessourcesManager : public Singleton<SFRessourcesManager>
{
  friend class Singleton<SFRessourcesManager>;

private:
  SFRessourcesManager();
  virtual ~SFRessourcesManager();

public:
  static SFImageLoader		*Images;
  static SFFontLoader		*Fonts;

private:
  std::map<std::string, AnimatedSprite *>	*_sprites;

public:
  static void			loadDefaultRessources();
  void				addSprite(std::string const &name, std::string const &path);
  AnimatedSprite		*getSprite(std::string const &name) const;
};

#endif
