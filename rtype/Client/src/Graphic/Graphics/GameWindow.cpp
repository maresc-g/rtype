//
// GameWindow.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Nov 16 18:22:54 2013 cyril jourdain
// Last update Sat Nov 16 19:58:39 2013 cyril jourdain
//

#include		"Graphic/Graphics/GameWindow.hh"
#include		"Graphic/Global.hh"

GameWindow::GameWindow() :
  SFWindow(sf::FloatRect(0,0,WIN_X,WIN_Y))
{
}

GameWindow::~GameWindow()
{
}

void			GameWindow::init()
{
  _HUDBar = new SFImageBox();
  _gameView = new GameView();
  addWidget(_HUDBar);
  addWidget(_gameView);
  _HUDBar->setPosition(0, _gameView->getBound().height);
  _HUDBar->setSize(WIN_X, WIN_Y - _HUDBar->getPosition().y);
  _HUDBar->setTexture((*(SFRessourcesManager::getInstance()->Images))[GAME_HUD]);
  setSize(sf::Vector2f(WIN_X, WIN_Y));
}
