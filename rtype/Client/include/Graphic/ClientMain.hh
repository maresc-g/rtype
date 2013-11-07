//
// ClientMain.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Nov  6 12:37:12 2013 cyril jourdain
// Last update Wed Nov  6 17:45:51 2013 guillaume marescaux
//

#ifndef 		__CLIENTMAIN_HH__
# define 		__CLIENTMAIN_HH__

#include		<map>
#include		"Graphic/SFGraphics/Widgets/SFWindow.hh"
#include		"Graphic/Graphics/LoginWindow.hh"
#include		"Graphic/Graphics/LobbyWindow.hh"
#include		"Core/Client.hh"

class			ClientMain
{
  enum			eWindow
    {
      LOGIN,
      LOBBY,
      GAME
    };

private:
  WindowManager			*_manager;
  std::map<eWindow, SFWindow *>	*_windows;
  Client			*_client;

public:
  ClientMain();
  virtual ~ClientMain();

public:
  void				init();
  void				launch();

  Client			*getClient(void) const;
};

#endif
