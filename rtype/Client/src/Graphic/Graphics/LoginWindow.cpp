//
// LoginWindow.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Nov  6 14:12:11 2013 cyril jourdain
// Last update Wed Nov  6 17:51:54 2013 guillaume marescaux
//

#include			"Graphic/Graphics/LoginWindow.hh"
#include			"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"
#include			"Graphic/SFGraphics/Widgets/SFConnect.hh"

LoginWindow::LoginWindow(Client const *client) :
  SFWindow(sf::FloatRect(0,0,WIN_X, WIN_Y)), _client(client)
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
  _bConnect = addWidget<SFButton>();
  _label = addWidget<SFLabel>();

  _background->setSize(WIN_X, WIN_Y);
  _background->setTexture((*(rMan->Images))[LOGIN_BACKGROUND]);
  _loginBackground->setSize(250,120);
  _loginBackground->setPosition(WIN_X / 2.0 - _loginBackground->getBound().width / 2.0,
				WIN_Y / 2.0 - _loginBackground->getBound().height / 2.0);
  _loginBackground->setTexture((*(rMan->Images))[LOGIN_BACKGROUND_BOX]);
  _tbAddress->setPosition(_loginBackground->getPosition().x + 30,
			 _loginBackground->getPosition().y + 30);
  _tbAddress->setBoxSize(_loginBackground->getBound().width - 50);
  _label->setText("Server address :");
  _label->setPosition(_tbAddress->getPosition().x, _tbAddress->getPosition().y - 20);
  _bConnect->setSize(100,30);
  _bConnect->setPosition(_tbAddress->getPosition().x, _tbAddress->getPosition().y + 30);
  _bConnect->setBackgroundTexture((*(rMan->Images))[LOGIN_BUTTON_IMAGE]);
  setPosition(sf::Vector2f(0,0));
  setSize(sf::Vector2f(WIN_X,WIN_Y));
  updateBound();

  /* TEST ONLY */

  connect->makeConnect(sf::Event::MouseButtonPressed,
		       _bConnect,
		       &SFButton::test,
		       _tbAddress,
		       _bConnect);
  /**/
}
