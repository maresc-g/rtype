//
// Mob.cpp for mob in /home/maitre_c/work/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Wed Oct 30 11:19:56 2013 antoine maitre
// Last update Tue Nov  5 10:50:25 2013 antoine maitre
//

#include "Entities/Mob.hh"

Mob::Mob(int const x, int const y, std::string const &path, int const speed, bool const destructible)
  : ACharacter(x, y, path, speed, destructible)
{
  std::ifstream fichier(path.c_str(), std::ios::in);
  std::string contenu;

  std::getline(fichier, contenu);
  contenu = contenu.substr(contenu.find("=") + 1, contenu.size() - contenu.find("="));
  this->_destructible = static_cast<bool>(std::stoi(contenu));
  std::getline(fichier, contenu);
  contenu = contenu.substr(contenu.find("=") + 1, contenu.size() - contenu.find("="));
  this->_l = std::stoi(contenu);
  this->_L = std::stoi(contenu.substr(contenu.find("x") + 1, contenu.size() - contenu.find("x")));
}

Mob::~Mob()
{

}

eObject		Mob::getType() const
{
  return (MOB);
}
