//
// SFWindow.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sun Nov  3 19:15:41 2013 cyril jourdain
// Last update Sat Nov 23 18:15:08 2013 cyril jourdain
//

#ifndef 		__SFWINDOW_HH__
# define 		__SFWINDOW_HH__

#include			<list>
#include			"Graphic/SFGraphics/Widgets/SFWidget.hh"
#include			"Graphic/SFGraphics/Widgets/WindowManager.hh"
#include			"Graphic/SFGraphics/Widgets/SFConnect.hh"

class WindowManager;

class				SFWindow
{
private:
  std::list<SFWidget *>		*_widgetList;
  SFWidget			*_focus;
  sf::FloatRect			*_bounds;
  sf::FloatRect			*_vpBounds;
  bool				_visible;
  bool				_stayOnTop;

protected:
  sf::View			*_view;
  WindowManager			*_manager;
  unsigned int			_id;
  SFConnect::EventCallback	*_onCloseCallback;

public:
  SFWindow();
  SFWindow(sf::FloatRect const &rect);
  virtual ~SFWindow();

public:
  virtual void			init() = 0;
  void				setId(unsigned int id);
  unsigned int			getId() const;
  SFWidget			*getFocused() const;
  void				setFocused(SFWidget *);
  sf::View			*getView() const;
  sf::FloatRect			*getBound() const;
  sf::FloatRect			*getVpBound() const;
  void				updateBound();
  void				setPosition(sf::Vector2f const &pos);
  void				setSize(sf::Vector2f const &pos);
  std::list<SFWidget *>		*getWidgetList() const;
  void				setVisibility(bool visibility);
  bool				isVisible() const;
  void				setStayOnTop(bool val);
  bool				isStayOnTop() const;

  template<class T>
  void			setOnCloseCallback(void (T::*)(void *const),
					   T*)
  {
  }

  SFConnect::EventCallback	*getOnCloseCallback() const
  {
    return _onCloseCallback;
  }

  void				addWidget(SFWidget *);
  void				draw(sf::RenderWindow *render) const;
  void				setWindowManager(WindowManager *const m){_manager = m;}
  virtual void			update() {};

};

#endif
