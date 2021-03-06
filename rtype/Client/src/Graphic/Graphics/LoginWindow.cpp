//
// LoginWindow.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Nov  6 14:12:11 2013 cyril jourdain
// Last update Sun Nov 24 21:10:00 2013 cyril jourdain
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
  if (_background)
    delete _background;
  if (_loginBackground)
    delete _loginBackground;
  if (_tbAddress)
    delete _tbAddress;
  if (_tbPort)
    delete _tbPort;
  if (_bConnect)
    delete _bConnect;
  if (_label)
    delete _label;
  if (_labelPort)
    delete _labelPort;
}

void		LoginWindow::init()
{
  SFRessourcesManager	*rMan = SFRessourcesManager::getInstance();
  SFConnect *connect = SFConnect::getInstance();

  _background = new SFImageBox();
  _loginBackground = new SFImageBox();
  _tbAddress = new SFTextBox();
  _tbPort = new SFTextBox();
  _bConnect = new SFButton();
  _label = new SFLabel();
  _labelPort = new SFLabel();

  addWidget(_background);
  addWidget(_loginBackground);
  addWidget(_tbAddress);
  addWidget(_tbPort);
  addWidget(_bConnect);
  addWidget(_label);
  addWidget(_labelPort);

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

  connect->makeConnect(sf::Event::MouseButtonPressed,
		       _bConnect,
		       &ClientMain::connectToServer,
		       _data,
		       ClientMain::getInstance());
  /**/
}
