//
// GameOver.cpp for  in /home/jourda_c/Documents/C++/Rtype_test/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Nov 23 18:02:55 2013 cyril jourdain
// Last update Sun Nov 24 21:04:23 2013 cyril jourdain
//

#include		"Graphic/Graphics/GameOver.hh"
#include		"Graphic/Global.hh"
#include		"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"

GameOver::GameOver() :
  SFWidget()
{
  _customView = new sf::View(sf::FloatRect(0,0,WIN_X,WIN_Y));
  _customView->setViewport(sf::FloatRect(0,0,1,1));
}

GameOver::~GameOver()
{
  if (_gameOverImage)
    delete _gameOverImage;
}

void			GameOver::init()
{
  _bounds->top = 0;
  _bounds->left = 0;
  _bounds->width = WIN_X;
  _bounds->height = WIN_Y;
  _customView->setViewport(sf::FloatRect(_bounds->left / WIN_X,
				   _bounds->top / WIN_Y,
				   _bounds->width / WIN_X,
				   _bounds->height / WIN_Y));
  _gameOverImage = new SFImageBox();
  _gameOverImage->init();
  _gameOverImage->setSize(WIN_X, WIN_Y);
  _gameOverImage->setTexture((*(SFRessourcesManager::getInstance()->Images))[GAMEOVER_BACKGROUND]);
}

sf::FloatRect		&GameOver::getBound() const
{
  return *_bounds;
}

void			GameOver::draw(sf::RenderTarget &target, sf::RenderStates states)  const
{
  if (_gameOverImage)
    target.draw(*_gameOverImage, states);
}

