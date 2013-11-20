//
// Map.cpp for game in /home/maitre_c/work/rtype/code/src/Game
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 17:15:04 2013 antoine maitre
// Last update Wed Nov 20 10:35:51 2013 antoine maitre
//

#include "Level/Map.hh"

Map::Map(std::string _path)
{
  std::ifstream fichier(_path.c_str(), std::ios::in);
  std::string contenu;
  std::string op;
  std::string pathMob;
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
      	  contenu = contenu.substr(contenu.find(";") + 1, contenu.size() - contenu.find(";"));
      	  op = contenu.substr(0, contenu.find(";"));
      	  contenu = contenu.substr(contenu.find(";") + 1, contenu.size() - contenu.find(";"));
	  pathMob = _path.substr(0, _path.size() - 3) + oss.str() + ".conf";
	  oss.str("");
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

void			Map::tryToSet(std::list<AEntity *> &l1, std::list<AEntity *> &l2, int adv)
{
  int			x;
  int			y;

  for (auto it = l1.begin(); it != l1.end(); ++it)
    {
      const auto info = (*it)->getInformationHitBox();
      for (auto hit = info.begin(); hit != info.end(); hit++)
	{
	  x = (*hit)->getCoordinate().getX() + (*it)->getCoord()->getX();
	  y = (*hit)->getCoordinate().getY() + (*it)->getCoord()->getY();
	  if ((*it)->getCoord()->getX() + (*hit)->getWidth() < 0 || (*it)->getCoord()->getX() > SCREENX + 50 ||
	      (*it)->getCoord()->getY() + (*hit)->getHeight() < 0 || (*it)->getCoord()->getY() > SCREENY)
	    {
	      (*it)->setDead(true);
	      break;
	    }
	  for (int i = y; i < y + (*hit)->getHeight(); i++)
	    for (int j = x - adv; j < x - adv + (*hit)->getWidth(); j++)
	      {
		if ((i >= 0 && i < SCREENY) && (j >= 0 && j <= SCREENX) && (*this->_map)[i][j] == 0)
		  (*this->_map)[i][j] = (*it)->getId();
		else if ((i >= 0 && i < SCREENY) && (j >= 0 && j <= SCREENX))
		  {
		    (*it)->collision();
		    for (auto it2 = l2.begin(); it2 != l2.end(); ++it2)
		      if ((*this->_map)[i][j] == (*it2)->getId())
			(*it2)->collision();
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
