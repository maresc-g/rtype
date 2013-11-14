//
// Map.cpp for game in /home/maitre_c/work/rtype/code/src/Game
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 17:15:04 2013 antoine maitre
// Last update Thu Nov 14 12:16:56 2013 antoine maitre
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
      this->_map = new std::vector<std::vector<unsigned int>> (SCREENY);
      for (int i = 0; i < SCREENY ; i++)
	(*this->_map)[i].resize(SCREENX);
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
      	  _enemiesStatic.push_back(new Mob(x, y, pathMob, 0, true));
      	}
      fichier.close();
    }
  else
    std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}

Map::~Map()
{

}

std::vector<std::vector<unsigned int>> *Map::getMap()
{
  return (this->_map);
}

void	Map::tryToSet(std::list<AEntity *> &l1, std::list<AEntity *> &l2, int adv)
{
  const Coordinate *toto;

  for (std::list<AEntity *>::iterator it = l1.begin(); it != l1.end(); ++it)
    {
      toto = (*it)->getCoord();
      for (int i = toto->getY(); i < toto->getY() + (*it)->getLargeur(); i++)
	{
	  if (i <= 0 || i >= SCREENY)
	    {
	      (*it)->setDead(true);
	      break;
	    }
	  for (int j = toto->getX() - adv; j < toto->getX() - adv + (*it)->getLongueur(); j++)
	    {
	      if (j <= 0 - (*it)->getLongueur() || j >= SCREENX)
		{
		  (*it)->setDead(true);
		  break;
		}
	      else if ((*this->_map)[i][j] == 0 && (i >= 0 && i < SCREENY) && (j >= 0 && j <= SCREENX))
		(*this->_map)[i][j] = (*it)->getId();
	      else
		{
		  (*it)->collision();
		  for (std::list<AEntity *>::iterator it2 = l2.begin(); it2 != l2.end(); ++it2)
		    if ((*this->_map)[i][j] == (*it2)->getId())
		      (*it2)->collision();
		  // for (std::list<AEntity *>::iterator it2 = l1.begin(); it2 != l1.end(); ++it2)
		  //   if ((*this->_map)[i][j] == (*it2)->getId())
		  //     (*it2)->collision();
		}
	    }
	}
    }
}

void	Map::setEntities(int adv)
{
  for (int i = 0; i < SCREENY; i++)
    for (int j = 0; j < SCREENX; j++)
      (*this->_map)[i][j] = 0;
  this->tryToSet(_enemies, _players, adv);
  this->tryToSet(_players, _enemies, adv);
  // for (int i=0; i < SCREENY; i++)
  //   std::cout << (*this->_map)[i] << std::endl;
}

std::list<AEntity *> &Map::getEnemies()
{
  return (this->_enemies);
}

std::list<AEntity *> &Map::getPlayers()
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
