//
// PlayerInfo.hh for yolo in /home/maitre_c/work/rtype/rtype/GameLoop/include/Game
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Mon Nov  4 23:22:19 2013 antoine maitre
// Last update Fri Nov 22 10:19:28 2013 laurent ansel
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
  bool		_inGame;
  std::list<Trame *>	*_msg;
public:
  PlayerInfo(ClientInfo *, int num);
  ~PlayerInfo();
  AEntity	*getPlayer() const;
  void		setPlayer(Player *);
  void		actionPlayer(Map *map, int);
  int		getNum() const;
  void		sendTrame(const std::string &protocol, const std::string &trame);
  bool		isMyInfo(ClientInfo *info) const;
  bool		getIG() const;
  void		setIG(bool b);
  void		quitGame();
  void		pushMsg(std::string const &proto, std::string const &content);
  void		sendMsg();
};

#endif
