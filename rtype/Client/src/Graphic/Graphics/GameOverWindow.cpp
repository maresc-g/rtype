//
// GameOverWindow.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Mon Nov  4 16:14:46 2013 cyril jourdain
// Last update Sat Nov 23 13:41:01 2013 guillaume marescaux
//

#include		"Graphic/Graphics/GameOverWindow.hh"
#include		"Graphic/ClientMain.hh"
#include		"Graphic/Global.hh"
#include		"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"
#include		"Game/GameList.hh"
#include		"Game/GameInfo.hh"
#include		"Graphic/SFGraphics/Widgets/SFConnect.hh"

GameOverWindow::GameOverWindow() :
  SFWindow(sf::FloatRect(0,0,WIN_X,WIN_Y))
{
}

GameOverWindow::~GameOverWindow()
{
}

void			GameOverWindow::init()
{
  _background = new SFImageBox();

  addWidget(_background);
  // Textures
  _background->setTexture((*(SFRessourcesManager::getInstance()->Images))[GAMEOVER_BACKGROUND]);
  // ~Texture
  _background->setSize(WIN_X,WIN_Y);
}
