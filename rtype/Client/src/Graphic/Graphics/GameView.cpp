//
// GameView.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Nov 16 18:29:50 2013 cyril jourdain
// Last update Mon Nov 18 14:50:47 2013 cyril jourdain
//

#include		"Graphic/Graphics/GameView.hh"
#include		"Graphic/ClientMain.hh"
#include		"Graphic/Global.hh"
#include		"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"

GameView::GameView() :
  SFWidget()
{
  _customView = new sf::View(sf::FloatRect(0,0,WIN_X, WIN_Y - 100));
  _customView->setViewport(sf::FloatRect(0,0,1,1));
}

GameView::~GameView()
{
}

void			GameView::init()
{
  _bounds->top = 0;
  _bounds->left = 0;
  _bounds->width = WIN_X;
  _bounds->height = WIN_Y - 100;
  _customView->setViewport(sf::FloatRect(_bounds->left / WIN_X,
				   _bounds->top / WIN_Y,
				   _bounds->width / WIN_X,
				   _bounds->height / WIN_Y));

  _background = new SFImageBox();
  _background->init();
  _background->setSize(WIN_X, WIN_Y);
  _background->setTexture((*(SFRessourcesManager::getInstance()->Images))[GAME_BACKGROUND]);
  _sprite = new AnimatedSprite();
  std::string dir  = SPRITE_DIR;
  dir += "/player.sprite";
  _sprite->loadFromFile(dir);
  _sprite->play("gauche");
  _clock = new sf::Clock();
  _clock->restart();
}

sf::FloatRect		&GameView::getBound() const
{
  return *_bounds;
}

void			GameView::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(*_background, states);
  target.draw(*_sprite, states);
  _sprite->update(*_clock);
}
