//
// PlayerInfo.cpp for rtype in /home/maitre_c/work/rtype/rtype/GameLoop
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Mon Nov  4 23:27:06 2013 antoine maitre
// Last update Wed Nov  6 14:49:23 2013 antoine maitre
//

#include "GameLoop/PlayerInfo.hh"

PlayerInfo::PlayerInfo(ClientInfo *info, int num)
  : _info(info), _num(num)
{
  std::string path = "";
  _player = new Player(20, 40, path, 1, true);
}

PlayerInfo::~PlayerInfo()
{

}

Player		*PlayerInfo::getPlayer() const
{
  return (this->_player);
}

void		PlayerInfo::actionPlayer(Map *map, int adv)
{
  const Coordinate	*coord = this->_player->getCoord();
  const Command	*cmd = this->_info->getFirstCommand();
  Action	act = cmd->getAction();

  if (act.getUp())
    {
      act.setUp(false);
      if (coord->getY() > 0)
	this->_player->move(coord->getX(), coord->getY() - 1);
    }
  if (act.getDown())
    {
      act.setDown(false);
      if (coord->getX() < map->getPosY())
	this->_player->move(coord->getX(), coord->getY() + 1);
    }
  if (act.getLeft())
    {
      act.setLeft(false);
      if (coord->getX() >= adv)
	this->_player->move(coord->getX() - 1, coord->getY());
    }
  if (act.getRight())
    {
      act.setRight(false);
      if (coord->getX() < adv + 80)
	this->_player->move(coord->getX() + 1, coord->getY());
    }
  if (act.getFire())
    {
      act.setFire(false);
    }
}
