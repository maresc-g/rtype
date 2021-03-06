//
// SFDialogBox.hh for  in /home/jourda_c/Documents/C++/RType
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Thu Nov  7 16:32:11 2013 cyril jourdain
// Last update Fri Nov 15 19:32:05 2013 cyril jourdain
//

#ifndef 		__SFDIALOGBOX_HH__
# define 		__SFDIALOGBOX_HH__

#include		"Graphic/Graphics/LoginWindow.hh"
#include		"Graphic/SFGraphics/Widgets/SFButton.hh"

class			SFDialogBox : public SFWindow
{
private:
  std::string		_name;
  std::string		_content;
  bool			_okButton;
  SFImageBox		*_background;
  SFButton		*_closeButton;
  SFLabel		*_label;
  SFLabel		*_title;

public:
  virtual void			init();

public:
  SFDialogBox(std::string const &name, std::string const &content, bool okButton = true);
  virtual ~SFDialogBox();
};

#endif
