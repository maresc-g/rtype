//
// WindowManager.cpp for  in /home/jourda_c/Documents/C++/RType/Sources/include
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Oct 23 00:18:05 2013 cyril jourdain
// Last update Fri Nov  8 14:45:48 2013 cyril jourdain
//

#include	<iostream>
#include	<functional>
#include	"Graphic/SFGraphics/Widgets/WindowManager.hh"
#include	"Graphic/SFGraphics/Ressources/SFImageLoader.hh"
#include	"Graphic/SFGraphics/Widgets/SFConnect.hh"
#include	"Graphic/Global.hh"

WindowManager::WindowManager() :
  _widgetList(new std::list<SFWidget*>), _focus(NULL),
  _windowList(new WindowList), _active(NULL),
  _cEvent(new sf::Event)
{
  _size.x = WIN_X;
  _size.y = WIN_Y;
  _exit = false;
  _fps = 20;
}

WindowManager::~WindowManager()
{
}

SFWidget	*WindowManager::getFocused() const
{
  return _focus;
}

void		WindowManager::draw() const
{
  _window->setView(*(_active->getView()));
  if (_windowList && !_windowList->empty())
    {
      for (auto it = _windowList->begin(); it != _windowList->end(); ++it)
	{
	  if (it->second && it->second->isVisible())
	    {
	      _window->setView(*(it->second->getView()));
	      it->second->draw(_window);
	    }
	}
      _window->setView(_window->getDefaultView());
    }
}

void		WindowManager::setFocusedWindow(sf::Event const &mouse)
{
  float x, y;
  bool	win = false;
  unsigned int		winId;
  SFWindow	*winPtr;

  sf::Vector2i  pos(mouse.mouseButton.x, mouse.mouseButton.y);
  sf::Vector2f	worldPos = _window->mapPixelToCoords(pos);
  WindowList::iterator save = _windowList->end();

  x = worldPos.x;
  y = worldPos.y;
  for (auto it = _windowList->begin(); it != _windowList->end(); it++)
    {
      if (it->second->isVisible())
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
    }
  if (win)
    {
      _active = save->second;
      winId = save->first;
      winPtr = save->second;
      _windowList->erase(save);
      _windowList->push_back(std::pair<unsigned int, SFWindow*>(winId, winPtr));
    }
}

void		WindowManager::tabEvent()
{
  bool		isSet = true;

  if (_active && _widgetList)
    {
      _widgetList = _active->getWidgetList();
      if (_focus)
	{
	  _focus->setFocus(false);
	  auto it = find(_widgetList->begin(), _widgetList->end(), _focus);
	  if (it != _widgetList->end())
	    {
	      ++it;
	      if (it != _widgetList->end())
		{
		  _focus = *it;
		  _focus->setFocus(true);
		  _active->setFocused(_focus);
		}
	      else
		isSet = false;
	    }
	}
      else
	isSet = false;
    }
  if (!isSet)
    {
      _focus = _widgetList->front();
      _focus->setFocus(true);
      _active->setFocused(_focus);
    }
}

void		WindowManager::shiftTabEvent()
{
  bool		isSet = true;

  if (_active && _widgetList)
    {
      _widgetList = _active->getWidgetList();
      if (_focus)
	{
	  _focus->setFocus(false);
	  auto it = find(_widgetList->begin(), _widgetList->end(), _focus);
	  if (it != _widgetList->begin())
	    {
	      --it;
	      if (it != _widgetList->begin())
		{
		  _focus = *it;
		  _focus->setFocus(true);
		  _active->setFocused(_focus);
		}
	      else
		isSet = false;
	    }
	}
      else
	isSet = false;
    }
  if (!isSet)
    {
      _focus = _widgetList->back();
      _focus->setFocus(true);
      _active->setFocused(_focus);
    }
}

bool		WindowManager::clickEvent(sf::Event const &mouse)
{
  float x, y;
  bool	obj = false;
  sf::Vector2i  pos(mouse.mouseButton.x, mouse.mouseButton.y);
  sf::Vector2f	worldPos = _window->mapPixelToCoords(pos);
  WindowList::iterator save = _windowList->end();

  x = worldPos.x;
  y = worldPos.y;
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
      if (_cEvent->type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
	{
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	    shiftTabEvent();
	  else
	    tabEvent();
	}
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

void		WindowManager::addWindow(unsigned int const id, SFWindow *win)
{
  _windowList->push_back(std::pair<unsigned int, SFWindow*>(id, win));
  _active = win;
  win->setWindowManager(this);
  win->setId(id);
  win->init();
}

void		WindowManager::addWindow(SFWindow *win)
{
  unsigned int	id = getLastWindowIndex() + 1;

  _windowList->push_back(std::pair<unsigned int, SFWindow*>(id, win));
  _active = win;
  win->setWindowManager(this);
  win->setId(id);
  win->init();
}

void		WindowManager::init()
{
  _window = new sf::RenderWindow(sf::VideoMode(WIN_X, WIN_Y), "RType");
  SFRessourcesManager::loadDefaultRessources();
}

void		WindowManager::exec()
{
  sf::Clock	clock;
  sf::Time	elapsedTime;
  float		time;

  while (!_exit)
    {
      clock.restart();
      manageEvent();
      _window->display();
      _window->clear();
      draw();
      elapsedTime = clock.getElapsedTime();
      time = 100000 / _fps - elapsedTime.asMicroseconds();
      if (time > 0)
	sf::sleep(sf::microseconds(time));
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

void			WindowManager::setActiveWindow(unsigned int const id)
{
  unsigned int winId;
  SFWindow *winPtr;

  auto it = find_if(_windowList->begin(), _windowList->end(),
		    [&](const std::pair<unsigned int, SFWindow*>& val) -> bool {
		      return val.first == id;
		    });
  if (it != _windowList->end())
    {
      _active = it->second;
      winId = it->first;
      winPtr = it->second;
      winPtr->setVisibility(true);
      _windowList->erase(it);
      _windowList->push_back(std::pair<unsigned int, SFWindow*>(winId, winPtr));
    }
}

SFWindow			*WindowManager::getWindowById(unsigned int const id) const
{
  auto it = find_if(_windowList->begin(), _windowList->end(),
		    [&](const std::pair<unsigned int, SFWindow*>& val) -> bool {
		      return val.first == id;
		    });
  if (it != _windowList->end())
    return it->second;
  return NULL;
}

void				WindowManager::removeWindowById(unsigned int const id)
{
  auto it = find_if(_windowList->begin(), _windowList->end(),
		    [&](const std::pair<unsigned int, SFWindow*>& val) -> bool {
		      return val.first == id;
		    });
  if (it != _windowList->end())
    {
      _windowList->erase(it);
      delete it->second;
    }
}

void				WindowManager::removeWindowCallback(void *param)
{
  unsigned int	id = *(reinterpret_cast<unsigned int*>(param));

  auto it = find_if(_windowList->begin(), _windowList->end(),
		    [&](const std::pair<unsigned int, SFWindow*>& val) -> bool {
		      return val.first == id;
		    });
  if (it != _windowList->end())
    _windowList->remove(*it);
}

unsigned int			WindowManager::getLastWindowIndex() const
{
  unsigned int			index;

  if (_windowList)
    {
      index = _windowList->front().first;
      for (auto it = _windowList->begin(); it != _windowList->end(); ++it)
	{
	  if (it->first > index)
	    index = it->first;
	}
    }
  return (index);
}

