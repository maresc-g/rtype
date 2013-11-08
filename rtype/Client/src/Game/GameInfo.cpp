//
// GameInfo.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Oct 29 14:44:49 2013 guillaume marescaux
// Last update Fri Nov  8 14:28:58 2013 guillaume marescaux
//

#include			"Game/GameInfo.hh"

//-----------------------------------BEGIN CTOR / DTOR-------------------------------------

GameInfo::GameInfo(std::string const &id, std::string const &name, std::string const &nbPlayer, std::string const &level):
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

std::string const		&GameInfo::getId(void) const { return (_id); }
void				GameInfo::setId(std::string const &id) { _id = id; }
std::string const		&GameInfo::getName(void) const { return (_name); }
void				GameInfo::setName(std::string const &name) { _name = name; }
std::string const		&GameInfo::getNbPlayer(void) const { return (_nbPlayer); }
void				GameInfo::setNbPlayer(std::string const &nbPlayer) { _nbPlayer = nbPlayer; }
std::string const		&GameInfo::getLevel(void) const { return (_level); }
void				GameInfo::setLevel(std::string const &level) { _level = level; }

//------------------------------------END GETTERS / SETTERS--------------------------------------
