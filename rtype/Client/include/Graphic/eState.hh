//
// eState.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Sat Nov 16 14:34:19 2013 guillaume marescaux
// Last update Tue Nov 19 13:41:00 2013 guillaume marescaux
//

#ifndef 		__ESTATE_HH__
# define 		__ESTATE_HH__

enum			eState
  {
    IN_LOGIN,
    IN_LOBBY,
    WAIT_GAME,
    PLAYING,
    GAMELIST,
    LEVEL_UP,
    CONNECTING,
    CONNECTED,
    ERROR_CONNECT
  };


#endif
