//
// GameView.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Nov 16 18:29:50 2013 cyril jourdain
// Last update Thu Nov 21 14:49:16 2013 cyril jourdain
//

#include		"Graphic/Graphics/GameView.hh"
#include		"Graphic/ClientMain.hh"
#include		"Graphic/Global.hh"
#include		"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"
#include		"Map/Map.hh"
#include		"Map/Entity.hh"

GameView::GameView() :
  SFWidget()
{
  _customView = new sf::View(sf::FloatRect(0,0,800, 800));
  _customView->setViewport(sf::FloatRect(0,0,1,1));
  _keys = new PressedKey;
}

GameView::~GameView()
{
}

void			GameView::init()
{
  _bounds->top = 0;
  _bounds->left = 0;
  _bounds->width = WIN_X;
  _bounds->height = WIN_Y;
  _customView->setViewport(sf::FloatRect(_bounds->left / WIN_X,
				   _bounds->top / WIN_Y,
				   _bounds->width / WIN_X,
				   _bounds->height / WIN_Y));

  _background = new SFImageBox();
  _background->init();
  _background->setSize(WIN_X, WIN_Y);
  _background->setTexture((*(SFRessourcesManager::getInstance()->Images))[GAME_BACKGROUND]);
  _player = SFRessourcesManager::getInstance()->getSprite(SPRITE_PLAYER1);
  _player->play("right");
  _rocket = SFRessourcesManager::getInstance()->getSprite(SPRITE_ROCKET);
  _rocket->play("right");
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
  //target.draw(*_player, states);
  _player->update(*_clock);
  _rocket->update(*_clock);
}

void			GameView::onKeyPressed(void *const)
{
  _keys->left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
  _keys->right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
  _keys->up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
  _keys->down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
  _keys->space = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
  ClientMain::getInstance()->sendKeyPress(*_keys);
}

void			GameView::update(sf::RenderWindow *win)
{
  static unsigned int	oldScroll = 0;
  static sf::Clock	clock;
  std::list<Entity*>	entities = Map::getInstance()->getEntities();

  if (oldScroll == 0)
    {
      clock.restart();
      oldScroll = 1;
    }
  if (clock.getElapsedTime().asMilliseconds() >= 2)
    if (oldScroll <= Map::getInstance()->getScroll()/* * 10*/)
      {
	_customView->move(1, 0);
	oldScroll++;
	clock.restart();
      }
  for (auto it = entities.begin(); it != entities.end(); ++it)
    {
      //std::cout << "Player position :" << (*it)->getX() << "/" << (*it)->getY() << std::endl;
      if ((*it)->getType() == "player1")
      	{
      	  _player->setPosition((*it)->getX(), (*it)->getY());
	  _player->play((*it)->getDirection());
      	  win->setView(*_customView);
      	  win->draw(*_player);
      	  win->setView(win->getDefaultView());
      	}
      if ((*it)->getType() == "rocket")
	{
	  _rocket->setPosition((*it)->getX(), (*it)->getY());
	  _rocket->play((*it)->getDirection());
	  win->setView(*_customView);
	  win->draw(*_rocket);
	  win->setView(win->getDefaultView());
	}
    }
}
