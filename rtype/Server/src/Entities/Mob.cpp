//
// Mob.cpp for mob in /home/maitre_c/work/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Wed Oct 30 11:19:56 2013 antoine maitre
// Last update Mon Nov 18 11:52:18 2013 alexis mestag
//

#include "Entities/Mob.hh"

Mob::Mob(int const x, int const y, std::string const &path, int const speed)
  : ACharacter(x, y, path, speed, true), _action(new Action)
{
  std::ifstream fichier(path.c_str(), std::ios::in);
  std::string contenu;

  std::getline(fichier, contenu);
  contenu = contenu.substr(contenu.find("=") + 1, contenu.size() - contenu.find("="));
  this->_destructible = static_cast<bool>(std::stoi(contenu));
  std::getline(fichier, contenu);
  contenu = contenu.substr(contenu.find("=") + 1, contenu.size() - contenu.find("="));
  this->_width = std::stoi(contenu);
  this->_height = std::stoi(contenu.substr(contenu.find("x") + 1, contenu.size() - contenu.find("x")));
}

Mob::~Mob()
{
  delete _action;
}

AEntity::eObject		Mob::getType() const
{
  return (MOB);
}

Action const			*Mob::getAction() const
{
  return (_action);
}
