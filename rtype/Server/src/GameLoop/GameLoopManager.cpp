//
// GameLoopManager.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Nov  5 10:47:00 2013 laurent ansel
// Last update Sun Nov 24 11:59:11 2013 laurent ansel
//

#include			"GameLoop/GameLoopManager.hh"

GameLoopManager::GameLoopManager():
  _idGame(1),
  _listGame(new std::list<GameLoop *>),
  _mutex(new Mutex)
{
  _mutex->initialize();
}

GameLoopManager::~GameLoopManager()
{
  _mutex->enter();
  for (std::list<GameLoop *>::iterator it = this->_listGame->begin() ; it != this->_listGame->end() ; ++it)
    {
      if (*it)
	{
	  (*it)->waitThread();
	  delete *it;
	}
    }
  _mutex->leave();
  delete this->_listGame;
  _mutex->destroy();
  delete _mutex;
}

unsigned int			GameLoopManager::pushNewGame(std::string const &name)
{
  _mutex->enter();
  GameLoop			*game = new GameLoop(name, this->_idGame);

  game->createThread(&startGame, game);
  game->Initialize();
  this->_listGame->push_back(game);
  this->_idGame++;
  _mutex->leave();
  return (game->getId());
}

bool				GameLoopManager::runGame(unsigned int const idGame)
{
  _mutex->enter();
  std::list<GameLoop *>::iterator	it;

  if (idGame > 0)
    {
      for (it = this->_listGame->begin() ; it != this->_listGame->end() && (*it)->getId() != idGame ; ++it);
      if (it != this->_listGame->end())
	{
	  (*it)->start();
	  _mutex->leave();
	  return (true);
	}
    }
  _mutex->leave();
  return (false);
}

void				GameLoopManager::quitGame(unsigned int const id)
{
  _mutex->enter();
  std::list<GameLoop *>::iterator	it;

  for (it = this->_listGame->begin() ; it != this->_listGame->end() && (*it)->getId() != id ; ++it);
  if (it != this->_listGame->end())
    {
      delete *it;
      it = this->_listGame->erase(it);
    }
  _mutex->leave();
}

std::string			GameLoopManager::listInfoGame()
{
  _mutex->enter();
  std::ostringstream		str;

  for (std::list<GameLoop *>::iterator it = this->_listGame->begin() ; it != this->_listGame->end() ; ++it)
    str << " " << (*it)->getId() << ";" << (*it)->getName() << ";" << (*it)->getNumPlayer() << ";" << (*it)->getLevel();
  _mutex->leave();
  return (str.str());
}

void				GameLoopManager::quitAllGame()
{
  _mutex->enter();
  for (std::list<GameLoop *>::iterator it = this->_listGame->begin() ; it != this->_listGame->end() ; ++it)
    {
      (*it)->quitGame();
    }
  _mutex->leave();
}

bool				GameLoopManager::addPlayerInGame(ClientInfo *client, unsigned int const idGame)
{
  _mutex->enter();
  std::list<GameLoop *>::iterator	it;

  if (idGame > 0)
    {
      for (it = this->_listGame->begin() ; it != this->_listGame->end() && (*it)->getId() != idGame ; ++it);
      if (it != this->_listGame->end())
	{
	  if ((*it)->newPlayer(client))
	    {
	      client->setIdGame(idGame);
	      _mutex->leave();
	      return (true);
	    }
	  _mutex->leave();
	  return (false);
	}
    }
  _mutex->leave();
  return (false);
}

bool				GameLoopManager::deletePlayer(ClientInfo *client)
{
  _mutex->enter();
  std::list<GameLoop *>::iterator	it;

  if (client->getIdGame() > 0)
    {
      for (it = this->_listGame->begin() ; it != this->_listGame->end() && (*it)->getId() != client->getIdGame() ; ++it);
      if (it != this->_listGame->end())
	{
	  if ((*it)->deletePlayer(client))
	    {
	      client->setIdGame(0);
	      _mutex->leave();
	      return (true);
	    }
	  _mutex->leave();
	  return (false);
	}
    }
  _mutex->leave();
  return (false);
}

void				*startGame(void *data)
{
  GameLoop			*game = reinterpret_cast<GameLoop *>(data);

  if (game)
    game->loop();
  return (NULL);
}
