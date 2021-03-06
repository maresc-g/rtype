//
// Level.cpp for level in /home/maitre_c/work/local/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 16:09:33 2013 antoine maitre
// Last update Wed Oct 30 17:44:04 2013 antoine maitre
//

#include	"Level/Level.hh"

Level::Level(int diff)
  : _diff(diff), _finish(false)
{
  std::string pathMap;
  std::ostringstream oss;

  oss << diff;
  this->_path = "src/Level/lvl" + oss.str() + "/";
}

Level::~Level()
{

}

void	Level::Initialize()
{
  std::string pathMap = this->_path + "map";

  this->_map = new Map(pathMap);
  this->_map->setStaticEntitiesMap();
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
