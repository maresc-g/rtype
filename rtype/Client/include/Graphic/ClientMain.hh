//
// ClientMain.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Nov  6 12:37:12 2013 cyril jourdain
// Last update Sat Nov 16 14:35:54 2013 guillaume marescaux
//

#ifndef 		__CLIENTMAIN_HH__
# define 		__CLIENTMAIN_HH__

class			Client;

#include		<map>
#include		"Graphic/SFGraphics/Widgets/SFWindow.hh"
#include		"Graphic/Graphics/LoginWindow.hh"
#include		"Graphic/Graphics/LobbyWindow.hh"
#include		"Core/Client.hh"
#include		"Utility/Singleton.hpp"
#include		"FileSystem/Directory.hh"
#include		"eState.hh"

#define			SPRITE_DIR	"Res/Sprites"

class			ClientMain : public Singleton<ClientMain>
{
  friend class		Singleton<ClientMain>;

private:
  WindowManager			*_manager;
  Client			*_client;
  std::map<unsigned int, SFWindow *>	*_windows;
  eState			_state;
  FileSystem::Directory		*_dir;

private:
  ClientMain();
  ClientMain(ClientMain const &);
  ClientMain	&operator=(ClientMain const &);
  virtual ~ClientMain();

public:
  void				init();
  void				launch();
  Client			*getClient(void) const;
  void				setState(eState);
  eState			getState() const;

public:  
  // ClientMain to Client functions / callbacks event
  void				connectToServer(void *param);
  void				joinGame(void *param);
  void				createGame(void *param);
  void				backToLogin(void *param);
};

#endif
