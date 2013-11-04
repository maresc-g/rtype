//
// Game.cpp for game in /home/maitre_c/work/local/rtype/code/src/Game
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:49:55 2013 antoine maitre
// Last update Wed Oct 30 17:51:08 2013 antoine maitre
//

#include "Game/Game.hh"

Game::Game()
  : _currentScreen(0)
{

}

Game::~Game()
{

}

void Game::Initialize()
{
  this->_levelManag = new LevelManager();
  this->_levelManag->Initialize();
}

void Game::loop()
{
  while (!this->_levelManag->getEndGame())
    {
      usleep(125000);
      this->_currentScreen++;
    }
}

void Game::recupScreen()
{
  
}

void Game::newPlayer()
{
  
}

void Game::deadPlayer()
{

}

void Game::spawnMob()
{
  std::list<Mob *> yolo = this->_levelManag->getCurrentLevel()->getMap()->getDynamicEntities();

  
}
