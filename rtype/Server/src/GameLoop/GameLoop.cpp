//
// GameLoop.cpp for game in /home/maitre_c/work/local/rtype/code/src/GameLoop
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:49:55 2013 antoine maitre
// Last update Tue Nov 19 13:16:03 2013 laurent ansel
//

#include "GameLoop/GameLoop.hh"

GameLoop::GameLoop(std::string const &name, unsigned int const id):
  Thread(),
  _clients(new std::list<PlayerInfo *>),
  _rate(50),
  _name(name),
  _id(id),
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
  clock_t	rest = 0;

  while (!this->_levelManag->getEndGame())
    {
      time = clock();
      this->_mutex->enter();
      this->_levelManag->incAdv();
      std::cout << "ADV = " << this->_levelManag->getAdv() << std::endl;
      for (std::list<PlayerInfo *>::iterator it = _clients->begin(); it != _clients->end(); ++it)
	(*it)->actionPlayer(this->_levelManag->getMap(), this->_levelManag->getAdv());
      for (std::list<AEntity *>::iterator it = this->_levelManag->getEnemies().begin(); it != this->_levelManag->getEnemies().begin(); it++)
	{
	  const Coordinate	*coord = (*it)->getCoord();

	  if (coord->getX() <= this->_levelManag->getAdv() - (*it)->getWidth())
	    it = this->_levelManag->getEnemies().erase(it);
	}
      this->_levelManag->getMap()->setEntities(this->_levelManag->getAdv());
      this->destroyDeadEntities(this->_levelManag->getEnemies());
      this->_mutex->leave();
      rest = clock() - time;
      if (rest < 1000 / this->_rate)
#ifndef _WIN32
	usleep(1000 * ((1000 / this->_rate) - rest));
#else
      Sleep((1000 * ((1000 / this->_rate) - rest)) / 1000);
#endif
    }
}

void			GameLoop::recupScreen()
{

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

void			GameLoop::destroyDeadEntities(std::list<AEntity *> &enemies)
{
  for (std::list<AEntity *>::iterator it = enemies.begin(); it != enemies.end(); it++)
    {
      if ((*it)->isDead() == true)
	it = enemies.erase(it);
    }
  for (std::list<PlayerInfo *>::iterator it = _clients->begin(); it != _clients->end(); it++)
    {
      if ((*it)->getPlayer()->isDead() == true)
       	this->playerDeath(*it);
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
  lvl = 0;
  this->_mutex->leave();
  return (lvl);
}
