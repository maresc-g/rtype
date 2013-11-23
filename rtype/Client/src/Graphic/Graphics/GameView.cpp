//
// GameView.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Nov 16 18:29:50 2013 cyril jourdain
// Last update Sat Nov 23 21:16:29 2013 guillaume marescaux
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
  _bounds->height = WIN_Y - 150;
  _customView->setViewport(sf::FloatRect(_bounds->left / WIN_X,
				   _bounds->top / WIN_Y,
				   _bounds->width / WIN_X,
				   _bounds->height / WIN_Y));

  _background = new SFImageBox();
  _background->init();
  _background->setSize(WIN_X, WIN_Y);
  _background->setTexture((*(SFRessourcesManager::getInstance()->Images))[GAME_BACKGROUND]);
  _player = SFRessourcesManager::getInstance()->getSprite(SPRITE_PLAYER1);
  _clock = new sf::Clock();
  _clock->restart();
  _scroll = 0;
  _totalScroll = 0;
  _clockScroll = new sf::Clock();
}

sf::FloatRect		&GameView::getBound() const
{
  return *_bounds;
}

void			GameView::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(*_background, states);
}

void			GameView::onKeyPressed(void *const)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    ClientMain::getInstance()->quitGame();
}

void			GameView::checkKeys()
{
  static sf::Clock		clock;
  static sf::Clock		clockSpace;
  static bool			init = false;
  static bool			saveSpace;

  if (!init)
    {
      clock.restart();
      clockSpace.restart();
      init = true;
      _keys->space = 0;
    }
  if (clock.getElapsedTime().asMicroseconds() >= 60000)
    {
      _keys->left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
      _keys->right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
      _keys->up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
      _keys->down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    }
  if (clockSpace.getElapsedTime().asMicroseconds() >= 300000)
    {
      saveSpace = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
      if (saveSpace)
	{
	  _keys->space = saveSpace;
	  clockSpace.restart();
	}
    }
  if (clock.getElapsedTime().asMicroseconds() >= 60000)
    {
      ClientMain::getInstance()->sendKeyPress(*_keys);
      _keys->space = 0;
      clock.restart();
    }
}

void			GameView::update(sf::RenderWindow *win)
{
  std::list<Entity*>	*entities = Map::getInstance()->getEntities();

  checkKeys();
  if (_scroll == 0)
    {
      _clockScroll->restart();
      _scroll = Map::getInstance()->getScroll();
      _totalScroll = _scroll;
      _customView->move(_scroll, 0);
    }
  if (_clockScroll->getElapsedTime().asMilliseconds() >= 5)
    if (_scroll <= Map::getInstance()->getScroll())
      {
	_customView->move(1, 0);
	_scroll++;
	_clockScroll->restart();
	_totalScroll++;
      }
  for (auto it = entities->begin(); it != entities->end(); ++it)
    {
      _player = SFRessourcesManager::getInstance()->getSprite((*it)->getType());
      _player->update(*_clock);
      _player->setPosition((*it)->getX(), (*it)->getY());
      _player->play((*it)->getDirection());
      win->setView(*_customView);
      if ((*it)->getInvincible() == true)
      	{
      	  if (static_cast<int>((*it)->getTime() * 10) % 5)
      	    win->draw(*_player);
      	}
      else
	win->draw(*_player);
      win->setView(win->getDefaultView());
    }
  for (auto it = entities->begin() ; it != entities->end() ; it++)
    {
      delete *it;
    }
}

void			GameView::reset()
{
  _customView->move((_totalScroll * -1), 0);
  _scroll = 0;
  _totalScroll = 0;
}
