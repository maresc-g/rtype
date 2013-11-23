//
// ClientMain.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Nov  6 12:45:56 2013 cyril jourdain
// Last update Sat Nov 23 18:28:57 2013 cyril jourdain
//

#include		"Graphic/ClientMain.hh"
#include		"Graphic/SFGraphics/Widgets/SFDialogBox.hh"
#include		"Graphic/SFGraphics/Widgets/SFDialogTextBox.hh"
#include		"Map/Map.hh"

static void	*trampoline(void *param)
{
  Client	*tmp = reinterpret_cast<Client *>(param);

  tmp->exec();
  return (NULL);
}

ClientMain::ClientMain()
{
}

ClientMain::~ClientMain()
{
}

ClientMain::ClientMain(ClientMain const &)
{
}

ClientMain	&ClientMain::operator=(ClientMain const &)
{
  return *this;
}

void			ClientMain::init()
{
  _state = new MutexVar<eState>(IN_LOGIN);
  _dir = new FileSystem::Directory(SPRITE_DIR);
  _action = new Action;
  _client = new Client(_dir, _state, _action);
  _client->createThread(&trampoline, _client);
  _manager = new WindowManager();
  _windows = new std::map<unsigned int, SFWindow*>();
  _manager->init();
  (*_windows)[LOGIN] = new LoginWindow();
  (*_windows)[LOBBY] = new LobbyWindow();
  (*_windows)[GAME] = new GameWindow();
  (*_windows)[GAMEOVER] = new GameOverWindow();
  _manager->addWindow(LOBBY,(*_windows)[LOBBY]);
  _manager->addWindow(LOGIN,(*_windows)[LOGIN]);
  _manager->addWindow(GAME,(*_windows)[GAME]);
  // _manager->addWindow(GAMEOVER,(*_windows)[GAMEOVER]);
  _manager->setActiveWindow(LOGIN);
}

void			ClientMain::launch()
{
  _client->start();
  _manager->exec();
  _client->waitThread();
  _client->destroy();
}

void			ClientMain::setState(eState s)
{
  *_state = s;
}

eState			ClientMain::getState() const
{
  return _state->getVar();
}

void			ClientMain::connectToServer(void *param)
{
  if (param)
    {
      LoginWData		*data = reinterpret_cast<LoginWData*>(param);
  
      std::cout << data->adress->getText() << std::endl;
      std::cout << data->port->getText() << std::endl;
      if (!data->adress->getText().empty() && !data->port->getText().empty())
	{
	  *_state = CONNECTING;
	  _client->setConnectInfo(new ConnectInfo(data->adress->getText(), data->port->getText()));
	  while (_state->getVar() == CONNECTING);
	  if (_state->getVar() == CONNECTED)
	    {
	      if (_client->getConnectInfo())
		{
		  _manager->setActiveWindow(LOBBY);
		  _manager->getWindowById(LOGIN)->setVisibility(false);
		  *_state = IN_LOGIN;
		  static_cast<LobbyWindow*>((*_windows)[LOBBY])->refreshGameList(NULL);
		}
	    }
	  else if (_state->getVar() == ERROR_CONNECT)
	    _manager->addWindow(new SFDialogBox("Error", "Could not connect to server"));
	  else
	    _manager->addWindow(new SFDialogBox("Error", "Unknown error"));
	}
      else
	_manager->addWindow(new SFDialogBox("Error", "Please fill server IP and PORT"));
    }
}

void			ClientMain::joinGame(void *)
{
  SFArrayLine		*line = static_cast<LobbyWindow*>((*_windows)[LOBBY])->getSelectedGame(NULL);

  if (line)
    {
      Map::getInstance()->clear();
      *_state = WAIT_GAME;
      int i = std::stoi((*line)["ID"].getData());
      _client->getProto()->protocolMsg(Protocol::JOIN, _client->getId(), &i);
      while (_state->getVar() == WAIT_GAME);
      if (_state->getVar() == PLAYING)
	{
	  _manager->getWindowById(LOBBY)->setVisibility(false);
	  _manager->setFPS(60);
	  _manager->setActiveWindow(GAME);
	}
      else
	{
	  _manager->addWindow(new SFDialogBox("Error", "Unable to launch the game"));
	  *_state = IN_LOBBY;
	}
    }
}

void			ClientMain::createGame(void *)
{
  SFDialogTextBox               *db  = new SFDialogTextBox("Info", "Enter room name");

  _manager->addWindow(db);
  db->setOnCloseCallback(&ClientMain::callCreateGame, this);
}

void			ClientMain::callCreateGame(void *data)
{
  std::string		tmp = reinterpret_cast<SFTextBox *>(data)->getText();

  std::cout << tmp << std::endl;
  if (tmp.size() > 0)
    {
      Map::getInstance()->clear();
      *_state = WAIT_GAME;
      _client->getProto()->protocolMsg(Protocol::CREATE, _client->getId(), &tmp);
      while (_state->getVar() == WAIT_GAME);
      if (_state->getVar() == PLAYING)
	{
	  _manager->setActiveWindow(GAME);
	  _manager->getWindowById(LOBBY)->setVisibility(false);
	}
      else
	{
	  _manager->addWindow(new SFDialogBox("Error", "Unable to launch the game"));
	  *_state = IN_LOBBY;
	}
    }
  else
    _manager->addWindow(new SFDialogBox("Error", "Please fill game name"));
}

void			ClientMain::backToLogin(void *)
{
  _manager->setActiveWindow(LOGIN);
  _client->disconnect();
  // _manager->addWindow(new SFDialogBox("Info", "Remember to disconnect from server"));
}

void			ClientMain::refreshGameList(void *)
{
  _client->getProto()->protocolMsg(Protocol::GET_GAMELIST, _client->getId(), NULL);
  *_state = GAMELIST;
  while (_state->getVar() == GAMELIST)
    ;
  static_cast<LobbyWindow*>((*_windows)[LOBBY])->refreshGameList(NULL);
}


void			ClientMain::sendKeyPress(PressedKey const &keys)
{
  _action->setLeft(keys.left);
  _action->setRight(keys.right);
  _action->setUp(keys.up);
  _action->setDown(keys.down);
  _action->setFire(keys.space);
}

void			ClientMain::quitGame(bool const gameOver, bool const)
{
  Map::getInstance()->clear();
  if (!gameOver)
    _client->getProto()->protocolMsg(Protocol::QUIT_GAME, _client->getId(), NULL);
  else {
    static_cast<GameWindow *>(_manager->getWindowById(GAME))->gameOver();
    sf::sleep(sf::seconds(2));
  }
  *_state = IN_LOBBY;
  _manager->getWindowById(GAME)->setVisibility(false);
  _manager->setFPS(20);
  _manager->setActiveWindow(LOBBY);
  static_cast<GameWindow *>(_manager->getWindowById(GAME))->reset();
  // else
  //   _manager->addWindow(new SFDialogBox("Gameover", (win == true ? "WIN" : "LOOSE")));
}

void			ClientMain::quit()
{
  _client->quit();
}
