//
// GameList.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Oct 29 15:03:05 2013 guillaume marescaux
// Last update Wed Nov 13 16:55:48 2013 cyril jourdain
//

#include			"Game/GameList.hh"

//-----------------------------------BEGIN CTOR / DTOR-------------------------------------

GameList::GameList():
  _games(new std::list<GameInfo *>), _mutex(new Mutex)
{
  _mutex->initialize();

  GameInfo *t = new GameInfo("1", "name1");
  GameInfo *t2 = new GameInfo("2", "name2");
  GameInfo *t3 = new GameInfo("3", "name3");
  GameInfo *t4 = new GameInfo("4", "name4");
  GameInfo *t5 = new GameInfo("5", "name5");
  GameInfo *t6 = new GameInfo("6", "name6");
  GameInfo *t7 = new GameInfo("7", "name7");
  GameInfo *t8 = new GameInfo("8", "name8");
  GameInfo *t9 = new GameInfo("9", "name9");
  GameInfo *t10 = new GameInfo("10", "name10");
  GameInfo *t11= new GameInfo("11", "name11");
  GameInfo *t12 = new GameInfo("12", "name12");
  _games->push_back(t);
  _games->push_back(t2);
  _games->push_back(t3);
  _games->push_back(t4);
  _games->push_back(t5);
  _games->push_back(t6);
  _games->push_back(t7);
  _games->push_back(t8);
  _games->push_back(t9);
  _games->push_back(t10);
  _games->push_back(t11);
  _games->push_back(t12);
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
