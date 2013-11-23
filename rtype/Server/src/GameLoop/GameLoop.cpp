//
// GameLoop.cpp for game in /home/maitre_c/work/local/rtype/code/src/GameLoop
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:49:55 2013 antoine maitre
// Last update Sat Nov 23 22:35:43 2013 antoine maitre
//

#include		<time.h>
#include		"GameLoop/GameLoopManager.hh"
#include		"SpriteLoaderManager/SpriteLoaderManager.hh"
#include		"GameLoop/GameLoop.hh"

GameLoop::GameLoop(std::string const &name, unsigned int const id):
  Thread(),
  _library(&DynamicLibraryManager::getInstance()->getGameLibrariesCopy()),
  _clients(new std::list<PlayerInfo *>),
  _rate(20),
  _name(name),
  _id(id),
  _criticalError(false),
  _mutex(new Mutex),
  _idEntity(0)
{
  this->_mutex->initialize();
  this->_library->loadLibraries();
}

GameLoop::~GameLoop()
{
  this->_mutex->destroy();
  delete this->_mutex;
}

void			GameLoop::Initialize()
{
  this->_levelManag = new LevelManager();
  this->_levelManag->Initialize();
}

void			GameLoop::scrolling()
{
  this->_levelManag->incAdv();
  this->_mutex->enter();
  for (auto it = this->_levelManag->getPlayers().begin(); it != this->_levelManag->getPlayers().end(); ++it)
    if ((*it)->getType() == AEntity::PLAYER)
      (*it)->movePos((*it)->getPosX() + 1, (*it)->getPosY());
  this->_mutex->leave();
}

void			GameLoop::action() const
{
  for (auto it = this->_levelManag->getPlayers().begin(); it != this->_levelManag->getPlayers().end(); ++it)
    if ((*it)->getType() != AEntity::PLAYER)
      {
	(static_cast<AProjectile *>(*it))->move();
	this->sendEntity((*it));
      }
  for (auto it = this->_levelManag->getEnemies().begin(); it != this->_levelManag->getEnemies().end(); ++it)
    if ((*it)->getType() != AEntity::MOB && (*it)->getType() != AEntity::WALL)
      {
	(static_cast<AProjectile *>(*it))->move();
	this->sendEntity((*it));
      }

}

void			GameLoop::execAction(Action const &act, AEntity *entity, int const, Map *map)
{
  if (act.getUp())
    {
      entity->move(entity->getPosX(), entity->getPosY() - entity->getSpeed());
    }
  if (act.getDown())
    {
      entity->move(entity->getPosX(), entity->getPosY() + entity->getSpeed());
    }
  if (act.getLeft())
    {
      entity->move(entity->getPosX() - entity->getSpeed(), entity->getPosY());
    }
  if (act.getRight())
    {
      entity->move(entity->getPosX() + entity->getSpeed(), entity->getPosY());
    }
  if (act.getFire())
    {
      const Coordinate spawn = entity->getSpawnProjectile();
      AProjectile	*projectile;
      int		vx;
      int		vy;

      projectile = reinterpret_cast<AProjectile *>(ObjectPoolManager::getInstance()->getCopy(AEntity::ROCKET));
      if (projectile)
	{
	  entity->getProjectileVector(vx, vy);
	  projectile->setVector(vx, vy);
	  SpriteLoaderManager::getInstance()->getEntitySprite("rocket", *projectile);
	  projectile->setId(_idEntity);
	  _idEntity++;
	  projectile->movePos(entity->getPosX(), entity->getPosY());
	  map->getEnemies().push_back(projectile);
	  std::cout << "POS = " << map->getPlayers().size() << std::endl;
	}
    }

}

void			GameLoop::moveAllEntities(bool &SuperVaisseau)
{
  this->_mutex->enter();
  for (auto it = this->_levelManag->getPlayers().begin(); it != this->_levelManag->getPlayers().end(); ++it)
    if ((*it)->moveToPixel())
      {
	this->sendEntity((*it));
	SuperVaisseau = true;
      }
  this->_mutex->leave();
  for (auto it = this->_levelManag->getEnemies().begin(); it != this->_levelManag->getEnemies().end(); ++it)
    if ((*it)->moveToPixel())
      this->sendEntity((*it));
}

void			GameLoop::removeEntities()
{
  this->_mutex->enter();
  this->destroyDeadEntities(this->_levelManag->getEnemies(),
			    this->_levelManag->getPlayers());
  this->_mutex->leave();
}

void			GameLoop::actionEntities()
{
  this->_mutex->enter();
  for (std::list<PlayerInfo *>::iterator it = _clients->begin(); it != _clients->end(); ++it)
    {
      if ((*it)->getIG() == true)
	(*it)->actionPlayer(this->_levelManag->getMap(), this->_levelManag->getPosAdv(), _idEntity);
    }
  for (auto it = this->_levelManag->getEnemies().begin(); it != this->_levelManag->getEnemies().end(); ++it)
    if ((*it)->getType() == AEntity::MOB)
      this->execAction(*reinterpret_cast<Mob *>((*it))->getAction(), *it, this->_levelManag->getPosAdv(), this->_levelManag->getMap());
  this->_mutex->leave();
}

void			GameLoop::lostLifePlayer() const
{
  this->_mutex->enter();
  for (auto it = this->_levelManag->getPlayers().begin(); it != this->_levelManag->getPlayers().end(); ++it)
    if ((*it)->getType() == AEntity::PLAYER && reinterpret_cast<Player *>((*it))->lostLife())
      this->sendLostLife((*it)->getId());
  this->_mutex->leave();
}

void			GameLoop::endLoop()
{
  this->_mutex->enter();
  if (this->_levelManag->getEndGame())
    sendClient("TCP", "ENDGAME WIN");
  else if (this->_criticalError == false)
    sendClient("TCP", "ENDGAME LOOSE");
  for (auto it_bis = this->_clients->begin(); it_bis != this->_clients->end(); it_bis++)
    (*it_bis)->sendMsg();
  this->quitClients();
  this->_mutex->leave();
  if (!this->_criticalError)
    GameLoopManager::getInstance()->quitGame(this->_id);
}

void			GameLoop::loop()
{
  clock_t		time = 0;
  clock_t		end = 0;
  clock_t		action = 0;
  bool			SuperVaisseau;

  action = clock();
  while (!this->_levelManag->getEndGame() && !this->_criticalError)
    {
      SuperVaisseau = false;
      this->spawnMob();
      this->spawnWalls();
      if (this->checkActiveClient() == false)
	break;
      time = clock();
      this->removeEntities();
      this->moveAllEntities(SuperVaisseau);
      this->actionEntities();
      this->_mutex->enter();
      this->_levelManag->getMap()->setEntities(this->_levelManag->getAdv());
      this->_mutex->leave();
      this->lostLifePlayer();
      end = clock();
      time = end - time;
      if (((double)time / CLOCKS_PER_SEC) <= 0.03)
        {
	  for (double i = 0 ; i <= 0.03 - ((double)time / CLOCKS_PER_SEC) ; i += 0.03)
	    this->scrolling();
	  this->sendScroll(this->_levelManag->getPosAdv());
	  this->_mutex->enter();
	  for (auto it_bis = this->_clients->begin(); it_bis != this->_clients->end(); it_bis++)
	    (*it_bis)->sendMsg();
	  this->_mutex->leave();
#ifndef _WIN32
	  usleep(((double)0.03 - ((double)time / CLOCKS_PER_SEC)) * 1000000);
#else
          Sleep(((double)0.03 - ((double)time / CLOCKS_PER_SEC)) * 1000);
#endif
	  action -= ((double)0.03 - ((double)time / CLOCKS_PER_SEC)) * CLOCKS_PER_SEC;
	}
      this->_mutex->enter();
      if ((((float)(clock() - action)) / CLOCKS_PER_SEC) > 0.04)
      	{
	  this->action();
	  action = clock();
	  if (SuperVaisseau == false)
	    for (auto it = this->_levelManag->getPlayers().begin(); it != this->_levelManag->getPlayers().end(); ++it)
	      {
		if ((*it)->getType() == AEntity::PLAYER)
		  {
		    reinterpret_cast<Player *>((*it))->setScore(reinterpret_cast<Player *>((*it))->getScore() + 1);
		    this->sendEntity((*it));
		  }
	      }
	  for (auto it = this->_levelManag->getEnemies().begin(); it != this->_levelManag->getEnemies().end(); ++it)
	    this->sendEntity((*it));
      	}
      this->_mutex->leave();
    }
  this->endLoop();
}

void			GameLoop::sendDeadEntity(unsigned int id) const
{
  std::ostringstream	oss;

  oss << "REMOVEENTITY " << id;
  this->sendClient("UDP", oss.str());
}

void			GameLoop::sendScroll(unsigned int scroll) const
{
  std::ostringstream	oss;

  oss << "SCROLL " << scroll;
  this->sendClient("UDP", oss.str());
}

void			GameLoop::sendClient(const std::string &protocol, const std::string &trame) const
{
  for (auto it_bis = this->_clients->begin(); it_bis != this->_clients->end(); it_bis++)
    if (!this->_criticalError)
      (*it_bis)->pushMsg(protocol, trame);
}

void			GameLoop::sendLostLife(unsigned int const id) const
{
  std::ostringstream	oss;

  oss << "LOSTLIFE " << id;
  this->sendClient("UDP", oss.str());
}

void			GameLoop::sendScreen(std::list<AEntity *> &list)
{
  for (auto it = list.begin(); it != list.end(); ++it)
    sendEntity(*it);
}

void			GameLoop::sendEntity(AEntity *entity) const
{
  std::ostringstream	oss;
  std::string		path(PATH_SPRITE);
  size_t		pos;

  oss << "ENTITY " << entity->getId() << ";";
  if (!entity->getPath().empty() && entity->getPath().size() > path.size() + 1 && ((pos = entity->getPath().find(EXTENSION_SPRITE)) != std::string::npos ||
										   (pos = entity->getPath().find(EXTENSION_SPRITE2)) != std::string::npos))
    oss << entity->getPath().substr(path.size() + 1, pos - (path.size() + 1));
  oss << ";" << entity->getPosX() << ";" << entity->getPosY();
  sendClient("UDP", oss.str());
}

bool			GameLoop::newPlayer(ClientInfo *newClient)
{
  int			i = 1;

  this->_mutex->enter();
  if (this->_clients->size() >= 4)
    {
      this->_mutex->leave();
      return (false);
    }
  if (!this->_clients->empty())
    for (auto it = _clients->begin(); it != _clients->end() && i == (*it)->getNum(); ++it)
      i++;
  this->_clients->push_back(new PlayerInfo(newClient, i));
  this->_clients->back()->getPlayer()->movePos(this->_levelManag->getPosAdv() + 20, 400);
  this->_clients->back()->getPlayer()->setId(_idEntity);
  _idEntity++;
  this->_levelManag->getPlayers().push_back(this->_clients->back()->getPlayer());
  this->_mutex->leave();
  return (true);
}

void			GameLoop::playerDeath(PlayerInfo *deadPlayer)
{
  deadPlayer->pushMsg("TCP", "DEAD");
}

void			GameLoop::spawnMob()
{
  Mob			*entity = NULL;

  if (rand () % 30 == 9)
    {
      entity = this->_library->getRandomInstance();
      if (entity)
	{
	  if (SpriteLoaderManager::getInstance()->getEntitySprite(entity->getPath(), *entity))
	    {
	      entity->setInvincible(0);
	      entity->setId(_idEntity);
	      _idEntity++;
	      this->_levelManag->getEnemies().push_back(entity);
	      this->_levelManag->getEnemies().back()->movePos(this->_levelManag->getPosAdv() + SCREENX * 10 + 1, rand() % 800);
	    }
	}
    }
}

void			GameLoop::spawnWalls()
{
  bool			spawnable = false;

  for (auto it = _levelManag->getInactiveWalls().begin(); it != _levelManag->getInactiveWalls().end(); ++it)
    {
      spawnable = SpriteLoaderManager::getInstance()->getEntitySprite((*it)->getPath(), *(*it));
      if (spawnable && (*it)->getPosX() <= this->_levelManag->getPosAdv() + SCREENX * 10 + 1)
	{
	  (*it)->setId(_idEntity);
	  _idEntity++;
	  it = this->_levelManag->spawnWall(it);
	}
      else if (!spawnable)
	{
	  it = _levelManag->getInactiveWalls().erase(it);
	  if (_levelManag->getInactiveWalls().empty())
	    break;
	  if (it != _levelManag->getInactiveWalls().begin())
	    it--;
	}
    }
}

void			GameLoop::destroyDeadEntities(std::list<AEntity *> &enemies, std::list<AEntity *> &players)
{
  for (std::list<AEntity *>::iterator it = enemies.begin(); it != enemies.end(); ++it)
    {
      if ((*it)->isDead() == true)
	{
	  this->sendDeadEntity((*it)->getId());
	  it = enemies.erase(it);
	  if (enemies.empty())
	    break;
	  if (it != enemies.begin())
	    --it;
	}
    }
  for (std::list<PlayerInfo *>::iterator it = _clients->begin(); it != _clients->end(); ++it)
    {
      if ((*it)->getPlayer()->isDead() == true)
	{
	  this->sendDeadEntity((*it)->getPlayer()->getId());
	  this->playerDeath(*it);
	  players.remove((*it)->getPlayer());
	  (*it)->setIG(false);
	}
    }
  for (auto it = players.begin(); it != players.end(); ++it)
    {
      if ((*it)->isDead() == true)
	{
	  this->sendDeadEntity((*it)->getId());
	  it = players.erase(it);
	  if (players.empty())
	    break;
	  if (it != players.begin())
	    --it;
	}
    }
}

unsigned int		GameLoop::getId() const
{
  unsigned int		id;

  this->_mutex->enter();
  id = this->_id;
  this->_mutex->leave();
  return (id);
}

std::string		GameLoop::getName() const
{
  std::string		name;

  this->_mutex->enter();
  name = this->_name;
  this->_mutex->leave();
  return (name);
}

unsigned int		GameLoop::getNumPlayer() const
{
  unsigned int		size;

  this->_mutex->enter();
  size = this->_clients->size();
  this->_mutex->leave();
  return (size);
}

void			GameLoop::quitGame()
{
  this->_mutex->enter();
  this->_criticalError = true;
  this->_mutex->leave();
}

bool			GameLoop::deletePlayer(ClientInfo *info)
{
  PlayerInfo		*pI;

  this->_mutex->enter();
  for (std::list<PlayerInfo *>::iterator it = _clients->begin(); it != _clients->end(); ++it)
    {
      if ((*it)->isMyInfo(info))
  	{
	  pI = *it;
	  this->sendDeadEntity((*it)->getPlayer()->getId());
	  for (auto itP = this->_levelManag->getPlayers().begin(); itP != this->_levelManag->getPlayers().end(); ++itP)
	    {
	      if ((*itP)->getId() == (*it)->getPlayer()->getId())
		{
		  itP = this->_levelManag->getPlayers().erase(itP);
		  break;
		}
	    }
	  it = _clients->erase(it);
	  delete pI;
	  this->_mutex->leave();
	  return (true);
	}
    }
  this->_mutex->leave();
  return (false);
}

unsigned int		GameLoop::getLevel() const
{
  unsigned int		lvl;

  this->_mutex->enter();
  lvl = this->_levelManag->getDiff();
  this->_mutex->leave();
  return (lvl);
}

bool			GameLoop::checkActiveClient()
{
  int			i = 0;

  for (auto it = this->_clients->begin(); it != this->_clients->end(); ++it)
    if ((*it)->getIG() == true)
      i++;
  return ((i)?(true):(false));
}


void			GameLoop::quitClients()
{

  for (auto it = this->_clients->begin(); it != this->_clients->end(); ++it)
    (*it)->quitGame();
}
