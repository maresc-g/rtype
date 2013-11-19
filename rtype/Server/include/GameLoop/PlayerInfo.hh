//
// PlayerInfo.hh for yolo in /home/maitre_c/work/rtype/rtype/GameLoop/include/Game
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Mon Nov  4 23:22:19 2013 antoine maitre
// Last update Tue Nov 19 13:57:51 2013 laurent ansel
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
private:
  Player	*_player;
  ClientInfo	*_info;
  int		_num;

public:
  PlayerInfo(ClientInfo *, int num);
  ~PlayerInfo();
  AEntity	*getPlayer() const;
  void		actionPlayer(Map *map, int);
  int		getNum() const;
  void		sendTrame(const std::string &protocol, const std::string &trame);
  bool		isMyInfo(ClientInfo *info) const;
};

#endif
