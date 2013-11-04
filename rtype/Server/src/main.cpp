//
// main.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 12:58:03 2013 laurent ansel
// Last update Wed Oct 30 15:58:43 2013 laurent ansel
//

#include		<string>
#include		<iostream>
#include		<sstream>
#include		"Server/Server.hh"
#include		"Error/SocketError.hpp"

int			main(int argc, char **argv)
{
  if (argc == 2)
    {
      std::string	tmp(argv[1]);
      std::istringstream	str(tmp);
      int		port;

      str >> port;
      try
	{
	  Server		*server = new Server(port);

	  server->run();
	}
      catch (SocketError const &e)
	{
	  std::cerr << e.what() << std::endl;
	  return (-1);
	}
    }
  else
    std::cerr << "Usage:\n\t" << argv[0] << " [port]" << std::endl;
  return (0);
}
