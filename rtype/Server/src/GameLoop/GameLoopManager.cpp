//
// GameLoopManager.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Nov  5 10:47:00 2013 laurent ansel
// Last update Wed Nov 13 21:42:47 2013 laurent ansel
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

void				GameLoopManager::pushNewGame(std::string const &name)
{
  (void)name;
  GameLoop			*game = new GameLoop(/*name, this->_idGame*/);

  game->createThread(&startGame, game);
  this->_listGame->push_back(game);
  this->_idGame++;
}

std::string			GameLoopManager::listInfoGame()
{
  std::ostringstream		str;

  for (std::list<GameLoop *>::iterator it = this->_listGame->begin() ; it != this->_listGame->end() ; ++it)
    {
      (*it)->enter();
      str << " " << (*it)->getId() << ";" << (*it)->getName() << ";" << (*it)->getNumPlayer() << ";" << (*it)->getLevel();
      (*it)->leave();
    }
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
	  if ((*it)->setPlayer(client))
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
