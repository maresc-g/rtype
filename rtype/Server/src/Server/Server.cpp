//
// Server.cpp for  in /home/ansel_l/Documents/Rtype/work/Server/include
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 20:02:48 2013 laurent ansel
// Last update Tue Oct 29 16:22:57 2013 laurent ansel
//

#include			"Server/Server.hh"

Server::Server():
  _select(new Select)
{
}

Server::~Server()
{
}

void				Server::run()
{
  Socket			*toto = new Socket;

  toto->initialize("TCP");
}
