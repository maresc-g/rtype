//
// PlayerInfo.cpp for rtype in /home/maitre_c/work/rtype/rtype/GameLoop
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Mon Nov  4 23:27:06 2013 antoine maitre
// Last update Wed Nov 13 14:41:46 2013 antoine maitre
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

AEntity		*PlayerInfo::getPlayer() const
{
  return (this->_player);
}

void		PlayerInfo::actionPlayer(Map *map, int adv)
{
  const Coordinate	*coord = this->_player->getCoord();
  const Command	*cmd = this->_info->getFirstCommand();
  Action	act = cmd->getAction();

  (void)map;
  this->_player->move(coord->getX() + 1, coord->getY());
  if (act.getUp())
    {
      act.setUp(false);
      this->_player->move(coord->getX(), coord->getY() - this->_player->getSpeed());
      if (coord->getY() < 0)
	this->_player->move(coord->getX(), 0);
    }
  if (act.getDown())
    {
      act.setDown(false);
      this->_player->move(coord->getX(), coord->getY() + this->_player->getSpeed());
      if (coord->getY() >= SCREENY - this->_player->getLargeur())
	this->_player->move(coord->getX(), SCREENY - this->_player->getLargeur());
    }
  if (act.getLeft())
    {
      act.setLeft(false);
      this->_player->move(coord->getX() - this->_player->getSpeed(), coord->getY());
      if (coord->getX() <  adv)
	this->_player->move(adv, coord->getY());
    }
  if (act.getRight())
    {
      act.setRight(false);
      this->_player->move(coord->getX() + this->_player->getSpeed(), coord->getY());
      if (coord->getX() > adv + SCREENX - this->_player->getLongueur())
	this->_player->move(adv + SCREENX - this->_player->getLongueur(), coord->getY());
    }
  if (act.getFire())
    {
      act.setFire(false);
    }
}
