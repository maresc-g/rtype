//
// GameWindow.hh for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Nov 16 17:36:41 2013 cyril jourdain
// Last update Sat Nov 23 23:28:56 2013 cyril jourdain
//

#ifndef 		__GAMEWINDOW_HH__
# define 		__GAMEWINDOW_HH__

#include		<vector>
#include		"Graphic/SFGraphics/Widgets/SFWindow.hh"
#include		"Graphic/SFGraphics/Widgets/SFImageBox.hh"
#include		"Graphic/SFGraphics/Widgets/SFLabel.hh"
#include		"Graphic/Graphics/GameView.hh"
#include		"Graphic/Graphics/GameHud.hh"
#include		"Graphic/Graphics/GameOver.hh"

class			GameWindow : public SFWindow
{
private:
  GameView		*_gameView;
  GameHud		*_gameHud;
  GameOver		*_gameOver;

public:
  GameWindow();
  virtual ~GameWindow();

public:
  void			init();
  virtual void		update();
  void			reset();
  void			gameOver();
};

#endif
