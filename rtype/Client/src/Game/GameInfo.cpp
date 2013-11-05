//
// GameInfo.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Oct 29 14:44:49 2013 guillaume marescaux
// Last update Tue Oct 29 15:13:37 2013 guillaume marescaux
//

#include			"Game/GameInfo.hh"

//-----------------------------------BEGIN CTOR / DTOR-------------------------------------

GameInfo::GameInfo(int id, std::string const &name, int nbPlayer, int level):
  _id(id), _name(name), _nbPlayer(nbPlayer), _level(level)
{
}

GameInfo::~GameInfo()
{
}

GameInfo::GameInfo(GameInfo const &other):
  _id(other._id), _name(other._name), _nbPlayer(other._nbPlayer), _level(other._level)
{
}

GameInfo			&GameInfo::operator=(GameInfo const &other)
{
  if (this != &other)
    {
      _id = other._id;
      _name = other._name;
      _nbPlayer = other._nbPlayer;
      _level = other._level;
    }
  return (*this);
}

//------------------------------------END CTOR / DTOR--------------------------------------

//-----------------------------------BEGIN GETTERS / SETTERS-------------------------------------

int				GameInfo::getId(void) const { return (_id); }
void				GameInfo::setId(int const id) { _id = id; }
std::string const		&GameInfo::getName(void) const { return (_name); }
void				GameInfo::setName(std::string const &name) { _name = name; }
int				GameInfo::getNbPlayer(void) const { return (_nbPlayer); }
void				GameInfo::setNbPlayer(int const nbPlayer) { _nbPlayer = nbPlayer; }
int				GameInfo::getLevel(void) const { return (_level); }
void				GameInfo::setLevel(int const level) { _level = level; }

//------------------------------------END GETTERS / SETTERS--------------------------------------
