//
// SFWindow.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sun Nov  3 19:15:41 2013 cyril jourdain
// Last update Wed Nov  6 14:11:39 2013 cyril jourdain
//

#ifndef 		__SFWINDOW_HH__
# define 		__SFWINDOW_HH__

#include			<list>
#include			"Graphic/SFGraphics/Widgets/SFWidget.hh"
#include			"Graphic/SFGraphics/Widgets/WindowManager.hh"

class WindowManager;

class				SFWindow
{
private:
  std::list<SFWidget *>		*_widgetList;
  SFWidget			*_focus;
  sf::FloatRect			*_bounds;
  sf::FloatRect			*_vpBounds;
protected:
  sf::View			*_view;
  WindowManager			*_manager;

public:
  SFWindow();
  SFWindow(sf::FloatRect const &rect);
  virtual ~SFWindow();

public:
  virtual void			init() = 0;
  SFWidget			*getFocused() const;
  void				setFocused(SFWidget *);
  sf::View			*getView() const;
  sf::FloatRect			*getBound() const;
  sf::FloatRect			*getVpBound() const;
  void				updateBound();
  void				setPosition(sf::Vector2f const &pos);
  void				setSize(sf::Vector2f const &pos);
  std::list<SFWidget *>		*getWidgetList() const;
  template<class T>
  T				*addWidget()
  {
    T		*w = new T;
    w->init();
    if (_widgetList)
      {
	_widgetList->push_back(w);
	return w;	
      }
    return NULL;
  }

  void				draw(sf::RenderWindow *render) const;
  void				setWindowManager(WindowManager *const m){_manager = m;}

};

#endif
