//
// GameWindow.hh for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Nov 16 17:36:41 2013 cyril jourdain
// Last update Sat Nov 16 19:07:11 2013 cyril jourdain
//

#ifndef 		__GAMEWINDOW_HH__
# define 		__GAMEWINDOW_HH__

#include		"Graphic/SFGraphics/Widgets/SFWindow.hh"
#include		"Graphic/SFGraphics/Widgets/SFImageBox.hh"
#include		"Graphic/Graphics/GameView.hh"

class			GameWindow : public SFWindow
{
private:
  SFImageBox		*_HUDBar;
  GameView		*_gameView;

public:
  GameWindow();
  virtual ~GameWindow();

public:
  void			init();
};

#endif
