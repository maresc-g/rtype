//
// SFRessourcesManager.cpp for  in /home/jourda_c/Documents/C++/Rtype_test/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Nov 23 23:46:14 2013 cyril jourdain
// Last update Sun Nov 24 16:55:30 2013 cyril jourdain
//

#include			"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"
#include			"Graphic/Global.hh"

SFRessourcesManager::SFRessourcesManager() :
  _sprites(new std::map<std::string, AnimatedSprite *>)
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
  Images->loadImage(DIALOGBOX_CANCEL_BUTTON_RES, DIALOGBOX_CANCEL_BUTTON);
  Images->loadImage(LOBBY_ARRAY_BACKGROUND_RES, LOBBY_ARRAY_BACKGROUND);
  Images->loadImage(ARRAY_LINE_PART_RES, ARRAY_LINE_PART);
  Images->loadImage(ARRAY_LINE_PART_SELECTED_RES, ARRAY_LINE_PART_SELECTED);
  Images->loadImage(GAME_BACKGROUND_RES, GAME_BACKGROUND);
  Images->loadImage(GAME_BACKGROUND_RES, GAME_BACKGROUND2);
  Images->loadImage(GAMEOVER_BACKGROUND_RES, GAMEOVER_BACKGROUND);
  Images->loadImage(GAME_HUD_RES, GAME_HUD);
  Images->loadImage(GAME_HUD_LIVES_RES, GAME_HUD_LIVES);
  Fonts->loadFont(ARIAL_FONT_RES, ARIAL_FONT);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_PLAYER1, SPRITE_PLAYER1_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_PLAYER2, SPRITE_PLAYER2_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_PLAYER3, SPRITE_PLAYER3_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_PLAYER4, SPRITE_PLAYER4_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_MOB1, SPRITE_MOB1_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_ROCKET, SPRITE_ROCKET_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_ROCKET2, SPRITE_ROCKET2_CONF, true);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALLD1, SPRITE_WALLD1_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALLD2, SPRITE_WALLD2_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALLD3, SPRITE_WALLD3_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALLD4, SPRITE_WALLD4_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALLD5, SPRITE_WALLD5_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALLU1, SPRITE_WALLU1_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALLU2, SPRITE_WALLU2_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALLU3, SPRITE_WALLU3_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALLU4, SPRITE_WALLU4_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALLU5, SPRITE_WALLU5_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALL1D1, SPRITE_WALL1D1_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALL1D2, SPRITE_WALL1D2_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALL1D3, SPRITE_WALL1D3_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALL1D4, SPRITE_WALL1D4_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALL1D5, SPRITE_WALL1D5_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALL1U1, SPRITE_WALL1U1_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALL1U2, SPRITE_WALL1U2_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALL1U3, SPRITE_WALL1U3_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALL1U4, SPRITE_WALL1U4_CONF);
  SFRessourcesManager::getInstance()->addSprite(SPRITE_WALL1U5, SPRITE_WALL1U5_CONF);
  SFRessourcesManager::getInstance()->addSprite(EXPLOSION, EXPLOSION_CONF, true);
}

void			SFRessourcesManager::addSprite(std::string const &name, std::string const &path, bool const loop)
{
  AnimatedSprite	*sprite;

  sprite = new AnimatedSprite();
  if (sprite){
    sprite->loadFromFile(path);
    sprite->setLoopPlay(loop);
    (*_sprites)[name] = sprite;
  }
}

AnimatedSprite		*SFRessourcesManager::getSprite(std::string const &str) const
{
  if ((*_sprites)[str])
    return ((*_sprites)[str]);
  return NULL;
}
