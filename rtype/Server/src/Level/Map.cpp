//
// Map.cpp for game in /home/maitre_c/work/rtype/code/src/Game
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 17:15:04 2013 antoine maitre
// Last update Wed Nov  6 14:51:28 2013 antoine maitre
//

#include "Level/Map.hh"

Map::Map(std::string _path)
{
  std::ifstream fichier(_path.c_str(), std::ios::in);
  std::string contenu;
  std::string op;
  std::string pathMob;
  int type;
  int x;
  int y;
  std::ostringstream oss;


  if(fichier)
    {
      std::getline(fichier, contenu);
      op = contenu.substr(0, contenu.find("x"));
      this->_x = std::stoi(op);
      contenu = contenu.substr(contenu.find("x") + 1, contenu.size() - contenu.find("x"));
      this->_y = std::stoi(contenu);
      this->_map = new std::vector<std::string>();
      for (int i = 0; i < this->_y ; i++)
	(*this->_map).push_back(std::string(this->_x, '0'));
      while (std::getline(fichier, contenu))
      	{
      	  op = contenu.substr(0, contenu.find(";"));
      	  type = atoi(op.c_str());
      	  contenu = contenu.substr(contenu.find(";") + 1, contenu.size() - contenu.find(";"));
      	  op = contenu.substr(0, contenu.find(";"));
      	  x = atoi(op.c_str());
      	  contenu = contenu.substr(contenu.find(";") + 1, contenu.size() - contenu.find(";"));
      	  y = atoi(contenu.c_str());
	  oss << type;
	  pathMob = _path.substr(0, _path.size() - 3) + oss.str() + ".conf";
	  oss.str("");
      	  _enemies.push_back(new Mob(x, y, pathMob, 0, true));
      	}
      fichier.close();
    }
  else
    std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}

Map::~Map()
{

}

std::vector<std::string> *Map::getMap()
{
  return (this->_map);
}

void	Map::setEnemies()
{
  const Coordinate *toto;

  for (std::list<Mob *>::iterator it = _enemies.begin(); it != _enemies.end(); ++it)
    {
      toto = (*it)->getCoord();
      for (int i = toto->getY(); i < toto->getY() + (*it)->getLargeur(); i++)
	for (int j = toto->getX(); j < toto->getX() + (*it)->getLongueur(); j++)
	  {
	    std::cout << i << " " << j << std::endl;
	    (*this->_map)[i][j] = 'X';
	  }
    }
  for (int i=0; i < 80; i++)
    std::cout << (*this->_map)[i].c_str() << std::endl;
}

std::list<Mob *> &Map::getEnemies()
{
  return (this->_enemies);
}

std::list<Player *> &Map::getPlayers()
{
  return (this->_players);
}

int		Map::getPosX() const
{
  return (this->_x);
}

int		Map::getPosY() const
{
  return (this->_y);
}
