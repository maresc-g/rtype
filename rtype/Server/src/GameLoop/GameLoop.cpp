
//
// GameLoop.cpp for game in /home/maitre_c/work/local/rtype/code/src/GameLoop
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:49:55 2013 antoine maitre
// Last update Tue Nov  5 10:23:01 2013 laurent ansel
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
      usleep(125000);
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
