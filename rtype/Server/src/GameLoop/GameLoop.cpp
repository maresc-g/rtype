
//
// GameLoop.cpp for game in /home/maitre_c/work/local/rtype/code/src/GameLoop
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:49:55 2013 antoine maitre
// Last update Wed Nov 13 12:21:10 2013 antoine maitre
//

#include "GameLoop/GameLoop.hh"

GameLoop::GameLoop()
{

}

GameLoop::~GameLoop()
{

}

void			GameLoop::Initialize(ClientInfo *client)
{
  this->_levelManag = new LevelManager();
  this->_levelManag->Initialize();
  this->_clients.push_back(new PlayerInfo(client, 1));
  this->_levelManag->getPlayers().push_back(this->_clients.front()->getPlayer());
}

void			GameLoop::loop()
{
  while (!this->_levelManag->getEndGame())
    {
#ifndef _WIN32
      usleep(125000);
      this->_levelManag->incAdv();
      for (std::list<PlayerInfo *>::iterator it = _clients.begin(); it != _clients.end(); ++it)
	(*it)->actionPlayer(this->_levelManag->getMap(), this->_levelManag->getAdv());
      for (std::list<AEntity *>::iterator it = this->_levelManag->getEnemies().begin(); it != this->_levelManag->getEnemies().begin(); it++)
	{
	  const Coordinate	*coord = (*it)->getCoord();
	  
	  if (coord->getX() <= this->_levelManag->getAdv() - (*it)->getLongueur())
	    it = this->_levelManag->getEnemies().erase(it);
	}
      this->_levelManag->getMap()->setEntities(this->_levelManag->getAdv());
      this->destroyDeadEntities(this->_levelManag->getEnemies(), 
				this->_levelManag->getPlayers());
#endif
    }
}

void			GameLoop::recupScreen()
{
  
}

void			GameLoop::newPlayer()
{
  
}

void			GameLoop::deadPlayer()
{

}

void			GameLoop::spawnMob()
{
  //  std::list<Mob *> yolo = this->_levelManag->getCurrentLevel()->getMap()->getDynamicEntities();

  
}

void			GameLoop::destroyDeadEntities(std::list<AEntity *> &enemies, std::list<AEntity *> &players)
{
  for (std::list<AEntity *>::iterator it = enemies.begin(); it != enemies.end(); it++)
    {
      if ((*it)->isDead() == true)
	it = enemies.erase(it);
    }
  for (std::list<PlayerInfo *>::iterator it = _clients.begin(); it != _clients.end(); it++)
    {
      if ((*it)->getPlayer()->isDead() == true)
	{
	  players.remove((*it)->getPlayer());
	  it = _clients.erase(it);
	}
    }
}

unsigned int		GameLoop::getId() const
{
  //  return (this->_id);
  return (0);
}

std::string		GameLoop::getName() const
{
  //  return (this->_name);
  return ("toto");
}

unsigned int		GameLoop::getNumPlayer() const
{
  //  return (this->_numberPlayer);
  return (3);
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
