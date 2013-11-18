//
// GameWindow.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Nov 16 18:22:54 2013 cyril jourdain
// Last update Sun Nov 17 23:15:09 2013 cyril jourdain
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
  _score = new SFLabel();
  _lives = new std::vector<SFImageBox*>;
  addWidget(_HUDBar);
  addWidget(_gameView);
  addWidget(_score);
  _HUDBar->setPosition(0, _gameView->getBound().height);
  _HUDBar->setSize(WIN_X, WIN_Y - _HUDBar->getPosition().y);
  _HUDBar->setTexture((*(SFRessourcesManager::getInstance()->Images))[GAME_HUD]);
  _score->setColor(sf::Color::White);
  _score->setText("Score : 00000000");
  _score->setTextSize(22);
  _score->setPosition(_HUDBar->getPosition().x + 200, _HUDBar->getPosition().y + _HUDBar->getBound().height / 2 - 20);
  for (int i = 0; i < 3; i++)
    {
      _lives->push_back(new SFImageBox());
      addWidget((*_lives)[i]);
      (*_lives)[i]->setTexture((*(SFRessourcesManager::getInstance()->Images))[GAME_HUD_LIVES]);
      (*_lives)[i]->setSize(32,32);
      (*_lives)[i]->setPosition(_score->getPosition().x + 450 + (i * 35), _score->getPosition().y);
    }
  setSize(sf::Vector2f(WIN_X, WIN_Y));
}
