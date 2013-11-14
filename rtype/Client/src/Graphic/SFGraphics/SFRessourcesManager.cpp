//
// SFRessourcesManager.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Tue Oct 29 13:30:23 2013 cyril jourdain
// Last update Tue Nov 12 14:07:17 2013 cyril jourdain
//

#include			"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"
#include			"Graphic/Global.hh"

SFRessourcesManager::SFRessourcesManager()
{
}

SFRessourcesManager::~SFRessourcesManager()
{
}

SFImageLoader *SFRessourcesManager::Images = SFImageLoader::getInstance();
SFFontLoader *SFRessourcesManager::Fonts = SFFontLoader::getInstance();

void			SFRessourcesManager::loadDefaultRessources()
{
  Images->loadImage(LOGIN_BUTTON_IMAGE_RES, LOGIN_BUTTON_IMAGE);
  Images->loadImage(LOGIN_BACKGROUND_RES, LOGIN_BACKGROUND);
  Images->loadImage(LOGIN_BACKGROUND_BOX_RES, LOGIN_BACKGROUND_BOX);
  Images->loadImage(LOBBY_BACKGROUND_RES, LOBBY_BACKGROUND);
  Images->loadImage(LOBBY_CENTER_BOX_RES, LOBBY_CENTER_BOX);
  Images->loadImage(LOBBY_JOIN_BUTTON_RES, LOBBY_JOIN_BUTTON);
  Images->loadImage(LOBBY_CREATE_BUTTON_RES, LOBBY_CREATE_BUTTON);
  Images->loadImage(LOBBY_REFRESH_BUTTON_RES, LOBBY_REFRESH_BUTTON);
  Images->loadImage(LOBBY_BACK_BUTTON_RES, LOBBY_BACK_BUTTON);
  Images->loadImage(DIALOGBOX_BACKGROUND_RES, DIALOGBOX_BACKGROUND);
  Images->loadImage(DIALOGBOX_OK_BUTTON_RES, DIALOGBOX_OK_BUTTON);
  Images->loadImage(LOBBY_ARRAY_BACKGROUND_RES, LOBBY_ARRAY_BACKGROUND);
  Images->loadImage(ARRAY_LINE_PART_RES, ARRAY_LINE_PART);
  Fonts->loadFont(ARIAL_FONT_RES, ARIAL_FONT);
}