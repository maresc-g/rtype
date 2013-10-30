//
// Map.cpp for game in /home/maitre_c/work/rtype/code/src/Game
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 17:15:04 2013 antoine maitre
// Last update Wed Oct 30 10:53:56 2013 antoine maitre
//

#include "Level/Map.hh"

Map::Map(std::string _path)
{
  std::ifstream fichier(_path.c_str(), std::ios::in);
  std::string contenu;
  // std::list<Mob *> toto;
  std::string op;
  int type;
  int x;
  int y;

  if(fichier)
    {
      std::getline(fichier, contenu);
      op = contenu.substr(0, contenu.find("x"));
      x = std::stoi(op);
      contenu = contenu.substr(contenu.find("x") + 1, contenu.size() - contenu.find("x"));
      y = std::stoi(contenu);
      this->_map = new std::vector<std::string>(y);
      for (int i = 0; i < y; i++)
	(*this->_map)[i] = std::string(x, '0');
      // while (std::getline(fichier, contenu))
      // 	{
      // 	  op = contenu.substr(0, contenu.find(";"));
      // 	  type = atoi(op.c_str());
      // 	  contenu = contenu.substr(contenu.find(";") + 1, contenu.size() - contenu.find(";"));
      // 	  op = contenu.substr(0, contenu.find(";"));
      // 	  x = atoi(op.c_str());
      // 	  contenu = contenu.substr(contenu.find(";") + 1, contenu.size() - contenu.find(";"));
      // 	  y = atoi(contenu.c_str());
      // 	  toto.push_back(new Mob(x, y, type));
      // 	}
      // genereMap(toto);
      // fichier.close();
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
