//
// main.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Fri Oct 25 11:18:47 2013 guillaume marescaux
// Last update Fri Nov 22 15:49:46 2013 guillaume marescaux
//

#include	"Socket/Socket.hpp"
#include	"Game/GameList.hh"
#include	"Core/Client.hh"
#include	"Error/IError.hh"
#include	"Graphic/ClientMain.hh"

int		main()
{
  ClientMain	*clientMain = ClientMain::getInstance();

  clientMain->init();
  clientMain->launch();
  return (0);
}
