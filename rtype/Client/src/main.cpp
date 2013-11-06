//
// main.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Fri Oct 25 11:18:47 2013 guillaume marescaux
// Last update Wed Nov  6 14:17:41 2013 cyril jourdain
//

#include	"Socket/Socket.hpp"
#include	"Game/GameList.hh"
#include	"Core/Client.hh"
#include	"Graphic/ClientMain.hh"

int		main()
{
  //Client	*client = new Client;
  ClientMain	*cMain = new ClientMain();

  //client->initialize();
  //client->destroy();
  cMain->init();
  cMain->launch();
  //delete client;
  return (0);
}
