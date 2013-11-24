//
// Command.hh for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 15:58:12 2013 laurent ansel
// Last update Sun Nov 24 14:24:19 2013 laurent ansel
//

#ifndef 			__COMMAND_HH__
# define 			__COMMAND_HH__

#include			<sstream>
#include			"Action/Action.hh"
#include			"CircularBufferManager/CircularBufferManager.hh"

class				Command
{
private:
  Trame				*_trame;
  Action			*_action;
  bool				_command;
public:
  Command(Trame *trame);
  virtual ~Command();
  Action			&getAction() const;
  void				setAction(Action const &action);
  void				trameToAction();
  bool				commandServer() const;
  void				resetAction();
private:
  void				actionCommand(std::istringstream &str);
  void				quitGameCommand(std::istringstream &str);
  void				quitAllCommand(std::istringstream &str);
  void				gameListCommand(std::istringstream &str);
  void				joinCommand(std::istringstream &str);
  void				createCommand(std::istringstream &str);
  void				getSpriteCommand(std::istringstream &str);
};

struct				tabCommand
{
  std::string			command;
  void				(Command::*func)(std::istringstream &);
};

#endif
