//
// main.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Thu Oct 24 12:58:03 2013 laurent ansel
// Last update Wed Nov 20 09:41:32 2013 laurent ansel
//

#include		<string>
#include		<iostream>
#include		<sstream>
#include		<stdexcept>
#include		"Server/Server.hh"
#include		"Error/SocketError.hpp"

int			main(int argc, char **argv)
{
  int			ret = 0;

  if (argc == 2)
    {
      try
	{
	  int			port = std::stoi(argv[1]);
	  Server		*server = new Server(port);

	  server->run();
	  delete server;
	}
      catch (std::invalid_argument const &e)
	{
	  std::cerr << "Invalid port" << std::endl;
	  ret = 2;
	}
      catch (SocketError const &e)
	{
	  std::cerr << e.what() << std::endl;
	  ret = 3;
	}
    }
  else
    {
      std::cerr << "Usage:\n\t" << argv[0] << " [port]" << std::endl;
      ret = 1;
    }
  return (ret);
}
