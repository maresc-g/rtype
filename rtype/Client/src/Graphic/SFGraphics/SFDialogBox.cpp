//
// SFDialogBox.cpp for  in /home/jourda_c/Documents/C++/RType
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Thu Nov  7 16:47:22 2013 cyril jourdain
// Last update Thu Nov  7 17:49:23 2013 cyril jourdain
//

#include		"Graphic/SFGraphics/Widgets/SFDialogBox.hh"
#include		"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"
#include		"Graphic/Global.hh"
#include		"Graphic/SFGraphics/Widgets/SFConnect.hh"

SFDialogBox::SFDialogBox(std::string const &name, std::string const &content, unsigned int id) :
  SFWindow(sf::FloatRect(0,0,400,150)), _name(name), _content(content), _id(id)
{
}

SFDialogBox::~SFDialogBox()
{
}

void			SFDialogBox::init()
{
  SFRessourcesManager	*rMan = SFRessourcesManager::getInstance();
  SFConnect		*connect = SFConnect::getInstance();

  _background = addWidget<SFImageBox>();
  _closeButton = addWidget<SFButton>();
  _label = addWidget<SFLabel>();
  _background->setTexture((*(rMan->Images))[LOGIN_BACKGROUND_BOX]);
  _background->setSize(400, 150);
  _closeButton->setBackgroundTexture((*(rMan->Images))[LOGIN_BUTTON_IMAGE]);
  _closeButton->setSize(100,40);
  _closeButton->setPosition(150,90);
  _label->setTextSize(18);
  _label->setText(_content);
  _label->setPosition(200 - _label->getBound().width / 2.0, 40);
  setSize(sf::Vector2f(400,150));
  updateBound();

  connect->makeConnect(sf::Event::MouseButtonPressed,
		       _closeButton,
		       &WindowManager::removeWindowCallback,
		       &_id,
		       _manager);  

}
