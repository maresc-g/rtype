//
// GameLoopManager.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Nov  5 10:47:00 2013 laurent ansel
// Last update Tue Nov 19 11:15:26 2013 laurent ansel
//

#include			"GameLoop/GameLoopManager.hh"

GameLoopManager::GameLoopManager():
  _idGame(1),
  _listGame(new std::list<GameLoop *>)
{

}

GameLoopManager::~GameLoopManager()
{
  for (std::list<GameLoop *>::iterator it = this->_listGame->begin() ; it != this->_listGame->end() ; ++it)
    {
      if (*it)
	{
	  (*it)->waitThread();
	  delete *it;
	}
    }
  delete this->_listGame;
}

unsigned int			GameLoopManager::pushNewGame(std::string const &name)
{
  GameLoop			*game = new GameLoop(name, this->_idGame);

  game->createThread(&startGame, game);
  game->Initialize();
  this->_listGame->push_back(game);
  this->_idGame++;
  return (game->getId());
}

bool				GameLoopManager::runGame(unsigned int const idGame)
{
  std::list<GameLoop *>::iterator	it;

  if (idGame > 0)
    {
      for (it = this->_listGame->begin() ; it != this->_listGame->end() && (*it)->getId() != idGame ; ++it);
      if (it != this->_listGame->end())
	{
	  (*it)->start();
	  return (true);
	}
    }
  return (false);
}

void				GameLoopManager::quitGame(unsigned int const id)
{
  std::list<GameLoop *>::iterator	it;

  for (it = this->_listGame->begin() ; it != this->_listGame->end() && (*it)->getId() != id ; ++it);
  if (it != this->_listGame->end())
    it = this->_listGame->erase(it);
}

std::string			GameLoopManager::listInfoGame()
{
  std::ostringstream		str;

  for (std::list<GameLoop *>::iterator it = this->_listGame->begin() ; it != this->_listGame->end() ; ++it)
    str << " " << (*it)->getId() << ";" << (*it)->getName() << ";" << (*it)->getNumPlayer() << ";" << (*it)->getLevel();
  return (str.str());
}

void				GameLoopManager::quitAllGame()
{
  for (std::list<GameLoop *>::iterator it = this->_listGame->begin() ; it != this->_listGame->end() ; ++it)
    {
      (*it)->quitGame();
    }
}

bool				GameLoopManager::addPlayerInGame(ClientInfo *client, unsigned int const idGame)
{
  std::list<GameLoop *>::iterator	it;

  if (idGame > 0)
    {
      for (it = this->_listGame->begin() ; it != this->_listGame->end() && (*it)->getId() != idGame ; ++it);
      if (it != this->_listGame->end())
	{
	  if ((*it)->newPlayer(client))
	    {
	      client->setIdGame(idGame);
	      return (true);
	    }
	  return (false);
	}
    }
  return (false);
}

bool				GameLoopManager::deletePlayer(ClientInfo *client)
{
  std::list<GameLoop *>::iterator	it;

  if (client->getIdGame())
    {
      for (it = this->_listGame->end() ; it != this->_listGame->end() && (*it)->getId() != client->getIdGame() ; ++it);
      if (it != this->_listGame->end())
	{
	  if ((*it)->deletePlayer(client))
	    {
	      client->setIdGame(0);
	      return (true);
	    }
	  return (false);
	}
    }
  return (false);
}

void				*startGame(void *data)
{
  GameLoop			*game = reinterpret_cast<GameLoop *>(data);

  if (game)
    game->loop();
  return (NULL);
}
