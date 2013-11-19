//
// ClientMain.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Nov  6 12:45:56 2013 cyril jourdain
// Last update Mon Nov 18 17:20:40 2013 guillaume marescaux
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
  _state = new MutexVar<eState>(IN_LOGIN);
  _dir = new FileSystem::Directory(SPRITE_DIR);
  _client = new Client(_dir, _state);
  _client->createThread(&trampoline, _client);
  _manager = new WindowManager();
  _windows = new std::map<unsigned int, SFWindow*>();
  _action = new Action;
  _manager->init();
  (*_windows)[LOGIN] = new LoginWindow();
  (*_windows)[LOBBY] = new LobbyWindow();
  (*_windows)[GAME] = new GameWindow();
  _manager->addWindow(LOBBY,(*_windows)[LOBBY]);
  _manager->addWindow(LOGIN,(*_windows)[LOGIN]);
  _manager->addWindow(GAME,(*_windows)[GAME]);
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
  _state->setVar(s);
}

eState			ClientMain::getState() const
{
  return _state->getVar();
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
	      _state->setVar(eState::IN_LOBBY);
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
  SFArrayLine		*line = static_cast<LobbyWindow*>((*_windows)[LOBBY])->getSelectedGame(NULL);

  //_manager->addWindow(new SFDialogBox("Info", "Join a game"));
  /* Need to do server stuff */
  if (line)
    {
      int i = std::stoi((*line)["ID"].getData());
      _client->getProto()->protocolMsg(Protocol::JOIN, _client->getId(), &i);
    }
  // _manager->setActiveWindow(GAME);
  // _manager->getWindowById(LOBBY)->setVisibility(false);
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
  _client->getProto()->protocolMsg(Protocol::CREATE, _client->getId(), &tmp);
}

void			ClientMain::backToLogin(void *)
{
  _manager->setActiveWindow(LOGIN);
  _manager->addWindow(new SFDialogBox("Info", "Remember to disconnect from server"));
}

void			ClientMain::refreshGameList(void *)
{
  _client->getProto()->protocolMsg(Protocol::GAMELIST, _client->getId(), NULL);
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
