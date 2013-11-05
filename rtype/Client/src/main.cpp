//
// main.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Fri Oct 25 11:18:47 2013 guillaume marescaux
// Last update Mon Nov  4 13:57:51 2013 guillaume marescaux
//

#include	"Socket/Socket.hpp"
#include	"Game/GameList.hh"
#include	"Core/Client.hh"

int		main()
{
  Client	*client = new Client;

  client->initialize();
  client->destroy();
  delete client;
  return (0);
}
