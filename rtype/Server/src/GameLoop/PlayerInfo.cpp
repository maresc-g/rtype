//
// PlayerInfo.cpp for rtype in /home/maitre_c/work/rtype/rtype/GameLoop
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Mon Nov  4 23:27:06 2013 antoine maitre
// Last update Sun Nov 24 18:34:33 2013 laurent ansel
//

#include		"SpriteLoaderManager/SpriteLoaderManager.hh"
#include		"ObjectPoolManager/ObjectPoolManager.hh"
#include		"GameLoop/PlayerInfo.hh"

PlayerInfo::PlayerInfo(ClientInfo *info, int num):
  _info(info),
  _num(num),
  _inGame(true),
  _msg(new std::list<Trame *>)
{
  // std::string path = "Res/Sprites/player.conf";
  // _player = new Player(20, 40, path, 1, true);
  _player = reinterpret_cast<Player *>(ObjectPoolManager::getInstance()->getCopy(AEntity::PLAYER));
  if (_player)
    {
      std::ostringstream str;

      str << "player" << num;
      SpriteLoaderManager::getInstance()->getEntitySprite(str.str(), *_player);
      _player->setInvincible(50);
      _player->setNum(num);
    }
}

PlayerInfo::~PlayerInfo()
{
  if (_msg)
    {
      for (auto it = this->_msg->begin() ; it != this->_msg->end() ; ++it)
	if ((*it))
	  delete (*it);
      delete this->_msg;
    }
  if (_player)
    delete _player;
}

void		PlayerInfo::setInfo(ClientInfo *info)
{
  this->_info = info;
}

AEntity		*PlayerInfo::getPlayer() const
{
  return (this->_player);
}

void		PlayerInfo::actionPlayer(Map *map, int adv, unsigned int &id)
{
  if (this->_info)
    {
      if (this->_player->getInvincible() > 0)
	this->_player->setInvincible(this->_player->getInvincible() - 1);
      if (this->_info->standbyCommand(ClientInfo::GAME) && this->_inGame)
	{
	  const Command	*cmd = this->_info->getFirstCommand(ClientInfo::GAME);
	  if (cmd)
	    {
	      Action	&act = cmd->getAction();

	      (void)map;
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
		  if (this->_player->getPosY() >= SCREENY * 10 - this->_player->getWidth())
		    this->_player->move(this->_player->getPosX(), SCREENY * 10 - this->_player->getWidth());
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
		  if (this->_player->getPosX() > adv + SCREENX * 10 - this->_player->getHeight())
		    this->_player->move(adv + SCREENX * 10 - this->_player->getHeight(), this->_player->getPosY());
		}
	      if (act.getFire())
		{
		  const Coordinate spawn = this->_player->getSpawnProjectile();
		  AEntity		*projectile;

		  act.setFire(false);
		  projectile = ObjectPoolManager::getInstance()->getCopy(AEntity::ROCKET);
		  if (projectile)
		    {
		      SpriteLoaderManager::getInstance()->getEntitySprite("rocket.gif", *projectile);
		      projectile->setId(id);
		      id++;
		      projectile->movePos(this->_player->getPosX() + spawn.getX(), this->_player->getPosY() + spawn.getY());
		      map->getPlayers().push_back(projectile);
		      static_cast<Rocket *>(projectile)->whoIsMyDaddy(this->_player);
		    }
		}
	      this->_info->setAction(act, ClientInfo::GAME);
	    }
	}
    }
}

int		PlayerInfo::getNum() const
{
  return (this->_num);
}


void		PlayerInfo::sendTrame(const std::string &protocol, const std::string &msg)
{
  if (this->_info)
    {
      Trame		*t = new Trame(this->_info->getId(), this->_info->getTrameId(), protocol, msg, true);

      this->_info->pushWriteTrame(protocol, t);
    }
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

void		PlayerInfo::quitGame()
{
  if (this->_info)
    this->_info->quitGame();
}

void		PlayerInfo::pushMsg(std::string const &proto, std::string const &content)
{
  if (_msg && this->_info)
    {
      if (!this->_msg->empty() && proto == this->_msg->back()->getHeader().getProto())
	  this->_msg->back()->appendContent("|" + content);
      else
	{
	  Trame		*trame = new Trame(this->_info->getId(), this->_info->getTrameId(), proto, content);

	  if (!this->_msg->empty())
	    this->_msg->back()->appendContent(END_TRAME);
	  this->_msg->push_back(trame);
	}
    }
}

void		PlayerInfo::sendMsg()
{
  if (_msg &&& this->_info)
    {
      for (auto it = this->_msg->begin() ; it != this->_msg->end() ; ++it)
	{
	  if (!(*it)->isSetEndTrame())
	    (*it)->appendContent(END_TRAME);
	  this->_info->pushWriteTrame((*it)->getHeader().getProto(), (*it));
	}
      this->_msg->clear();
    }
}

void		PlayerInfo::deleteMsg()
{
  if (_msg)
    {
      for (auto it = this->_msg->begin() ; it != this->_msg->end() ; ++it)
	if ((*it))
	  delete (*it);
      delete this->_msg;
    }
  _msg = NULL;
}
