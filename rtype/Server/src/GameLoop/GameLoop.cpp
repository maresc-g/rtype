//
// GameLoop.cpp for game in /home/maitre_c/work/local/rtype/code/src/GameLoop
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:49:55 2013 antoine maitre
// Last update Wed Nov 20 13:34:45 2013 antoine maitre
//

#include "GameLoop/GameLoop.hh"

GameLoop::GameLoop(std::string const &name, unsigned int const id):
  Thread(),
  _clients(new std::list<PlayerInfo *>),
  _rate(5),
  _name(name),
  _id(id),
  _criticalError(false),
  _mutex(new Mutex)
{
  this->_mutex->initialize();
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

void			GameLoop::loop()
{
  clock_t	time = 0;
  clock_t	end = 0;

  while (!this->_levelManag->getEndGame() || this->_criticalError == true)
    {
      if (this->checkActiveClient() == false)
	break;
      time = clock();
      this->_mutex->enter();
      this->_levelManag->incAdv();
      std::cout << "ADV = " << this->_levelManag->getAdv() << std::endl;
      for (std::list<PlayerInfo *>::iterator it = _clients->begin(); it != _clients->end(); ++it)
	{
	  if ((*it)->getIG() == true)
	    (*it)->actionPlayer(this->_levelManag->getMap(), this->_levelManag->getAdv());
	}
      for (std::list<AEntity *>::iterator it = this->_levelManag->getEnemies().begin(); it != this->_levelManag->getEnemies().end(); it++)
      	{
      	  const Coordinate	*coord = (*it)->getCoord();

      	  if (coord->getX() <= this->_levelManag->getAdv() - (*it)->getWidth())
      	    it = this->_levelManag->getEnemies().erase(it);
      	}
      this->_levelManag->getMap()->setEntities(this->_levelManag->getAdv());
      this->destroyDeadEntities(this->_levelManag->getEnemies(),
      				this->_levelManag->getPlayers());
      this->_mutex->leave();
      end = clock();
      time = end - time;
      if (((double)time / CLOCKS_PER_SEC) < 1000 / this->_rate)
        {
#ifndef _WIN32
          usleep(1000000 / this->_rate - ((float)time / CLOCKS_PER_SEC));
#else
          Sleep((1000 / this->_rate - ((float)time / CLOCKS_PER_SEC)) / 1000);
#endif
        }
      this->_mutex->enter();
      this->sendScroll(this->_levelManag->getAdv());
      this->sendScreen(this->_levelManag->getPlayers());
      this->sendScreen(this->_levelManag->getEnemies());
      this->_mutex->leave();
    }
  if (this->_levelManag->getEndGame())
    sendClient("TCP", "ENDGAME WIN");
  else if (this->_criticalError == false)
    sendClient("TCP", "ENDGAME LOOSE");
}

void			GameLoop::sendDeadEntity(unsigned int id)
{
  std::ostringstream	oss;

  oss << "DEAD " << id;
  this->sendClient("TCP", oss.str());
}

void			GameLoop::sendScroll(unsigned int scroll)
{
  std::ostringstream	oss;

  oss << "SCROLL " << scroll * 10;
  this->sendClient("UDP", oss.str());
}

void			GameLoop::sendClient(const std::string &protocol, const std::string &trame)
{
  for (auto it_bis = this->_clients->begin(); it_bis != this->_clients->end(); it_bis++)
    (*it_bis)->sendTrame(protocol, trame);
}

void			GameLoop::sendScreen(std::list<AEntity *> &list)
{
  std::ostringstream	oss;

  for (auto it = list.begin(); it != list.end(); it++)
    {
      oss << "ENTITY " << (*it)->getId()
	  << ";" << (*it)->getPath().substr(12, (*it)->getPath().size() - 16)
	  << ";" << (*it)->getCoord()->getX() * 10 << ";" << (*it)->getCoord()->getY() * 10;
      std::cout << oss.str() << " " << (*it)->getType() << std::endl;
      sendClient("UDP", oss.str());
      oss.str("");
    }
}

bool			GameLoop::newPlayer(ClientInfo *newClient)
{
  int			i = 0;

  this->_mutex->enter();
  for (auto it = _clients->begin(); it != _clients->end() && i != (*it)->getNum(); ++it)
    i++;
  this->_clients->push_back(new PlayerInfo(newClient, i));
  this->_clients->front()->getPlayer()->move(this->_levelManag->getAdv() + 20, 40);
  this->_levelManag->getPlayers().push_back(this->_clients->front()->getPlayer());
  this->_mutex->leave();
  return (true);
}

void			GameLoop::playerDeath(PlayerInfo *deadPlayer)
{
  deadPlayer->sendTrame("TCP", "DEAD");
}

void			GameLoop::spawnMob()
{
  if (rand() % 10 == 9)
    {
      this->_levelManag->getEnemies().push_back(ObjectPoolManager::getInstance()->getCopy(AEntity::MOB));
      this->_levelManag->getEnemies().back()->move(SCREENX + 5, rand() % 80);
    }
}

void			GameLoop::destroyDeadEntities(std::list<AEntity *> &enemies, std::list<AEntity *> &players)
{
  for (std::list<AEntity *>::iterator it = enemies.begin(); it != enemies.end(); it++)
    {
      if ((*it)->isDead() == true)
	{
	  this->sendDeadEntity((*it)->getId());
	  it = enemies.erase(it);
	}
    }
  for (std::list<PlayerInfo *>::iterator it = _clients->begin(); it != _clients->end(); it++)
    {
      if ((*it)->getPlayer()->isDead() == true)
	{
	  this->sendDeadEntity((*it)->getPlayer()->getId());
	  this->playerDeath(*it);
	  players.remove((*it)->getPlayer());
	  (*it)->setIG(false);
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
  for (std::list<PlayerInfo *>::iterator it = _clients->begin(); it != _clients->end(); it++)
    {
      if ((*it)->isMyInfo(info))
  	{
	  pI = *it;
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

  for (auto it = this->_clients->begin(); it != this->_clients->end(); it++)
    if ((*it)->getIG() == true)
      i++;
  return ((i)?(true):(false));
}
