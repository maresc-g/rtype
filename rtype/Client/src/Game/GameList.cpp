//
// GameList.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Oct 29 15:03:05 2013 guillaume marescaux
// Last update Tue Nov  5 12:55:29 2013 guillaume marescaux
//

#include			"Game/GameList.hh"

//-----------------------------------BEGIN CTOR / DTOR-------------------------------------

GameList::GameList():
  _games(new std::list<GameInfo *>)
{
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
  if (gameInfo)
    _games->push_back(gameInfo);
}

void				GameList::removeGame(int id)
{
  for (auto it = _games->begin() ; it != _games->end() ; it++)
    {
      if ((*it)->getId() == id)
	{
	  delete *it;
	  _games->erase(it);
	  break;
	}      
    }
}

void				GameList::clear()
{
  for (auto it = _games->begin() ; it != _games->end() ; it++)
    {
      delete *it;
    }
  _games->clear();
}

//------------------------------------END METHODS--------------------------------------
