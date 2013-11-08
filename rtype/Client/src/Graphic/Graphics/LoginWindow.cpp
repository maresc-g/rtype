//
// LoginWindow.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Nov  6 14:12:11 2013 cyril jourdain
// Last update Thu Nov  7 17:39:29 2013 cyril jourdain
//

#include			"Graphic/Graphics/LoginWindow.hh"
#include			"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"
#include			"Graphic/SFGraphics/Widgets/SFConnect.hh"
#include			"Graphic/ClientMain.hh"

LoginWindow::LoginWindow() :
  SFWindow(sf::FloatRect(0,0,WIN_X, WIN_Y)), _data(new LoginWData)
{
}

LoginWindow::~LoginWindow()
{
}

void		LoginWindow::init()
{
  SFRessourcesManager	*rMan = SFRessourcesManager::getInstance();
  SFConnect *connect = SFConnect::getInstance();

  _background = addWidget<SFImageBox>();
  _loginBackground = addWidget<SFImageBox>();
  _tbAddress = addWidget<SFTextBox>();
  _tbPort = addWidget<SFTextBox>();
  _bConnect = addWidget<SFButton>();
  _label = addWidget<SFLabel>();
  _labelPort = addWidget<SFLabel>();
  _data->adress = _tbAddress;
  _data->port = _tbPort;

  _background->setSize(WIN_X, WIN_Y);
  _background->setTexture((*(rMan->Images))[LOGIN_BACKGROUND]);
  _loginBackground->setSize(360,140);
  _loginBackground->setPosition(WIN_X / 2.0 - _loginBackground->getBound().width / 2.0,
				WIN_Y / 2.0 - _loginBackground->getBound().height / 2.0);
  _loginBackground->setTexture((*(rMan->Images))[LOGIN_BACKGROUND_BOX]);
  _tbAddress->setPosition(_loginBackground->getPosition().x + 110,
			 _loginBackground->getPosition().y + 30);
  _tbAddress->setBoxSize(_loginBackground->getBound().width - 95 - 50);
  _tbPort->setPosition(_tbAddress->getPosition().x, _tbAddress->getPosition().y + 30);
  _tbPort->setBoxSize(50);
  _label->setText("Server address :");
  _label->setPosition(_tbAddress->getPosition().x - 100, _tbAddress->getPosition().y);
  _labelPort->setText("Server port :");
  _labelPort->setPosition(_tbPort->getPosition().x - 100, _tbPort->getPosition().y);
  _bConnect->setSize(100,30);
  _bConnect->setPosition(_tbPort->getPosition().x, _tbPort->getPosition().y + 30);
  _bConnect->setBackgroundTexture((*(rMan->Images))[LOGIN_BUTTON_IMAGE]);
  setSize(sf::Vector2f(WIN_X,WIN_Y));
  updateBound();
  /* TEST ONLY */

  connect->makeConnect(sf::Event::MouseButtonPressed,
		       _bConnect,
		       &ClientMain::connectToServer,
		       _data,
		       ClientMain::getInstance());
  /**/
}
