//
// ClientMain.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Nov  6 12:37:12 2013 cyril jourdain
// Last update Thu Nov  7 13:51:35 2013 cyril jourdain
//

#ifndef 		__CLIENTMAIN_HH__
# define 		__CLIENTMAIN_HH__

#include		<map>
#include		"Graphic/SFGraphics/Widgets/SFWindow.hh"
#include		"Graphic/Graphics/LoginWindow.hh"
#include		"Graphic/Graphics/LobbyWindow.hh"
#include		"Core/Client.hh"
#include		"Utility/Singleton.hpp"

class			ClientMain : public Singleton<ClientMain>
{
  friend class		Singleton<ClientMain>;

private:
  WindowManager			*_manager;
  Client			*_client;
  std::map<unsigned int, SFWindow *>	*_windows;

private:
  ClientMain();
  ClientMain(ClientMain const &);
  ClientMain	&operator=(ClientMain const &);
  virtual ~ClientMain();

public:
  void				init();
  void				launch();
  Client			*getClient(void) const;

public:
  
  // ClientMain to Client functions / callbacks event
  void				connectToServer(void *param);
};

#endif
