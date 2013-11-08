//
// WindowManager.hh for  in /home/jourda_c/Documents/C++/RType/Sources/include
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Oct 23 00:00:35 2013 cyril jourdain
// Last update Thu Nov  7 17:38:56 2013 cyril jourdain
//

#ifndef 		__WINDOWMANAGER_HH__
# define 		__WINDOWMANAGER_HH__

#include		<list>
#include		<map>
#include		<SFML/Window.hpp>
#include		"Graphic/SFGraphics/Widgets/SFTextBox.hh"
#include		"Graphic/SFGraphics/Widgets/SFButton.hh"
#include		"Graphic/SFGraphics/Widgets/SFWindow.hh"
#include		"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"

class	SFWindow;

class			WindowManager
{

private:
  typedef std::list<std::pair<unsigned int, SFWindow*>>	WindowList;

  sf::RenderWindow	*_defaultRenderWindow;
  std::list<SFWidget*>	*_widgetList;
  SFWidget		*_focus;
  WindowList		*_windowList;
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
  void			tabEvent();
  void			shiftTabEvent();
  void			manageEvent();
  void			addWidget(SFWidget *);
  void			addWindow(unsigned int const id, SFWindow *);
  void			init();
  void			exec();

public:
  sf::RenderWindow	*getRenderWindow() const;
  void			setRenderWindow(sf::RenderWindow*);
  void			setActiveWindow(unsigned int const id);
  SFWindow		*getWindowById(unsigned int const id) const;
  void			removeWindowById(unsigned int const id);
  void			removeWindowCallback(void *param);

private:
  void			setFocusedWindow(sf::Event const &mouse);

};

#endif
