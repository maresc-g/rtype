//
// PlayerInfo.hh for yolo in /home/maitre_c/work/rtype/rtype/GameLoop/include/Game
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Mon Nov  4 23:22:19 2013 antoine maitre
// Last update Mon Nov  4 23:54:44 2013 antoine maitre
//

#ifndef		__PLAYERINFO_HH__
# define	__PLAYERINFO_HH__

#include	"Entities/AEntity.hh"
#include	"ClientInfo/ClientInfo.hh"

class		PlayerInfo
{
  AEntity	*_player;
  ClientInfo	*_info;
public:
  PlayerInfo(ClientInfo *);
  ~PlayerInfo();
};

#endif
