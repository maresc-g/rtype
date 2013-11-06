//
// ClientMain.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Nov  6 12:37:12 2013 cyril jourdain
// Last update Wed Nov  6 14:09:56 2013 cyril jourdain
//

#ifndef 		__CLIENTMAIN_HH__
# define 		__CLIENTMAIN_HH__

#include		<map>
#include		"Graphic/SFGraphics/Widgets/SFWindow.hh"
#include		"Graphic/Graphics/LoginWindow.hh"
#include		"Graphic/Graphics/LobbyWindow.hh"

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

public:
  ClientMain();
  virtual ~ClientMain();

public:
  void				init();
  void				launch();
};

#endif
