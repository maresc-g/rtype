//
// Level.cpp for level in /home/maitre_c/work/local/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 16:09:33 2013 antoine maitre
// Last update Wed Oct 30 10:15:16 2013 antoine maitre
//

#include	"Level/Level.hh"

Level::Level(int diff)
  : _diff(diff)
{
  std::ostringstream oss;
  std::string pathMap;

  oss << diff;
  pathMap = "src/Level/lvl" + oss.str() + "/map";
  std::cout << pathMap << std::endl;
  this->_map = new Map(pathMap);
}

Level::~Level()
{

}

