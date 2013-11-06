//
// LoginWindow.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sun Nov  3 19:22:13 2013 cyril jourdain
// Last update Wed Nov  6 17:51:17 2013 guillaume marescaux
//

#ifndef 		__LOGINWINDOW_HH__
# define 		__LOGINWINDOW_HH__

#include		"Graphic/Global.hh"
#include		"Graphic/SFGraphics/Widgets/SFWindow.hh"
#include		"Graphic/SFGraphics/Widgets/SFTextBox.hh"
#include		"Graphic/SFGraphics/Widgets/SFLabel.hh"
#include		"Graphic/SFGraphics/Widgets/SFImageBox.hh"
#include		"Graphic/SFGraphics/Widgets/SFButton.hh"
#include		"Core/Client.hh"

class			LoginWindow : public SFWindow
{
private:
  SFImageBox		*_background;
  SFImageBox		*_loginBackground;
  SFTextBox		*_tbAddress;
  SFButton		*_bConnect;
  SFLabel		*_label;
  Client const		*_client;

public:
  LoginWindow(Client const *client);
  virtual ~LoginWindow();

public:
  virtual void		init();
};

#endif
