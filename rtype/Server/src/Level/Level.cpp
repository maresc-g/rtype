//
// Level.cpp for level in /home/maitre_c/work/local/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 16:09:33 2013 antoine maitre
// Last update Sun Nov 24 12:39:13 2013 laurent ansel
//

#include	"Level/Level.hh"

Level::Level(int diff)
  : _diff(diff), _finish(false), _adv(0), _pixelAdv(0)
{
  std::string pathMap;
  std::ostringstream oss;

  oss << diff;
  this->_path = "Res/Level/Level" + oss.str() + "/";
}

Level::~Level()
{
  if (_map)
    delete _map;
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

unsigned int	Level::getDiff()
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
    {
      this->_pixelAdv++;
      if (this->_pixelAdv == 10)
	{
	  this->_pixelAdv = 0;
	  this->_adv++;
	}
    }
  else
    this->_finish = true;
}

std::list<AEntity *> &Level::getEnemies()
{
  return (this->_map->getEnemies());
}

std::list<AEntity *> &Level::getPlayers()
{
  return (this->_map->getPlayers());
}

std::list<AEntity *> &Level::getWalls()
{
  return (this->_map->getWalls());
}

std::list<AEntity *> &Level::getInactiveWalls()
{
  return (this->_map->getInactiveWalls());
}

std::list<AEntity *>::iterator const	&Level::spawnWall(std::list<AEntity *>::iterator &it)
{
  it = this->_map->spawnWall(it);
  return it;
}

int			Level::getPosAdv() const
{
  return (this->_adv * 10 + _pixelAdv);
}

unsigned int Level::getAdv() const
{
  return (this->_adv);
}

int Level::getPixelAdv() const
{
  return (this->_pixelAdv);
}
