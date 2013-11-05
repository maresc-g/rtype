//
// GameList.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Oct 29 15:03:05 2013 guillaume marescaux
// Last update Tue Oct 29 15:32:50 2013 guillaume marescaux
//

#include			"Game/GameList.hh"

//-----------------------------------BEGIN CTOR / DTOR-------------------------------------

GameList::GameList():
  _games(new std::list<GameInfo *>)
{
}

GameList::GameList(GameList const &other):
  _games(new std::list<GameInfo *>(*other._games))
{
}

GameList			&GameList::operator=(GameList const &other)
{
  if (this != &other)
    {
      _games = new std::list<GameInfo *>(*other._games);
    }
  return (*this);
}

GameList::~GameList()
{
  for (auto it = _games->begin() ; it != _games->end() ; it++)
    {
      delete *it;
    }
  delete _games;
}

//------------------------------------END CTOR / DTOR--------------------------------------

//-----------------------------------BEGIN METHODS-------------------------------------

void				GameList::addGame(GameInfo *gameInfo)
{
  _games->push_back(gameInfo);
}

//------------------------------------END METHODS--------------------------------------
