//
// ClientMain.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Nov  6 12:45:56 2013 cyril jourdain
// Last update Sun Nov 24 23:22:31 2013 guillaume marescaux
//

#include		<sstream>
#include		"Graphic/ClientMain.hh"
#include		"Graphic/SFGraphics/Widgets/SFDialogBox.hh"
#include		"Graphic/SFGraphics/Widgets/SFDialogTextBox.hh"
#include		"Map/Map.hh"
#include		"Sound/SoundManager.hh"
#include		"Sound/Sounds.hh"

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
  _clock = new sf::Clock;
  (*_windows)[LOGIN] = new LoginWindow();
  (*_windows)[LOBBY] = new LobbyWindow();
  (*_windows)[GAME] = new GameWindow();
  (*_windows)[LOBBY]->setVisibility(false);
  (*_windows)[GAME]->setVisibility(false);
  (*_windows)[GAMEOVER] = new GameOverWindow();
  _manager->addWindow(LOBBY,(*_windows)[LOBBY]);
  _manager->addWindow(LOGIN,(*_windows)[LOGIN]);
  _manager->addWindow(GAME,(*_windows)[GAME]);
  // _manager->addWindow(GAMEOVER,(*_windows)[GAMEOVER]);
  _manager->setActiveWindow(LOGIN);
  SoundManager::getInstance()->loadDefaultSounds();
  SoundManager::getInstance()->playMusic(LOBBY_MUSIC);
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

int			ClientMain::getClientLife() const
{
  return _client->getLife();
}

int			ClientMain::getClientScore() const
{
  return _client->getScore();
}

void			ClientMain::connectToServer(void *param)
{
  if (param)
    {
      LoginWData		*data = reinterpret_cast<LoginWData*>(param);
  
      if (!data->adress->getText().empty() && !data->port->getText().empty())
	{
	  *_state = CONNECTING;
	  _client->setConnectInfo(new ConnectInfo(data->adress->getText(), data->port->getText()));
	  _clock->restart();
	  while (_state->getVar() == CONNECTING) waitServ(IN_LOGIN, ERROR_CONNECT);
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
	    {
	      *_state = IN_LOGIN;
	      _manager->addWindow(new SFDialogBox("Error", "Could not connect to server"));
	    }
	  // else
	  //   _manager->addWindow(new SFDialogBox("Error", "Unknown error"));
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
      _clock->restart();
      while (_state->getVar() == WAIT_GAME) waitServ(IN_LOBBY, IN_LOBBY);
      if (_state->getVar() == PLAYING)
	{
	  _manager->getWindowById(LOBBY)->setVisibility(false);
	  _manager->setFPS(40);
	  _manager->setActiveWindow(GAME);
	  SoundManager::getInstance()->pauseMusic(LOBBY_MUSIC);
	  SoundManager::getInstance()->playMusic(GAME_MUSIC);
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

  if (tmp.size() > 0)
    {
      Map::getInstance()->clear();
      *_state = WAIT_GAME;
      _client->getProto()->protocolMsg(Protocol::CREATE, _client->getId(), &tmp);
      _clock->restart();
      while (_state->getVar() == WAIT_GAME) waitServ(IN_LOGIN, IN_LOGIN);
      if (_state->getVar() == PLAYING)
	{
	  _manager->setActiveWindow(GAME);
	  _manager->getWindowById(LOBBY)->setVisibility(false);
	  _manager->setFPS(40);
	  SoundManager::getInstance()->pauseMusic(LOBBY_MUSIC);
	  SoundManager::getInstance()->playMusic(GAME_MUSIC);
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
  _clock->restart();
  while (_state->getVar() == GAMELIST) waitServ(IN_LOBBY, IN_LOGIN);
  static_cast<LobbyWindow*>((*_windows)[LOBBY])->refreshGameList(NULL);
}


void			ClientMain::sendKeyPress(PressedKey const &keys)
{

  _action->setLeft(keys.left);
  _action->setRight(keys.right);
  _action->setUp(keys.up);
  _action->setDown(keys.down);
  _action->setFire(keys.space);
  if (keys.space)
    SoundManager::getInstance()->playSound(SHOT1);
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
  SoundManager::getInstance()->stopMusic(GAME_MUSIC);
  SoundManager::getInstance()->playMusic(LOBBY_MUSIC);
  // else
  //   _manager->addWindow(new SFDialogBox("Gameover", (win == true ? "WIN" : "LOOSE")));
}

void			ClientMain::quit()
{
  _client->quit();
}

void			ClientMain::waitServ(eState, eState newState)
{
  int time = _clock->getElapsedTime().asSeconds();
  if (time >= 5)
    {
      *_state = newState;
      _manager->addWindow(new SFDialogBox("Error", "Server timeout"));
      quit();
    }
}
