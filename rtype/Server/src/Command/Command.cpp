//
// Command.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 16:01:59 2013 laurent ansel
// Last update Mon Nov 18 17:13:14 2013 laurent ansel
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
  delete this->_action;
}

Action				&Command::getAction() const
{
  return (*this->_action);
}

void				Command::setAction(Action const &action)
{
  *this->_action = action;
}

void				Command::actionCommand(std::istringstream &str)
{
  std::istringstream		param;
  size_t			pos;
  size_t			posEnd;
  int				action;

  if ((posEnd = str.str().rfind(END_TRAME)) == std::string::npos)
    param.str(str.str().substr((pos = str.tellg()) + 1));
  else
    param.str(str.str().substr((pos = str.tellg()) + 1, (posEnd - 1) - std::string(END_TRAME).size()));
  param >> action;
  *this->_action << action;
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
  size_t			pos;
  size_t			posEnd;

  if ((posEnd = str.str().rfind(END_TRAME)) == std::string::npos)
    param = str.str().substr((pos = str.tellg()) + 1);
  else
    param = str.str().substr((pos = str.tellg()) + 1, (posEnd - 1) - std::string(END_TRAME).size());
  this->_action->setParam(param);
  this->_action->setJoin(true);
}

void				Command::createCommand(std::istringstream &str)
{
  std::string			param;
  size_t			pos;
  size_t			posEnd;

  if ((posEnd = str.str().rfind(END_TRAME)) == std::string::npos)
    param = str.str().substr((pos = str.tellg()) + 1);
  else
    param = str.str().substr((pos = str.tellg()) + 1, (posEnd - 1) - std::string(END_TRAME).size());
  this->_action->setParam(param);
  this->_action->setCreate(true);
}

void				Command::getSpriteCommand(std::istringstream &str)
{
  std::string			param;
  size_t			pos;
  size_t			posEnd;

  if ((posEnd = str.str().rfind(END_TRAME)) == std::string::npos)
    param = str.str().substr((pos = str.tellg()) + 1);
  else
    param = str.str().substr((pos = str.tellg()) + 1, (posEnd - 1) - std::string(END_TRAME).size());
  this->_action->setParam(param);
  this->_action->setGetSprite(true);

}

void				Command::trameToAction()
{
  static tabCommand		tab[] =
    {
      {"ACTION", &Command::actionCommand},
      {"QUITGAME", &Command::quitGameCommand},
      {"QUITSERVER", &Command::quitAllCommand},
      {"GAMELIST", &Command::gameListCommand},
      {"JOIN", &Command::joinCommand},
      {"CREATE", &Command::createCommand},
      {"GETSPRITE", &Command::getSpriteCommand}
    };
  static unsigned int		size = sizeof(tab) / sizeof(*tab);

  if (this->_trame)
    {
      std::istringstream	str(this->_trame->getContent());
      std::string		content;
      size_t			pos;

      while (str.good())
	{
	  content = "";
	  str >> content;
	  if ((pos = content.find(END_TRAME)) != std::string::npos)
	    content = content.substr(0, pos);
	  for (unsigned int i = 0 ; i < size ; i++)
	    {
	      if (content == tab[i].command)
		(this->*tab[i].func)(str);
	    }
	}
    }
}
