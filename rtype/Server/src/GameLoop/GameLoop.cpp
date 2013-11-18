//
// GameLoop.cpp for game in /home/maitre_c/work/local/rtype/code/src/GameLoop
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:49:55 2013 antoine maitre
// Last update Mon Nov 18 16:16:45 2013 arthur rucquois
//

#include "GameLoop/GameLoop.hh"

GameLoop::GameLoop(std::string const &name, unsigned int const id):
  Thread(),
  Mutex(),
  _clients(new std::list<PlayerInfo *>),
  _rate(50),
  _name(name),
  _id(id)
{
}

GameLoop::~GameLoop()
{
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
      this->_levelManag->incAdv();
      std::cout << this->_levelManag->getAdv() << std::endl;
      for (std::list<PlayerInfo *>::iterator it = _clients->begin(); it != _clients->end(); ++it)
	(*it)->actionPlayer(this->_levelManag->getMap(), this->_levelManag->getAdv());
      for (std::list<AEntity *>::iterator it = this->_levelManag->getEnemies().begin(); it != this->_levelManag->getEnemies().begin(); it++)
	{
	  const Coordinate	*coord = (*it)->getCoord();
	  
	  if (coord->getX() <= this->_levelManag->getAdv() - (*it)->getWidth())
	    it = this->_levelManag->getEnemies().erase(it);
	}
      this->_levelManag->getMap()->setEntities(this->_levelManag->getAdv());
      this->destroyDeadEntities(this->_levelManag->getEnemies(),
				this->_levelManag->getPlayers());
#ifndef _WIN32
      rest = clock() - time;
      if (rest < 1000 / this->_rate)
	usleep(1000 * ((1000 / this->_rate) - rest));
#endif
    }
}

void			GameLoop::recupScreen()
{
  
}

void			GameLoop::newPlayer(ClientInfo *newClient)
{
  int			i = 1;
  for (auto it = _clients->begin(); it != _clients->end() && i != (*it)->getNum(); ++it)
    i++;
  this->_clients->push_back(new PlayerInfo(newClient, i));
  this->_clients->front()->getPlayer()->move(this->_levelManag->getAdv() + 20, 40);
  this->_levelManag->getPlayers().push_back(this->_clients->front()->getPlayer());
}

void			GameLoop::deadPlayer(std::list<PlayerInfo *>::iterator &deadPlayer)
{
  std::ostringstream	oss;

  oss << "DEAD " << (*deadPlayer)->getNum();
  (*deadPlayer)->sendTrame("TCP", std::string(oss.str()));
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
	it = enemies.erase(it);
    }
  for (std::list<PlayerInfo *>::iterator it = _clients->begin(); it != _clients->end(); it++)
    {
      if ((*it)->getPlayer()->isDead() == true)
	{
	  players.remove((*it)->getPlayer());
	  it = _clients->erase(it);
	  it = this->_clients->begin();
	}
    }
}

unsigned int		GameLoop::getId() const
{
  return (this->_id);
}

std::string		GameLoop::getName() const
{
  return (this->_name);
}

unsigned int		GameLoop::getNumPlayer() const
{
  return (this->_clients->size());
}

bool			GameLoop::setPlayer(ClientInfo *)
{
  return (true);
}

void			GameLoop::quitGame()
{

}

bool			GameLoop::deletePlayer(ClientInfo *)
{
  return (true);
}

unsigned int		GameLoop::getLevel() const
{
  //  return (this->_level);
  return (1);
}
