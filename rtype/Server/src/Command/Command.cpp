//
// Command.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 16:01:59 2013 laurent ansel
// Last update Sun Nov  3 21:35:34 2013 laurent ansel
//

#include			"Command/Command.hh"

Command::Command(Trame *trame):
  _trame(trame),
  _action(new Action)
{
}

Command::~Command()
{
  if (this->_trame)
    delete this->_trame;
}

Action				&Command::getAction() const
{
  return (*this->_action);
}

void				Command::upCommand(std::istringstream &)
{
  this->_action->setUp(true);
}

void				Command::downCommand(std::istringstream &)
{
  this->_action->setDown(true);
}

void				Command::leftCommand(std::istringstream &)
{
  this->_action->setLeft(true);
}

void				Command::rightCommand(std::istringstream &)
{
  this->_action->setRight(true);
}

void				Command::fireCommand(std::istringstream &)
{
  this->_action->setFire(true);
}

void				Command::quitGameCommand(std::istringstream &)
{
  this->_action->setQuitGame(true);
}

void				Command::quitAllCommand(std::istringstream &)
{
  this->_action->setQuitGame(true);
  this->_action->setQuitAll(true);
}

void				Command::gameListCommand(std::istringstream &)
{
  this->_action->setGameList(true);
}

void				Command::joinCommand(std::istringstream &str)
{
  std::string			param;

  str >> param;
  this->_action->setParam(param);
  this->_action->setJoin(true);
}

void				Command::createCommand(std::istringstream &str)
{
  std::string			param;

  str >> param;
  this->_action->setParam(param);
  this->_action->setCreate(true);
}

void				Command::trameToAction()
{
  static tabCommand		tab[] =
    {
      {"UP", &Command::upCommand},
      {"DOWN", &Command::downCommand},
      {"LEFT", &Command::leftCommand},
      {"RIGHT", &Command::downCommand},
      {"FIRE", &Command::fireCommand},
      {"QUITGAME", &Command::quitGameCommand},
      {"QUITALL", &Command::quitAllCommand},
      {"GAMELIST", &Command::gameListCommand},
      {"JOIN", &Command::joinCommand},
      {"CREATE", &Command::createCommand}
    };
  static unsigned int		size = sizeof(tab) / sizeof(*tab);
  if (this->_trame)
    {
      std::istringstream	str(this->_trame->getContent());
      std::string		content;

      for (unsigned int i = 0 ; i < size ; i++)
	{
	  content = "";
	  str >> content;
	  if (content == tab[i].command)
	    (this->*tab[i].func)(str);
	}
    }
}
