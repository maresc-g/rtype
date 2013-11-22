//
// SFDialogTextBox.hh for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Fri Nov 15 19:31:49 2013 cyril jourdain
// Last update Fri Nov 22 15:17:50 2013 guillaume marescaux
//

#ifndef 		__SFDIALOGTEXTBOX_HH__
# define 		__SFDIALOGTEXTBOX_HH__

#include		"Graphic/Graphics/LoginWindow.hh"
#include		"Graphic/SFGraphics/Widgets/SFButton.hh"
#include		"Graphic/SFGraphics/Widgets/SFConnect.hh"

class			SFDialogTextBox : public SFWindow
{
private:
  std::string		_name;
  std::string		_content;
  SFImageBox		*_background;
  SFButton		*_okButton;
  SFButton		*_closeButton;
  SFLabel		*_label;
  SFLabel		*_title;
  SFTextBox		*_textBox;

public:
  virtual void		init();

  template<class T>
  void			setOnCloseCallback(void (T::*func)(void *const),
					   T* target)
  {
    std::cout << "callback from dialog" << std::endl;
    _onCloseCallback = new SFConnect::EventCallback();
    _onCloseCallback->_function = std::bind(func, target, std::placeholders::_1);
    std::cout << "TEXT_BOX IN HH=" << _textBox << std::endl;
    _onCloseCallback->_param = _textBox;
  }

public:
  SFDialogTextBox(std::string const &name, std::string const &content);
  virtual ~SFDialogTextBox();
};


#endif
