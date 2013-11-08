//
// LobbyWindow.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sun Nov  3 23:37:40 2013 cyril jourdain
// Last update Thu Nov  7 14:11:12 2013 cyril jourdain
//

#ifndef 		__LOBBYWINDOW_HH__
# define 		__LOBBYWINDOW_HH__

#include		"Graphic/SFGraphics/Widgets/SFWindow.hh"
#include		"Graphic/SFGraphics/Widgets/SFTextBox.hh"
#include		"Graphic/SFGraphics/Widgets/SFImageBox.hh"
#include		"Graphic/SFGraphics/Widgets/SFButton.hh"
#include		"Core/Client.hh"

class			LobbyWindow : public SFWindow
{
private:
  SFImageBox		*_background;
  SFImageBox		*_centerBox;
  SFButton		*_joinButton;
  SFButton		*_createButton;
  SFButton		*_refreshButton;
  SFButton		*_backButton;

public:
  LobbyWindow();
  virtual ~LobbyWindow();

public:
  virtual void		init();
};

#endif
