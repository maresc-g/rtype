//
// main.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Fri Oct 25 11:18:47 2013 guillaume marescaux
// Last update Wed Nov  6 20:24:25 2013 cyril jourdain
//

#include	"Socket/Socket.hpp"
#include	"Game/GameList.hh"
#include	"Core/Client.hh"
#include	"Error/IError.hh"
#include	"Graphic/ClientMain.hh"

static void	*trampoline(void *param)
{
  Client	*tmp = reinterpret_cast<Client *>(param);

  tmp->exec();
  return (NULL);
}

int		main()
{
  // Client	*client = new Client;

  // client->createThread(&trampoline, client);
  // client->start();
  // client->waitThread();
  // client->destroy();
  // delete client;
  ClientMain	*clientMain = new ClientMain;

  clientMain->init();
  clientMain->launch();
  return (0);
}
