//
// WindowManager.cpp for  in /home/jourda_c/Documents/C++/RType/Sources/include
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Oct 23 00:18:05 2013 cyril jourdain
// Last update Wed Nov  6 21:34:28 2013 cyril jourdain
//

#include	<iostream>
#include	<functional>
#include	"Graphic/SFGraphics/Widgets/WindowManager.hh"
#include	"Graphic/SFGraphics/Ressources/SFImageLoader.hh"
#include	"Graphic/SFGraphics/Widgets/SFConnect.hh"
#include	"Graphic/Global.hh"

WindowManager::WindowManager() :
  _widgetList(new std::list<SFWidget*>), _focus(NULL),
  _windowList(new std::map<std::string, SFWindow*>), _active(NULL),
  _cEvent(new sf::Event)
{
  _size.x = WIN_X;
  _size.y = WIN_Y;
  _exit = false;
}

WindowManager::~WindowManager()
{
}

SFWidget	*WindowManager::getFocused() const
{
  return _focus;
}

/*
  Remaining problem :
  If a window is over another one, the window selection bug,
  due to the usage of a map, where there's no order
  Need to find a way to sort map, in order to always take
  the front one.
  Idea : Make a list, not a map, of struct, containing a name a SFWindow
  Then windows will be in the drawing order
 */
void		WindowManager::draw() const
{
  _window->setView(*(_active->getView()));
  for (auto it = _windowList->begin(); it != _windowList->end(); it++)
    {
      if (it->second != _active)
	{
	  _window->setView(*(it->second->getView()));
	  it->second->draw(_window);
	}
    }
  if (_active)
    {
      _window->setView(*(_active->getView()));
      _active->draw(_window);
    }
  _window->setView(_window->getDefaultView());
}

void		WindowManager::setFocusedWindow(sf::Event const &mouse)
{
  float x, y;
  bool	win = false;
  std::string winName;
  SFWindow	*winPtr;

  sf::Vector2i  pos(mouse.mouseButton.x, mouse.mouseButton.y);
  sf::Vector2f	worldPos = _window->mapPixelToCoords(pos);
  std::map<std::string, SFWindow*>::iterator save = _windowList->end();

  x = worldPos.x;
  y = worldPos.y;
  for (auto it = _windowList->begin(); it != _windowList->end(); it++)
    {
      if (x >= it->second->getVpBound()->left &&
  	  x <= it->second->getVpBound()->width + it->second->getVpBound()->left &&
  	  y >= it->second->getVpBound()->top &&
  	  y <= it->second->getVpBound()->height + it->second->getVpBound()->top)
  	{
	  save = it;
	  win = true;
  	}
    }
  if (win)
    {
      std::cout << "Change active window" << std::endl;
      _active = save->second;
      winName = save->first;
      winPtr = save->second;
      _windowList->erase(save);
      _windowList->insert(std::pair<std::string, SFWindow*>(winName, winPtr));
    }
}

bool		WindowManager::clickEvent(sf::Event const &mouse)
{
  float x, y;
  bool	obj = false;
  bool	win = false;

  sf::Vector2i  pos(mouse.mouseButton.x, mouse.mouseButton.y);
  sf::Vector2f	worldPos = _window->mapPixelToCoords(pos);
  std::map<std::string, SFWindow*>::iterator save = _windowList->end();

  x = worldPos.x;
  y = worldPos.y;
  
  // for (auto it = _windowList->begin(); it != _windowList->end(); it++)
  //   {
  //     if (x >= it->second->getVpBound()->left &&
  // 	  x <= it->second->getVpBound()->width + it->second->getVpBound()->left &&
  // 	  y >= it->second->getVpBound()->top &&
  // 	  y <= it->second->getVpBound()->height + it->second->getVpBound()->top)
  // 	{
  // 	  save = it;
  // 	  win = true;
  // 	}
  //   }
  // if (win)
  //   {
  //     _active = save->second;
  //     _windowList->erase(save);
  //     _windowList->insert(save);
  //   }
  setFocusedWindow(mouse);
  if (_active)
    {
      _widgetList = _active->getWidgetList();
      worldPos = _window->mapPixelToCoords(pos, *_active->getView());
      x = worldPos.x;
      y = worldPos.y;
      _focus = _active->getFocused();
    }
  if (_focus)
    _focus->setFocus(false);
  _focus = NULL;
  for (auto it = _widgetList->begin(); it != _widgetList->end(); it++)
    {
      if (x >= (*it)->getPosition().x &&
	  x <= ((*it)->getPosition().x + (*it)->getBound().width) &&
	  y >= (*it)->getPosition().y &&
	  y <= (*it)->getPosition().y + (*it)->getBound().height)
      	{
      	  _focus = *it;
	  _focus->setFocus(true);
	  _active->setFocused(_focus);
	  obj = true;
      	}
    }
  _window->setView(_window->getDefaultView());
  return (obj);
}

void		WindowManager::manageEvent()
{
  SFConnect	*connect = SFConnect::getInstance();

  while (_window->pollEvent(*_cEvent))
    {
      if (_cEvent->type == sf::Event::Closed)
	{
	  _exit = true;
	  return;
	}
      _click = true;
      if (_cEvent->type == sf::Event::MouseButtonPressed)
	_click = clickEvent(*_cEvent);
      if (_click && _focus && _focus->getMethodMap()[_cEvent->type])
	{
	  _focus->callNativeFunction(_cEvent);
	  connect->callCallback(_cEvent, _focus);
	}
    }
}

/////////////////// TODO : CHECK IF IT WORKS. DELETE USELESS CODE AND SHIT

void		WindowManager::addWidget(SFWidget *widget)
{
  _widgetList->push_back(widget);
}

void		WindowManager::addWindow(std::string const &name, SFWindow *win)
{
  _windowList->insert(std::pair<std::string, SFWindow*>(name, win));
  _active = win;
}

void		WindowManager::init()
{
  _window = new sf::RenderWindow(sf::VideoMode(WIN_X, WIN_Y), "RType");
  SFRessourcesManager::loadDefaultRessources();
}

void		WindowManager::exec()
{
  while (!_exit)
    {
      manageEvent();
      _window->display();
      _window->clear();
      draw();
    }
  if (_window)
    _window->close();
}

sf::RenderWindow	*WindowManager::getRenderWindow() const {
  return (_window);
}
void			WindowManager::setRenderWindow(sf::RenderWindow *win) {
  _window = win;
}


// void			WindowManager::switchToLobby(void *const obj)
// {
//   SFWindow	*save = _windowList->back();
//   auto		itsave = find(_windowList->begin(), _windowList->end(), save);
//   std::string	text = reinterpret_cast<SFTextBox*>(obj)->getText();

//   std::cout << text << std::endl;
//   _active = _windowList->front();
//   _windowList->erase(itsave);
//   _windowList->push_front(save);
// }
