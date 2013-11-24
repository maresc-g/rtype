//
// Server.hh for  in /home/ansel_l/Documents/Rtype/work/Server/include
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 20:01:50 2013 laurent ansel
// Last update Sun Nov 24 14:11:13 2013 laurent ansel
//

#ifndef 			__SERVER_HH__
# define 			__SERVER_HH__

//#define DEBUG_SERVER

#include			<map>
#include			<string>
#include			"Socket/Socket.hpp"
#include			"Mutex/Mutex.hpp"
#include			"Thread/Thread.hpp"
#include			"Select/Select.hh"
#include			"ClientInfo/ClientInfo.hh"
#include			"DynamicLibrary/DynamicLibraryUpdater.hh"

class				Server
{
private:
  unsigned int			_clientId;
  std::map<std::string, Socket *>	*_socket;
  Select			*_select;
  std::list<ClientInfo *>	*_client;
public:
  Server(int const port);
  virtual ~Server();
  void				run();
private:
  void				initializeSelect() const;
  void				newClient();
  void				recvTrameUdp();
  void				readAndWriteClient();
  std::list<ClientInfo *>::iterator	&deleteClient(std::list<ClientInfo *>::iterator &it);
  void				execCommand();
  void				debug(std::string const &str) const;
  void				quitAllClient() const;
  bool				manageGame(std::list<ClientInfo *>::iterator &it, Action &action);
  bool				manageQuit(std::list<ClientInfo *>::iterator &it, Action &action);
  bool				manageSprite(std::list<ClientInfo *>::iterator &it, Action &action);
  void				sendSprite(ClientInfo *client, std::string const &sprite, std::string const &proto);
  void				sendListSprite(ClientInfo *client);
};

#endif
