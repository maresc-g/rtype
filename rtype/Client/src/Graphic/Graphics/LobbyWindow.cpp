//
// LobbyWindow.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Mon Nov  4 16:14:46 2013 cyril jourdain
// Last update Thu Nov  7 14:33:36 2013 cyril jourdain
//

#include		"Graphic/Graphics/LobbyWindow.hh"
#include		"Graphic/Global.hh"
#include		"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"

LobbyWindow::LobbyWindow() :
  SFWindow(sf::FloatRect(0,0,WIN_X,WIN_Y))
{

}

LobbyWindow::~LobbyWindow()
{
}

void			LobbyWindow::init()
{
  _background = addWidget<SFImageBox>();
  _centerBox = addWidget<SFImageBox>();
  _joinButton = addWidget<SFButton>();
  _createButton = addWidget<SFButton>();
  _refreshButton = addWidget<SFButton>();
  _backButton = addWidget<SFButton>();

  // Textures
  _background->setTexture((*(SFRessourcesManager::getInstance()->Images))[LOBBY_BACKGROUND]);
  _joinButton->setBackgroundTexture((*(SFRessourcesManager::getInstance()->Images))[LOBBY_JOIN_BUTTON]);
  _centerBox->setTexture((*(SFRessourcesManager::getInstance()->Images))[LOBBY_CENTER_BOX]);
  _createButton->setBackgroundTexture((*(SFRessourcesManager::getInstance()->Images))
				      [LOBBY_CREATE_BUTTON]);
  _refreshButton->setBackgroundTexture((*(SFRessourcesManager::getInstance()->Images))
				       [LOBBY_REFRESH_BUTTON]);
  _backButton->setBackgroundTexture((*(SFRessourcesManager::getInstance()->Images))[LOBBY_BACK_BUTTON]);
  // ~Texture
  _background->setSize(WIN_X,WIN_Y);
  _centerBox->setSize(1000,600);
  _centerBox->setPosition(WIN_X / 2 - _centerBox->getBound().width / 2,
			  WIN_Y / 2 - _centerBox->getBound().height / 2);

  _joinButton->setPosition(sf::Vector2f(_centerBox->getPosition().x + 45,
					_centerBox->getPosition().y + 50));
  _joinButton->setSize(130,30);

  _createButton->setPosition(sf::Vector2f(_joinButton->getPosition().x,
					  _joinButton->getPosition().y +
					  _joinButton->getBound().height + 20));
  _createButton->setSize(130,30);
  _refreshButton->setPosition(_createButton->getPosition().x,_centerBox->getBound().height - 20);
  _refreshButton->setSize(130,30);

  _backButton->setPosition(sf::Vector2f(_refreshButton->getPosition().x,
					_refreshButton->getPosition().y + 40));
  _backButton->setSize(130,30);

  setSize(sf::Vector2f(WIN_X,WIN_Y));
  setVisibility(false);
  updateBound();
}
