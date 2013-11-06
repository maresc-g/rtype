
//
// GameLoop.cpp for game in /home/maitre_c/work/local/rtype/code/src/GameLoop
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:49:55 2013 antoine maitre
// Last update Tue Nov  5 13:59:31 2013 laurent ansel
//

#include "GameLoop/GameLoop.hh"

GameLoop::GameLoop()
  : _currentScreen(0)
{
}

GameLoop::~GameLoop()
{
}

void GameLoop::Initialize()
{
  this->_levelManag = new LevelManager();
  this->_levelManag->Initialize();
}

void GameLoop::loop()
{
  while (!this->_levelManag->getEndGame())
    {
#ifndef _WIN32
      usleep(125000);
#endif
      this->_currentScreen++;
    }
}

void GameLoop::recupScreen()
{
  
}

void GameLoop::newPlayer()
{
  
}

void GameLoop::deadPlayer()
{

}

void GameLoop::spawnMob()
{
  std::list<Mob *> yolo = this->_levelManag->getCurrentLevel()->getMap()->getDynamicEntities();

  
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
