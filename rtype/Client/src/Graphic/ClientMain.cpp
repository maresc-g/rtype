//
// ClientMain.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Nov  6 12:45:56 2013 cyril jourdain
// Last update Thu Nov  7 17:48:33 2013 cyril jourdain
//

#include		"Graphic/ClientMain.hh"
#include		"Graphic/SFGraphics/Widgets/SFDialogBox.hh"

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
  _client = new Client();
  // _client->createThread(&trampoline, _client);
  _manager = new WindowManager();
  _windows = new std::map<unsigned int, SFWindow*>();
  _manager->init();
  (*_windows)[LOGIN] = new LoginWindow();
  (*_windows)[LOBBY] = new LobbyWindow();
  (*_windows)[2] = new SFDialogBox("toto", "Error : Window not initialized", 2);
  (*_windows)[LOGIN]->init();
  (*_windows)[LOBBY]->init();
  (*_windows)[2]->init();
  _manager->addWindow(LOBBY,(*_windows)[LOBBY]);
  _manager->addWindow(LOGIN,(*_windows)[LOGIN]);
  _manager->addWindow(2,(*_windows)[2]);
  //_manager->setActiveWindow(LOGIN);
}

void			ClientMain::launch()
{
  // _client->start();
  _manager->exec();
  _client->waitThread();
  _client->destroy();
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
	      _manager->getWindowById(LOBBY)->setVisibility(true);
	    }
	}
    }
}
