//
// GameList.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Oct 29 15:03:05 2013 guillaume marescaux
// Last update Wed Nov 13 10:18:51 2013 guillaume marescaux
//

#include			"Game/GameList.hh"

//-----------------------------------BEGIN CTOR / DTOR-------------------------------------

GameList::GameList():
  _games(new std::list<GameInfo *>), _mutex(new Mutex)
{
  _mutex->initialize();
}

GameList::~GameList()
{
  _mutex->enter();
  for (auto it = _games->begin() ; it != _games->end() ; it++)
    {
      delete *it;
    }
  delete _games;
  _mutex->leave();
  _mutex->destroy();
  delete _mutex;
}

//------------------------------------END CTOR / DTOR--------------------------------------

//-----------------------------------BEGIN METHODS-------------------------------------

void				GameList::addGame(GameInfo *gameInfo)
{
  if (gameInfo)
    {
      _mutex->enter();
      _games->push_back(gameInfo);
      _mutex->leave();
    }
}

void				GameList::removeGame(std::string const &id)
{
  _mutex->enter();
  for (auto it = _games->begin() ; it != _games->end() ; it++)
    {
      if ((*it)->getId() == id)
	{
	  delete *it;
	  _games->erase(it);
	  break;
	}      
    }
  _mutex->leave();
}

void				GameList::clear()
{
  _mutex->enter();
  for (auto it = _games->begin() ; it != _games->end() ; it++)
    {
      delete *it;
    }
  _games->clear();
  _mutex->leave();
}

std::list<GameInfo *> const	&GameList::getGames(void) const
{
  std::list<GameInfo *>		*tmp;

  _mutex->enter();
  tmp = _games;
  _mutex->leave();
  return (*tmp);
}

//------------------------------------END METHODS--------------------------------------
