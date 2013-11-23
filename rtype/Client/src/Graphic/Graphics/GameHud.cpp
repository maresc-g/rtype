//
// GameHud.cpp for  in /home/jourda_c/Documents/C++/Rtype_test/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Nov 23 17:19:13 2013 cyril jourdain
// Last update Sat Nov 23 18:18:13 2013 cyril jourdain
//

#include		"Graphic/Graphics/GameHud.hh"
#include		"Graphic/Global.hh"
#include		"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"

GameHud::GameHud() :
  SFWidget()
{
  _customView = new sf::View(sf::FloatRect(0,0,800,150));
  _customView->setViewport(sf::FloatRect(0,0,1,1));
}

GameHud::~GameHud()
{
}

void			GameHud::init()
{
  _bounds->top = WIN_Y - 150;
  _bounds->left = 0;
  _bounds->width = WIN_X;
  _bounds->height = 150;
  _customView->setViewport(sf::FloatRect(_bounds->left / WIN_X,
				   _bounds->top / WIN_Y,
				   _bounds->width / WIN_X,
				   _bounds->height / WIN_Y));
  _background = new SFImageBox();
  _background->init();
  _background->setSize(WIN_X, 150);
  _background->setTexture((*(SFRessourcesManager::getInstance()->Images))[GAME_HUD]);
  _score = new SFLabel();
  _score->init();
  _score->setColor(sf::Color::White);
  _score->setText("Score : 00000000");
  _score->setPosition(100, 75);
  _score->setTextSize(18);
}

sf::FloatRect		&GameHud::getBound() const
{
  return *_bounds;
}

void			GameHud::draw(sf::RenderTarget &target, sf::RenderStates states)  const
{
  target.draw(*_background, states);
  target.draw(*_score, states);
}
