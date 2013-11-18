//
// LobbyWindow.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Mon Nov  4 16:14:46 2013 cyril jourdain
// Last update Mon Nov 18 14:48:39 2013 cyril jourdain
//

#include		"Graphic/Graphics/LobbyWindow.hh"
#include		"Graphic/ClientMain.hh"
#include		"Graphic/Global.hh"
#include		"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"
#include		"Game/GameList.hh"
#include		"Game/GameInfo.hh"
#include		"Graphic/SFGraphics/Widgets/SFConnect.hh"

LobbyWindow::LobbyWindow() :
  SFWindow(sf::FloatRect(0,0,WIN_X,WIN_Y))
{

}

LobbyWindow::~LobbyWindow()
{
}

void			LobbyWindow::init()
{
  // _background = addWidget<SFImageBox>();
  // _centerBox = addWidget<SFImageBox>();
  // _joinButton = addWidget<SFButton>();
  // _createButton = addWidget<SFButton>();
  // _refreshButton = addWidget<SFButton>();
  // _backButton = addWidget<SFButton>();
  // _arrayGame = addWidget<SFArray>();

  _background = new SFImageBox();
  _centerBox = new SFImageBox();
  _joinButton = new SFButton();
  _createButton = new SFButton();
  _refreshButton = new SFButton();
  _backButton = new SFButton();
  _arrayGame = new SFArray();
  _arrayBackground = new SFImageBox();

  addWidget(_background);
  addWidget(_centerBox);
  addWidget(_joinButton);
  addWidget(_createButton);
  addWidget(_refreshButton);
  addWidget(_backButton);
  addWidget(_arrayBackground);
  addWidget(_arrayGame);

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
  _refreshButton->setPosition(_createButton->getPosition().x,_centerBox->getBound().height - 40);
  _refreshButton->setSize(130,30);

  _backButton->setPosition(sf::Vector2f(_refreshButton->getPosition().x,
					_refreshButton->getPosition().y +
					_refreshButton->getBound().height + 20));
  _backButton->setSize(130,30);

  _arrayBackground->setTexture((*(SFRessourcesManager::getInstance()->Images))[LOBBY_ARRAY_BACKGROUND]);
  _arrayBackground->setPosition(_centerBox->getPosition().x + 230, _centerBox->getPosition().y + 10);
  _arrayBackground->setSize(_centerBox->getBound().width - 240, _centerBox->getBound().height - 20);
  _arrayGame->setBackgroundTexture((*(SFRessourcesManager::getInstance()->Images))[LOBBY_ARRAY_BACKGROUND]);
  _arrayGame->create((std::list<std::string>){"ID", "NAME", "PLAYERS"});
  _arrayGame->setPosition(_arrayBackground->getPosition().x + 10, _arrayBackground->getPosition().y + 95);
  _arrayGame->setSize(745,478);
  setSize(sf::Vector2f(WIN_X,WIN_Y));
  setVisibility(false);
  updateBound();

  SFConnect::getInstance()->makeConnect(sf::Event::MouseButtonPressed, _refreshButton,
					&ClientMain::refreshGameList, NULL, ClientMain::getInstance());
  SFConnect::getInstance()->makeConnect(sf::Event::MouseButtonPressed, _joinButton,
					&ClientMain::joinGame, NULL,
					ClientMain::getInstance());
  SFConnect::getInstance()->makeConnect(sf::Event::MouseButtonPressed, _createButton,
					&ClientMain::createGame, NULL,
					ClientMain::getInstance());
  SFConnect::getInstance()->makeConnect(sf::Event::MouseButtonPressed, _backButton,
					&ClientMain::backToLogin, NULL,
					ClientMain::getInstance());
}

void				LobbyWindow::refreshGameList(void *const)
{
  std::list<GameInfo*>		list = GameList::getInstance()->getGames();
  int				i = 0;

  _arrayGame->clear();
  for (auto it = list.begin(); it != list.end(); it++)
    {
      _arrayGame->addLine();
      (*_arrayGame)[i]["ID"].setText((*it)->getId());
      (*_arrayGame)[i]["NAME"].setText((*it)->getName());
      (*_arrayGame)[i]["PLAYERS"].setText((*it)->getNbPlayer());
      i++;
    }
}

SFArrayLine			*LobbyWindow::getSelectedGame(void *const) const
{
  if (_arrayGame)
    return (_arrayGame->getSelected());
  return NULL;
}

/* ARRAY SEGFAULT ON UNEXISTING INDEX */
