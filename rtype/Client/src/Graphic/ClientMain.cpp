//
// ClientMain.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Nov  6 12:45:56 2013 cyril jourdain
// Last update Wed Nov  6 17:53:10 2013 guillaume marescaux
//

#include		"Graphic/ClientMain.hh"

ClientMain::ClientMain()
{
}

ClientMain::~ClientMain()
{
}

void			ClientMain::init()
{
  _client = new Client();
  _manager = new WindowManager();
  _windows = new std::map<eWindow, SFWindow*>();
  _manager->init();
  (*_windows)[LOGIN] = new LoginWindow(_client);
  (*_windows)[LOBBY] = new LobbyWindow(_client);
  (*_windows)[LOGIN]->init();
  (*_windows)[LOBBY]->init();
  _manager->addWindow((*_windows)[LOBBY]);
  _manager->addWindow((*_windows)[LOGIN]);
}

void			ClientMain::launch()
{
  _manager->exec();
}
