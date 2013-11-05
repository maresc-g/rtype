//
// Client.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Oct 29 16:28:26 2013 guillaume marescaux
// Last update Mon Nov  4 16:43:23 2013 guillaume marescaux
//

#ifndef 		__CLIENT_HH__
# define 		__CLIENT_HH__

#include		<map>
#include		"Socket/Socket.hpp"
#include		"Socket/SocketClient.hpp"
#include		"Select/Select.hh"
#include		"CircularBufferManager/CircularBufferManager.hh"
#include		"Core/Protocol.hh"

class			Client
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

public:

  // Ctor / Dtor
  Client();
  virtual ~Client();

  // Methods
  void			initialize(void);
  void			destroy(void);
  void			loop(void);
  void			write(void);
  void			read(long const sec, long const usec, bool timeout);

private:

  // Private Methods
  void			writeToSocket(Trame const &trame, eSocket sock);
  void			readFromSocket(eSocket sock);

  void			welcome(Trame const &trame);
  void			getGamelist(Trame const &trame);
  void			ok(Trame const &trame);
  void			ko(Trame const &trame);
  void			launchGame(Trame const &trame);
  void			map(Trame const &trame);
  void			enemy(Trame const &trame);
  void			projectile(Trame const &trame);
  void			player(Trame const &trame);
  void			scroll(Trame const &trame);
  void			dead(Trame const &trame);
  void			endGame(Trame const &trame);
};

#endif
