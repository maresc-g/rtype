//
// GameWindow.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Nov 16 18:22:54 2013 cyril jourdain
// Last update Fri Nov 22 13:20:47 2013 cyril jourdain
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
  addWidget(_gameView);

  // addWidget(_score);
  // addWidget(_HUDBar);

  // sf::FloatRect	tmp = _gameView->getBound();
  // sf::Vector2i gamePos = {tmp.height, tmp.width};

  // sf::Vector2f	worldPos = _manager->getRenderWindow()->mapPixelToCoords(gamePos, *_gameView->getCustomView());

  // std::cout << worldPos.x << std::endl;
  // std::cout << WIN_Y - worldPos.y << std::endl;

  // _HUDBar->setSize(WIN_X, WIN_Y - worldPos.y);
  // _HUDBar->setPosition(0, worldPos.y);
  // _HUDBar->setTexture((*(SFRessourcesManager::getInstance()->Images))[GAME_HUD]);
  // _score->setColor(sf::Color::White);
  // _score->setText("Score : 00000000");
  // _score->setPosition(_HUDBar->getPosition().x + 200, _HUDBar->getPosition().y + _HUDBar->getBound().height / 2 - 20);
  // _score->setTextSize(22);
  // std::cout << "POSITION Y HUD : " << _HUDBar->getPosition().y << std::endl;
  // std::cout << "POSITION Y SCORE : " << _score->getPosition().y << std::endl;
  // for (int i = 0; i < 3; i++)
  //   {
  //     _lives->push_back(new SFImageBox());
  //     addWidget((*_lives)[i]);
  //     (*_lives)[i]->setTexture((*(SFRessourcesManager::getInstance()->Images))[GAME_HUD_LIVES]);
  //     (*_lives)[i]->setSize(32,32);
  //     (*_lives)[i]->setPosition(_score->getPosition().x + 450 + (i * 35), _score->getPosition().y);
  //   }
  setSize(sf::Vector2f(WIN_X, WIN_Y));
}

void			GameWindow::update()
{
  if (_gameView)
    _gameView->update(_manager->getRenderWindow());
}
