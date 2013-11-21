//
// PlayerInfo.cpp for rtype in /home/maitre_c/work/rtype/rtype/GameLoop
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Mon Nov  4 23:27:06 2013 antoine maitre
// Last update Thu Nov 21 15:25:30 2013 laurent ansel
//

#include		"SpriteLoaderManager/SpriteLoaderManager.hh"
#include		"ObjectPoolManager/ObjectPoolManager.hh"
#include		"GameLoop/PlayerInfo.hh"

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
      _player->setNum(num);
    }
}

PlayerInfo::~PlayerInfo()
{

}

AEntity		*PlayerInfo::getPlayer() const
{
  return (this->_player);
}

bool		PlayerInfo::actionPlayer(Map *map, int adv)
{
  bool		ret = false;
  const Coordinate	*coord = this->_player->getCoord();

  if (this->_info->standbyCommand())
    {
      const Command	*cmd = this->_info->getFirstCommand();
      if (cmd)
  	{
	  Action	&act = cmd->getAction();

  	  (void)map;
  	  if (this->_player->getInvincible() > 0)
  	    this->_player->setInvincible(this->_player->getInvincible() - 1);
  	  if (act.getUp())
  	    {
	      ret = true;
  	      act.setUp(false);
  	      this->_player->move(this->_player->getPosX(), this->_player->getPosY() - this->_player->getSpeed());
  	      if (this->_player->getPosY() < 0)
  	      	this->_player->move(this->_player->getPosX(), 0);
  	    }
  	  if (act.getDown())
  	    {
	      ret = true;
  	      act.setDown(false);
  	      this->_player->move(this->_player->getPosX(), this->_player->getPosY() + this->_player->getSpeed());
  	      if (this->_player->getPosY() >= SCREENY * 10 - this->_player->getHeight())
  	      	this->_player->move(this->_player->getPosX(), SCREENY * 10 - this->_player->getHeight());
  	    }
  	  if (act.getLeft())
  	    {
	      ret = true;
  	      act.setLeft(false);
  	      this->_player->move(this->_player->getPosX() - this->_player->getSpeed(), this->_player->getPosY());
  	      if (this->_player->getPosX() <  adv)
  	      	this->_player->move(adv, this->_player->getPosY());
  	    }
  	  if (act.getRight())
  	    {
	      ret = true;
  	      act.setRight(false);
  	      this->_player->move(this->_player->getPosX() + this->_player->getSpeed(), this->_player->getPosY());
  	      if (this->_player->getPosX() > adv + SCREENX * 10 - this->_player->getWidth())
  	      	this->_player->move(adv + SCREENX * 10 - this->_player->getWidth(), this->_player->getPosY());
  	    }
  	  if (act.getFire())
  	    {
	      ret = true;
  	      const Coordinate spawn = this->_player->getSpawnProjectile();
  	      AEntity		*projectile;

  	      act.setFire(false);
  	      projectile = ObjectPoolManager::getInstance()->getCopy(AEntity::ROCKET);
  	      if (projectile)
  		{
  		  SpriteLoaderManager::getInstance()->getEntitySprite("rocket", *projectile);
  		  projectile->movePos(this->_player->getPosX(), this->_player->getPosY());
		  map->getPlayers().push_back(projectile);
  		}
  	    }
	  this->_info->setAction(act);
  	}
    }
  return (ret);
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
