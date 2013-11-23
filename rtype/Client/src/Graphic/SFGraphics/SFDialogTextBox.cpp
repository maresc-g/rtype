//
// SFDialogTextBox.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Fri Nov 15 19:38:01 2013 cyril jourdain
// Last update Sun Nov 24 00:19:03 2013 guillaume marescaux
//

#include		"Graphic/SFGraphics/Widgets/SFDialogTextBox.hh"
#include		"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"
#include		"Graphic/Global.hh"
#include		"Graphic/SFGraphics/Widgets/SFConnect.hh"

SFDialogTextBox::SFDialogTextBox(std::string const &name, std::string const &content) :
  SFWindow(sf::FloatRect(0,0,400,150)), _name(name), _content(content)
{
  setStayOnTop(true);
}

SFDialogTextBox::~SFDialogTextBox()
{
}

void			SFDialogTextBox::init()
{
  SFRessourcesManager	*rMan = SFRessourcesManager::getInstance();
  SFConnect		*connect = SFConnect::getInstance();

  _background = new SFImageBox();
  _label = new SFLabel();
  _title = new SFLabel();
  _okButton = new SFButton();
  _closeButton = new SFButton();
  _textBox = new SFTextBox();

  addWidget(_background);
  addWidget(_label);
  addWidget(_title);
  addWidget(_okButton);
  addWidget(_closeButton);
  addWidget(_textBox);

  _background->setTexture((*(rMan->Images))[DIALOGBOX_BACKGROUND]);
  _background->setSize(400, 150);
  _label->setTextSize(18);
  _label->setText(_content);
  _label->setPosition(200 - _label->getBound().width / 2.0, 50);
  _title->setTextSize(17);
  _title->setText(_name);
  _title->setPosition(15,5);
  _okButton->setBackgroundTexture((*(rMan->Images))[DIALOGBOX_OK_BUTTON]);
  _okButton->setSize(100,30);
  _okButton->setPosition(100,112);
  _closeButton->setBackgroundTexture((*(rMan->Images))[DIALOGBOX_CANCEL_BUTTON]);
  _closeButton->setSize(100,30);
  _closeButton->setPosition(200,112);
  _textBox->setPosition(_label->getPosition().x, _label->getPosition().y + _label->getBound().height + 10);
  std::cout << "TEXTBOX_PTR=" << _textBox << std::endl;
  setSize(sf::Vector2f(400,150));
  setPosition(sf::Vector2f(WIN_X / 2 - 200, WIN_Y / 2 - 75));
  updateBound();
  connect->makeConnect(sf::Event::MouseButtonPressed,
		       _okButton,
		       &WindowManager::removeWindowCallback,
		       &_id,
		       _manager);
  connect->makeConnect(sf::Event::MouseButtonPressed,
  		       _closeButton,
  		       &WindowManager::removeWindowNoCallback,
  		       &_id,
  		       _manager);
}
