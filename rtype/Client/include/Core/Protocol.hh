//
// Protocol.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Fri Nov  1 13:33:27 2013 guillaume marescaux
// Last update Sat Nov 23 23:05:34 2013 guillaume marescaux
//

#ifndef 		__PROTOCOL_HH__
# define 		__PROTOCOL_HH__

#include		<map>
#include		"Socket/SocketClient.hpp"
#include		"CircularBufferManager/CircularBufferManager.hh"

class			Protocol
{
public:

  enum			eProtocol
    {
      INITIALIZE,
      GET_GAMELIST,
      JOIN,
      CREATE,
      ACTION,
      GET_SPRITE,
      QUIT_GAME,
      QUIT_SERVER,
      WELCOME,
      CHECK,
      GAMELIST,
      OK,
      KO,
      LAUNCHGAME,
      MAP,
      ENTITY,
      SCORE,
      SCROLL,
      LOSTLIFE,
      DEAD,
      REMOVE_ENTITY,
      ENDGAME,
      SPRITE,
      CONTENTFILE,
      LEVELUP,
      SERVERQUITTED,
      END
    };

private:

  // Attributes
  std::map<eProtocol, void(Protocol::*)(int const, void *)>	*_ptrs;
  std::map<std::string, eProtocol>				*_equivalent;
  int								_trameId;

public:
  // Ctor / Dtor
  Protocol();
  virtual ~Protocol();

private:
  Protocol(Protocol const &);
  Protocol		&operator=(Protocol const &);

  // Private Methods
  void			initialize(int const id, void *data);
  void			getGamelist(int const id, void *data);
  void			join(int const id, void *data);
  void			create(int const id, void *data);
  void			action(int const id, void *data);
  void			getSprite(int const id, void *data);
  void			quitGame(int const id, void *data);
  void			quitServer(int const id, void *data);

public:

  // Methods
  void			protocolMsg(eProtocol proto, int const id, void *data);
  eProtocol		getMsg(Trame *trame);
};

#endif
