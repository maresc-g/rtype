//
// SFWidget.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Oct 23 12:06:36 2013 cyril jourdain
// Last update Sat Nov 23 18:18:55 2013 cyril jourdain
//

#ifndef 		__SFWIDGET_HH__
# define 		__SFWIDGET_HH__

#include		<SFML/Graphics.hpp>
#include		<map>
#include		<iostream>
#include		<functional>

class				SFWidget;
typedef void			(SFWidget::*methodPtr)(void *const);

class				SFWidget : public sf::Drawable, public sf::Transformable
{
private:
  typedef std::map<sf::Event::EventType, methodPtr>	MethodMap;
  static MethodMap		_ptrMap;

protected:
  bool				_focused;
  sf::FloatRect			*_bounds;
  sf::View			*_customView;
  sf::RenderTarget		*_renderTarget;
  bool				_visible;
  
public:
  SFWidget();
  virtual ~SFWidget();

public:
  MethodMap			&getMethodMap() const;
  void				setFocus(bool focus);
  virtual void			setSize(float x, float y);
  void				callNativeFunction(sf::Event *const event);
  sf::View			*getCustomView() const;
  void				setRenderTarget(sf::RenderTarget *);
  void				setVisible(bool);
  bool				isVisible() const;

private:
  virtual void			draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;

  //######## Init static map function #########
public:
  static std::map<sf::Event::EventType, methodPtr> createMap()
  {
    MethodMap m;

    m[sf::Event::MouseButtonPressed] = &SFWidget::onClick;
    m[sf::Event::KeyPressed] = &SFWidget::onKeyPressed;
    m[sf::Event::TextEntered] = &SFWidget::onTextEntered;
    m[sf::Event::MouseWheelMoved] = &SFWidget::onMouseWheelMove;
    return m;
  }
  //############################################

  //######### Virtual method ###########
public:
  virtual void			init() = 0;
  virtual void			setBackgroundColor(sf::Color) = 0;
  virtual sf::FloatRect		&getBound() const;
  virtual void			onClick(void *const param);
  virtual void			onKeyPressed(void *const){};
  virtual void			onTextEntered(void *const){};
  virtual void			onMouseWheelMove(void *const){};
  //####################################

};

#endif
