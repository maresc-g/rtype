//
// LoginWindow.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sun Nov  3 19:22:13 2013 cyril jourdain
// Last update Thu Nov  7 14:12:16 2013 cyril jourdain
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

struct			LoginWData
{
  SFTextBox		*adress;
  SFTextBox		*port;
};

class			LoginWindow : public SFWindow
{
private:
  LoginWData		*_data;
  SFImageBox		*_background;
  SFImageBox		*_loginBackground;
  SFTextBox		*_tbAddress;
  SFTextBox		*_tbPort;
  SFButton		*_bConnect;
  SFLabel		*_label;
  SFLabel		*_labelPort;

public:
  LoginWindow();
  virtual ~LoginWindow();

public:
  virtual void		init();
};

#endif
