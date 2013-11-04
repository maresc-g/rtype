//
// LevelManager.cpp for level in /home/maitre_c/work/local/rtype/code/src/Game
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 15:58:06 2013 antoine maitre
// Last update Fri Nov  1 11:03:58 2013 arthur rucquois
//

#include	"Game/LevelManager.hh"

const std::string		&LevelManager::getPath() const
{
  return (this->_path);
}

const std::list<Level *>	&LevelManager::getLevels() const
{
  return (this->_levels);
}

const Level			&LevelManager::getCurrentLevel() const
{
  return (*(this->_currentLevel));
}

LevelManager::LevelManager()
{
}

LevelManager::~LevelManager()
{
}
