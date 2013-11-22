//
// Client.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Oct 29 16:28:26 2013 guillaume marescaux
// Last update Fri Nov 22 12:39:15 2013 guillaume marescaux
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
#include		"Graphic/SFGraphics/Widgets/SFTextBox.hh"
#include		"Mutex/MutexVar.hpp"
#include		"FileSystem/Directory.hh"
#include		"Graphic/eState.hh"
#include		"Action/Action.hh"

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
  Select				*_select;
  Protocol				*_protocol;
  int					_id;
  MutexVar<ConnectInfo *>		*_info;
  MutexVar<bool>			*_running;
  MutexVar<bool>			*_initialized;
  FileSystem::Directory			*_dir;
  std::list<std::string>		*_diffDir;
  MutexVar<eState>			*_state;
  Action				*_action;

public:

  // Ctor / Dtor
  Client(FileSystem::Directory *dir, MutexVar<eState> *_state, Action *action);
  virtual ~Client();

  // Methods
  bool			initialize(void);
  void			destroy(void);
  void			loop(void);
  void			write(void);
  void			read(long const sec, long const usec, bool timeout);
  void			exec(void);
  void			disconnect(void);
  std::list<Trame *>	*splitCommand(Trame const &trame);

  // Getters / Setters
  void			setConnectInfo(ConnectInfo *info);
  ConnectInfo		*getConnectInfo() const;
  void			setRunning(bool const running);
  bool			getRunning(void) const;
  void			setInitialized(bool const initialized);
  bool			getInitialized(void) const;
  Protocol		*getProto(void) const;
  int			getId(void) const;

private:

  // Private Methods
  void			writeToSocket(Trame const &trame, eSocket sock);
  void			readFromSocket(eSocket sock);
  static std::map<std::string, std::string>	initMapGameList(void);
  static std::map<std::string, std::string>	initMapGetMap(void);

  void			welcome(Trame const &trame);
  void			gamelist(Trame const &trame);
  void			ko(Trame const &trame);
  void			launchGame(Trame const &trame);
  void			map(Trame const &trame);
  void			entity(Trame const &trame);
  void			scroll(Trame const &trame);
  void			dead(Trame const &trame);
  void			removeEntity(Trame const &trame);
  void			sprite(Trame const &trame);
  void			contentFile(Trame const &trame);
  void			levelUp(Trame const &trame);
  void			endGame(Trame const &trame);
  void			serverQuit(Trame const &trame);
};

#endif
