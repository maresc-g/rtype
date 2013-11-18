//
// PlayerInfo.hh for yolo in /home/maitre_c/work/rtype/rtype/GameLoop/include/Game
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Mon Nov  4 23:22:19 2013 antoine maitre
// Last update Mon Nov 18 15:19:34 2013 arthur rucquois
//

#ifndef		__PLAYERINFO_HH__
# define	__PLAYERINFO_HH__

#include	"Entities/Player.hh"
#include	"ClientInfo/ClientInfo.hh"
#include	"Action/Action.hh"
#include	"Level/Map.hh"
#include	"Entities/Weapon/Rocket.hh"

class		PlayerInfo
{
  Player	*_player;
  ClientInfo	*_info;
  int		_num;
public:
  PlayerInfo(ClientInfo *, int num);
  ~PlayerInfo();
  AEntity	*getPlayer() const;
  void		actionPlayer(Map *map, int);
  int		getNum() const;
  void		sendTrame(const std::string &protocol, const std::string trame);
};

#endif
