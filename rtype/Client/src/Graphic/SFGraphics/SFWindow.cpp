//
// SFWindow.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sun Nov  3 19:36:18 2013 cyril jourdain
// Last update Fri Nov 15 20:14:11 2013 cyril jourdain
//

#include			"Graphic/SFGraphics/Widgets/SFWindow.hh"
#include			"Graphic/Global.hh"

static bool deleteList(SFWidget *elem) {delete elem; return true;}

SFWindow::SFWindow() :
  _widgetList(new std::list<SFWidget*>), _focus(NULL), _bounds(new sf::FloatRect(0,0,0,0)),
  _vpBounds(new sf::FloatRect(0,0,0,0)),
  _view(new sf::View())
{
  _visible = true;
  _stayOnTop = false;
  _onCloseCallback = NULL;
}

SFWindow::SFWindow(sf::FloatRect const &rect) :
  _widgetList(new std::list<SFWidget*>), _focus(NULL), _bounds(new sf::FloatRect(0,0,0,0)),
  _vpBounds(new sf::FloatRect(rect)),
  _view(new sf::View(rect))
{
  _view->setViewport(sf::FloatRect(0,0,1,1));
  _visible = true;
  _stayOnTop = false;
  _onCloseCallback = NULL;
}

SFWindow::~SFWindow()
{
  _focus = NULL;
  if (_widgetList)
    {
      _widgetList->remove_if(deleteList);
    }
  delete _widgetList;
  // might not work
}

void				SFWindow::setId(unsigned int id) {_id = id;}
unsigned int			SFWindow::getId() const {return _id;}

SFWidget			*SFWindow::getFocused() const
{
  return _focus;
}

void				SFWindow::setFocused(SFWidget *w)
{
  _focus = w;
}

sf::View			*SFWindow::getView() const
{
  return _view;
}

sf::FloatRect			*SFWindow::getBound() const
{
  return _bounds;
}

sf::FloatRect			*SFWindow::getVpBound() const
{
  return _vpBounds;
}

void				SFWindow::updateBound()
{
  float	sizex = _view->getSize().x;
  float	sizey = _view->getSize().y;
  float centerx = _view->getCenter().x;
  float centery = _view->getCenter().y;

  _bounds->left = -((centerx - (sizex / 2)));// * _view->getViewport().width);
  _bounds->top = -((centery - (sizey / 2)));// * _view->getViewport().height);
  _bounds->width = (sizex)// * _view->getViewport().width
    ;
  _bounds->height = (sizey)// * _view->getViewport().height
    ;
}

void				SFWindow::setPosition(sf::Vector2f const &pos)
{
  _vpBounds->left = pos.x;
  _vpBounds->top = pos.y;
  _view->setViewport(sf::FloatRect(_vpBounds->left / WIN_X,
				   _vpBounds->top / WIN_Y,
				   _vpBounds->width / WIN_X,
				   _vpBounds->height / WIN_Y));
}

void				SFWindow::setSize(sf::Vector2f const &size)
{
  _vpBounds->width = size.x;
  _vpBounds->height = size.y;
  _view->setViewport(sf::FloatRect(_vpBounds->left / WIN_X,
				   _vpBounds->top / WIN_Y,
				   _vpBounds->width / WIN_X,
				   _vpBounds->height / WIN_Y));
}

std::list<SFWidget *>		*SFWindow::getWidgetList() const
{
  return _widgetList;
}

void				SFWindow::setVisibility(bool visibility)
{
  _visible = visibility;
}

bool				SFWindow::isVisible() const
{
  return _visible;
}

void				SFWindow::setStayOnTop(bool val)
{
  _stayOnTop = val;
}

bool				SFWindow::isStayOnTop() const
{
  return _stayOnTop;
}

void				SFWindow::addWidget(SFWidget *w)
{
  w->setRenderTarget(_manager->getRenderWindow());
  w->init();
  _widgetList->push_back(w);
}

void				SFWindow::draw(sf::RenderWindow *win) const
{
  for (std::list<SFWidget *>::iterator it = _widgetList->begin();it != _widgetList->end();++it)
    {
      if ((*it)->getCustomView())
       	win->setView(*(*it)->getCustomView());
      win->draw(**it);
      if ((*it)->getCustomView())
	win->setView(win->getDefaultView());
    }
}
