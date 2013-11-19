//
// Level.cpp for level in /home/maitre_c/work/local/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 16:09:33 2013 antoine maitre
// Last update Tue Nov 19 12:19:58 2013 antoine maitre
//

#include	"Level/Level.hh"

Level::Level(int diff)
  : _diff(diff), _finish(false), _adv(20)
{
  std::string pathMap;
  std::ostringstream oss;

  oss << diff;
  this->_path = "Res/Level/Level" + oss.str() + "/";
}

Level::~Level()
{

}

void	Level::Initialize()
{
  std::string pathMap = this->_path + "map";

  this->_map = new Map(pathMap);
}

bool	Level::getEnd()
{
  return (this->_finish);
}

int	Level::getDiff()
{
  return (this->_diff);
}

Map	*Level::getMap()
{
  return (this->_map);
}

void	Level::incAdv()
{
  if (this->_adv < this->_map->getPosX())
    this->_adv++;
}

std::list<AEntity *> &Level::getEnemies()
{
  return (this->_map->getEnemies());
}

std::list<AEntity *> &Level::getPlayers()
{
  return (this->_map->getPlayers());
}

int Level::getAdv() const
{
  return (this->_adv);
}
