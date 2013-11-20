//
// PlayerInfo.cpp for rtype in /home/maitre_c/work/rtype/rtype/GameLoop
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Mon Nov  4 23:27:06 2013 antoine maitre
// Last update Wed Nov 20 16:05:22 2013 antoine maitre
//

#include		"SpriteLoaderManager/SpriteLoaderManager.hh"
#include		"ObjectPoolManager/ObjectPoolManager.hh"
#include "GameLoop/PlayerInfo.hh"

PlayerInfo::PlayerInfo(ClientInfo *info, int num)
  : _info(info), _num(num), _inGame(true)
{
  // std::string path = "Res/Sprites/player.conf";
  // _player = new Player(20, 40, path, 1, true);
  _player = reinterpret_cast<Player *>(ObjectPoolManager::getInstance()->getCopy(AEntity::PLAYER));
  if (_player)
    {
      SpriteLoaderManager::getInstance()->getEntitySprite("player", *_player);
      _player->setInvincible(40);
    }
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

  if (adv < map->getPosX())
    this->_player->move(coord->getX() + 1, coord->getY());
  if (this->_info->standbyCommand())
    {
      const Command	*cmd = this->_info->getFirstCommand();
      if (cmd)
	{
	  Action	act = cmd->getAction();

	  (void)map;
	  if (this->_player->getInvincible() > 0)
	    this->_player->setInvincible(this->_player->getInvincible() - 1);
	  if (act.getUp())
	    {
	      act.setUp(false);
	      this->_player->move(this->_player->getPosX(), this->_player->getPosY() - this->_player->getSpeed());
	      if (this->_player->getPosY() < 0)
		this->_player->move(this->_player->getPosX(), 0);
	    }
	  if (act.getDown())
	    {
	      act.setDown(false);
	      this->_player->move(this->_player->getPosX(), this->_player->getPosY() + this->_player->getSpeed());
	      if (this->_player->getPosY() >= SCREENY - this->_player->getHeight())
		this->_player->move(this->_player->getPosX(), SCREENY - this->_player->getHeight());
	    }
	  if (act.getLeft())
	    {
	      act.setLeft(false);
	      this->_player->move(this->_player->getPosX() - this->_player->getSpeed(), this->_player->getPosY());
	      if (this->_player->getPosX() <  adv)
		this->_player->move(adv, this->_player->getPosY());
	    }
	  if (act.getRight())
	    {
	      act.setRight(false);
	      this->_player->move(this->_player->getPosX() + this->_player->getSpeed(), this->_player->getPosY());
	      if (this->_player->getPosX() > adv + SCREENX - this->_player->getWidth())
		this->_player->move(adv + SCREENX - this->_player->getWidth(), this->_player->getPosY());
	    }
	  if (act.getFire())
	    {
	      const Coordinate spawn = this->_player->getSpawnProjectile();
	      act.setFire(false);
	      map->getPlayers().push_back(new Rocket(spawn.getX(), spawn.getY(), "Res/Sprites/rocket.conf", 5, true, 1, 0));
	    }
	  this->_info->setAction(act);
	}
    }
}

int		PlayerInfo::getNum() const
{
  return (this->_num);
}


void		PlayerInfo::sendTrame(const std::string &protocol, const std::string &msg)
{
  Trame		*t = new Trame(this->_info->getId(), this->_info->getTrameId(), protocol, msg, true);

  this->_info->pushWriteTrame(protocol, t);
}

bool		PlayerInfo::isMyInfo(ClientInfo *info) const
{
  if (this->_info == info)
    return (true);
  return (false);
}

bool		PlayerInfo::getIG() const
{
  return (this->_inGame);
}

void		PlayerInfo::setIG(bool b)
{
  this->_inGame = b;
}
