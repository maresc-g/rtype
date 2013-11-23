//
// GameOverWindow.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sun Nov  3 23:37:40 2013 cyril jourdain
// Last update Sat Nov 23 12:52:56 2013 guillaume marescaux
//

#ifndef 		__GAMEOVERWINDOW_HH__
# define 		__GAMEOVERWINDOW_HH__

#include		"Graphic/SFGraphics/Widgets/SFWindow.hh"
#include		"Graphic/SFGraphics/Widgets/SFImageBox.hh"
#include		"Core/Client.hh"

class			GameOverWindow : public SFWindow
{
private:
  SFImageBox		*_background;

public:
  GameOverWindow();
  virtual ~GameOverWindow();

public:
  virtual void		init();
};

#endif
