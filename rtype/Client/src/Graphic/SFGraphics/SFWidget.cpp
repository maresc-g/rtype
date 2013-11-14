//
// SFWidget.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Thu Oct 24 17:38:46 2013 cyril jourdain
// Last update Tue Nov 12 13:21:07 2013 cyril jourdain
//

#ifndef 		__SFWIDGET_CPP__
# define 		__SFWIDGET_CPP__

#include		"Graphic/SFGraphics/Widgets/SFWidget.hh"

SFWidget::SFWidget() : sf::Drawable(), sf::Transformable()
{
  _bounds = new sf::FloatRect(0,0,0,0);
  _customView = NULL;
  //_mouseParam = NULL;
};

SFWidget::~SFWidget()
{
}

SFWidget::MethodMap	&SFWidget::getMethodMap() const
{
  return SFWidget::_ptrMap;
}

void			SFWidget::setFocus(bool focus)
{
  _focused = focus;
}

sf::FloatRect		&SFWidget::getBound() const
{
  return (*_bounds);
}

sf::View		*SFWidget::getCustomView() const
{
  return (_customView);
}

void			SFWidget::setSize(float x, float y)
{
  float scaleX, scaleY;

  scaleX = x / (*_bounds).width * getScale().x;
  scaleY = y / (*_bounds).height * getScale().y;
  setScale(scaleX, scaleY);
  _bounds->width *= scaleX;
  _bounds->height *= scaleY;
}

void			SFWidget::callNativeFunction(sf::Event *const event)
{
  if (_ptrMap[event->type])
    (this->*(_ptrMap[event->type]))(event);
}

/* EVENT FUNCTION CLASSBACK */
void			SFWidget::onClick(void *const)
{
}

SFWidget::MethodMap SFWidget::_ptrMap = SFWidget::createMap();

#endif