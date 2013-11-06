//
// WindowManager.hh for  in /home/jourda_c/Documents/C++/RType/Sources/include
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Oct 23 00:00:35 2013 cyril jourdain
// Last update Wed Nov  6 14:11:48 2013 cyril jourdain
//

#ifndef 		__WINDOWMANAGER_HH__
# define 		__WINDOWMANAGER_HH__

#include		<list>
#include		<SFML/Window.hpp>
#include		"Graphic/SFGraphics/Widgets/SFTextBox.hh"
#include		"Graphic/SFGraphics/Widgets/SFButton.hh"
#include		"Graphic/SFGraphics/Widgets/SFWindow.hh"
#include		"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"

class	SFWindow;

class			WindowManager
{

private:
  sf::RenderWindow	*_defaultRenderWindow;
  std::list<SFWidget*>	*_widgetList;
  SFWidget		*_focus;
  std::list<SFWindow *>	*_windowList;
  SFWindow		*_active;
  sf::Event		*_cEvent;
  sf::RenderWindow	*_window;
  bool			_click;
  sf::Vector2f		_size;
  bool			_exit;


public:
  WindowManager();
  virtual ~WindowManager();

public:
  SFWidget		*getFocused() const;
  void			draw() const;
  bool			clickEvent(sf::Event const &);
  void			manageEvent();
  void			addWidget(SFWidget *);
  void			addWindow(SFWindow *);
  void			init();
  void			exec();

public:
  sf::RenderWindow	*getRenderWindow() const;
  void			setRenderWindow(sf::RenderWindow*);

};

#endif
