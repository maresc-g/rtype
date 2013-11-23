//
// GameWindow.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Nov 16 18:22:54 2013 cyril jourdain
// Last update Sat Nov 23 19:16:54 2013 cyril jourdain
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
  _gameView = new GameView();
  _gameHud = new GameHud();
  _gameOver = new GameOver();
  addWidget(_gameView);
  addWidget(_gameHud);
  addWidget(_gameOver);
  _gameOver->setVisible(false);
  setSize(sf::Vector2f(WIN_X, WIN_Y));
}

void			GameWindow::update()
{
  if (_gameView)
    _gameView->update(_manager->getRenderWindow());
}

void			GameWindow::reset()
{
  _gameView->reset();
  _gameView->setVisible(true);
  _gameHud->setVisible(true);
  _gameOver->setVisible(false);
}

void			GameWindow::gameOver()
{
  _gameView->setVisible(false);
  _gameHud->setVisible(false);
  _gameOver->setVisible(true);
}
