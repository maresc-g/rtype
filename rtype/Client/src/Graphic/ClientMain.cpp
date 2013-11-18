//
// ClientMain.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Nov  6 12:45:56 2013 cyril jourdain
// Last update Mon Nov 18 10:36:13 2013 cyril jourdain
//

#include		"Graphic/ClientMain.hh"
#include		"Graphic/SFGraphics/Widgets/SFDialogBox.hh"
#include		"Graphic/SFGraphics/Widgets/SFDialogTextBox.hh"

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
  _state = IN_LOGIN;
  _dir = new FileSystem::Directory(SPRITE_DIR);
  _client = new Client(_dir, &_state);
  _client->createThread(&trampoline, _client);
  _manager = new WindowManager();
  _windows = new std::map<unsigned int, SFWindow*>();
  _manager->init();
  (*_windows)[LOGIN] = new LoginWindow();
  (*_windows)[LOBBY] = new LobbyWindow();
  (*_windows)[GAME] = new GameWindow();
  _manager->addWindow(LOBBY,(*_windows)[LOBBY]);
  _manager->addWindow(LOGIN,(*_windows)[LOGIN]);
  _manager->addWindow(GAME,(*_windows)[GAME]);
  _manager->setActiveWindow(LOBBY);
}

void			ClientMain::launch()
{
  // _client->start();
  _manager->exec();
  _client->waitThread();
  _client->destroy();
}

void			ClientMain::setState(eState s)
{
  _state = s;
}

eState			ClientMain::getState() const
{
  return _state;
}

void			ClientMain::connectToServer(void *param)
{
  sf::Clock		clock;

  if (param)
    {
      LoginWData		*data = reinterpret_cast<LoginWData*>(param);
  
      std::cout << data->adress->getText() << std::endl;
      std::cout << data->port->getText() << std::endl;
      if (!data->adress->getText().empty() && !data->port->getText().empty())
	{
	  _client->setConnectInfo(new ConnectInfo(data->adress->getText(), data->port->getText()));
	  clock.restart();
	  while (clock.getElapsedTime().asSeconds() < 1);
	  if (_client->getConnectInfo())
	    {
	      _manager->setActiveWindow(LOBBY);
	      _manager->getWindowById(LOGIN)->setVisibility(false);
	      _state = eState::IN_LOBBY;
	      static_cast<LobbyWindow*>((*_windows)[LOBBY])->refreshGameList(NULL);
	    }
	  else
	    _manager->addWindow(new SFDialogBox("Error", "Could not connect to server"));
	}
      else
	_manager->addWindow(new SFDialogBox("Error", "Please fill server IP and PORT"));
    }
}

void			ClientMain::joinGame(void *)
{
  //_manager->addWindow(new SFDialogBox("Info", "Join a game"));
  /* Need to do server stuff */
  _manager->setActiveWindow(GAME);
  _manager->getWindowById(LOBBY)->setVisibility(false);
}

void			ClientMain::createGame(void *)
{
  SFDialogTextBox               *db  = new SFDialogTextBox("Info", "Enter room name");

  _manager->addWindow(db);
  db->setOnCloseCallback(&ClientMain::backToLogin, this); //Need to change callback
}

void			ClientMain::backToLogin(void *)
{
  _manager->setActiveWindow(LOGIN);
  _manager->addWindow(new SFDialogBox("Info", "Remember to disconnect from server"));
}

void			ClientMain::refreshGameList(void *)
{
  static_cast<LobbyWindow*>((*_windows)[LOBBY])->refreshGameList(NULL);
}
