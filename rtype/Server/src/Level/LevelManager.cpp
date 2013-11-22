//
// LevelManager.cpp for level in /home/maitre_c/work/local/rtype/code/src/Game
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:58:06 2013 antoine maitre
// Last update Fri Nov 22 11:01:07 2013 arthur rucquois
//

#include	"Level/LevelManager.hh"

LevelManager::LevelManager()
  : _diff(1), _endGame(false)
{

}

LevelManager::~LevelManager()
{

}

void	LevelManager::Initialize()
{
  this->_levels.push_back(new Level(1));
  this->_currentLevel = this->_levels.front();
  // this->_levels.push_back(new Level(2));
  // this->_levels.push_back(new Level(3));
  for (std::list<Level *>::iterator it = this->_levels.begin(); it != this->_levels.end(); ++it)
    (*it)->Initialize();
}

void	LevelManager::nextLevel()
{
  Level	*tmp = this->_currentLevel;

  this->_diff++;
  for (std::list<Level *>::iterator it = this->_levels.begin(); it != this->_levels.end(); ++it)
    {
      if (this->_diff == (*it)->getDiff())
	this->_currentLevel = (*it);
    }
  if (tmp == this->_currentLevel)
    this->_endGame = true;
}

Level	*LevelManager::getCurrentLevel()
{
  return (this->_currentLevel);
}

bool	LevelManager::getEndGame()
{
  return (this->_endGame);
}

void	LevelManager::incAdv()
{
  this->_currentLevel->incAdv();
  if (this->_currentLevel->getEnd() == true)
    this->nextLevel();
}

std::list<AEntity *> &LevelManager::getEnemies()
{
  return (this->_currentLevel->getEnemies());
}

std::list<AEntity *> &LevelManager::getPlayers()
{
  return (this->_currentLevel->getPlayers());
}

std::list<AEntity *> &LevelManager::getWalls()
{
  return (this->_currentLevel->getWalls());
}

std::list<AEntity *> &LevelManager::getInactiveWalls()
{
  return (this->_currentLevel->getInactiveWalls());
}

std::list<AEntity *>::iterator const	&LevelManager::spawnWall(std::list<AEntity *>::iterator &it)
{
  it = this->_currentLevel->spawnWall(it);
  return it;
}

Map			*LevelManager::getMap()
{
  return (this->_currentLevel->getMap());
}

int			LevelManager::getAdv() const
{
  return (this->_currentLevel->getAdv());
}

int			LevelManager::getPixelAdv() const
{
  return (this->_currentLevel->getAdv());
}

unsigned int		LevelManager::getDiff() const
{
  return (this->_diff);
}

int			LevelManager::getPosAdv() const
{
  return (this->_currentLevel->getPosAdv());
}
