//
// SFRessourcesManager.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Tue Oct 29 13:32:32 2013 cyril jourdain
// Last update Wed Nov  6 14:11:03 2013 cyril jourdain
//

#ifndef 		__SFRESSOURCESMANAGER_HH__
# define 		__SFRESSOURCESMANAGER_HH__

#include			"Utility/Singleton.hpp"
#include			"Graphic/SFGraphics/Ressources/SFImageLoader.hh"
#include			"Graphic/SFGraphics/Ressources/SFFontLoader.hh"

class				SFRessourcesManager : public Singleton<SFRessourcesManager>
{
  friend class Singleton<SFRessourcesManager>;

private:
  SFRessourcesManager();
  virtual ~SFRessourcesManager();

public:
  static SFImageLoader		*Images;
  static SFFontLoader		*Fonts;

public:
  static void			loadDefaultRessources();
};

#endif
