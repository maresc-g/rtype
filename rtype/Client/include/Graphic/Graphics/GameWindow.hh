//
// GameWindow.hh for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Nov 16 17:36:41 2013 cyril jourdain
// Last update Sun Nov 17 23:06:10 2013 cyril jourdain
//

#ifndef 		__GAMEWINDOW_HH__
# define 		__GAMEWINDOW_HH__

#include		<vector>
#include		"Graphic/SFGraphics/Widgets/SFWindow.hh"
#include		"Graphic/SFGraphics/Widgets/SFImageBox.hh"
#include		"Graphic/SFGraphics/Widgets/SFLabel.hh"
#include		"Graphic/Graphics/GameView.hh"

class			GameWindow : public SFWindow
{
private:
  SFImageBox		*_HUDBar;
  GameView		*_gameView;
  SFLabel		*_score;
  std::vector<SFImageBox*>	*_lives;

public:
  GameWindow();
  virtual ~GameWindow();

public:
  void			init();
};

#endif
