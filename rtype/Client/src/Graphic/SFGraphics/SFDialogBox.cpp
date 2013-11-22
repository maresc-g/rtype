//
// SFDialogBox.cpp for  in /home/jourda_c/Documents/C++/RType
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Thu Nov  7 16:47:22 2013 cyril jourdain
// Last update Fri Nov 22 15:10:49 2013 guillaume marescaux
//

#include		"Graphic/SFGraphics/Widgets/SFDialogBox.hh"
#include		"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"
#include		"Graphic/Global.hh"
#include		"Graphic/SFGraphics/Widgets/SFConnect.hh"

SFDialogBox::SFDialogBox(std::string const &name, std::string const &content,
			 bool okButton) :
  SFWindow(sf::FloatRect(0,0,400,150)), _name(name), _content(content), _okButton(okButton)
{
  setStayOnTop(true);
}

SFDialogBox::~SFDialogBox()
{
}

void			SFDialogBox::init()
{
  SFRessourcesManager	*rMan = SFRessourcesManager::getInstance();
  SFConnect		*connect = SFConnect::getInstance();

  _background = new SFImageBox();
  _label = new SFLabel();
  _title = new SFLabel();
  _closeButton = new SFButton();

  addWidget(_background);
  addWidget(_label);
  addWidget(_title);
  addWidget(_closeButton);

  _background->setTexture((*(rMan->Images))[DIALOGBOX_BACKGROUND]);
  _background->setSize(400, 150);
  _label->setTextSize(18);
  _label->setText(_content);
  _label->setPosition(200 - _label->getBound().width / 2.0, 50);
  _title->setTextSize(17);
  _title->setText(_name);
  _title->setPosition(15,5);
  // if (_okButton)
  //   {
  _closeButton->setBackgroundTexture((*(rMan->Images))[DIALOGBOX_OK_BUTTON]);
  _closeButton->setSize(100,30);
  _closeButton->setPosition(150,112);
    // }
  setSize(sf::Vector2f(400,150));
  setPosition(sf::Vector2f(WIN_X / 2 - 200, WIN_Y / 2 - 75));
  updateBound();
  connect->makeConnect(sf::Event::MouseButtonPressed,
		       _closeButton,
		       &WindowManager::removeWindowCallback,
		       &_id,
		       _manager);
}
