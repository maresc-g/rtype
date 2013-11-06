//
// Client.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Oct 29 16:28:26 2013 guillaume marescaux
// Last update Wed Nov  6 17:37:42 2013 guillaume marescaux
//

#ifndef 		__CLIENT_HH__
# define 		__CLIENT_HH__

#include		<map>
#include		"Socket/Socket.hpp"
#include		"Socket/SocketClient.hpp"
#include		"Select/Select.hh"
#include		"CircularBufferManager/CircularBufferManager.hh"
#include		"Core/Protocol.hh"
#include		"Thread/Thread.hpp"
#include		"Core/ConnectInfo.hh"

class			Client : public Thread
{
public:

  enum			eSocket
    {
      TCP,
      UDP
    };

private:

  // Attributes
  std::map<Protocol::eProtocol, void(Client::*)(Trame const &)>	*_ptrs;
  std::map<eSocket, Socket *>		*_sockets;
  std::map<eSocket, SocketClient *>	*_socketsClient;
  Select		*_select;
  Protocol		*_protocol;
  int			_id;
  ConnectInfo		*_info;

public:

  // Ctor / Dtor
  Client();
  virtual ~Client();

  // Methods
  bool			initialize(void);
  void			destroy(void);
  void			loop(void);
  void			write(void);
  void			read(long const sec, long const usec, bool timeout);
  void			exec(void);

private:

  // Private Methods
  void			writeToSocket(Trame const &trame, eSocket sock);
  void			readFromSocket(eSocket sock);
  static std::map<std::string, std::string>	initMapGameList(void);

  void			welcome(Trame const &trame);
  void			gamelist(Trame const &trame);
  void			ok(Trame const &trame);
  void			ko(Trame const &trame);
  void			launchGame(Trame const &trame);
  void			map(Trame const &trame);
  void			entity(Trame const &trame);
  void			scroll(Trame const &trame);
  void			dead(Trame const &trame);
  void			endGame(Trame const &trame);
};

#endif
