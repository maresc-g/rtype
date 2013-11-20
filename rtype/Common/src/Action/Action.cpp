//
// Action.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Sat Nov  2 18:02:37 2013 laurent ansel
// Last update Wed Nov 20 12:19:01 2013 laurent ansel
//

#include			<iostream>
#include			"Action/Action.hh"

Action::Action():
  _action(new MutexVar<int>(0)),
  _param("")
{
}

Action::~Action()
{
  delete _action;
}

Action::Action(Action const &other):
  _action(NULL)
{
  *this = other;
}

Action				&Action::operator=(Action const &other)
{
  if (this != &other)
    {
      if (!this->_action)
      	this->_action = new MutexVar<int>(0);
      this->_action->setVar(other._action->getVar());
      this->_param = other._param;
    }
  return (*this);
}

Action				&Action::operator<<(int const action)
{
  static void			(Action::*func[])(bool const) =
    {
      &Action::setUp,
      &Action::setDown,
      &Action::setLeft,
      &Action::setRight,
      &Action::setFire,
      NULL
    };
  for (int i = 0 ; func[i] ; ++i)
    (this->*func[i])(action & (1 << i));
  return (*this);
}

bool				Action::getAction(Action::eAction const action) const
{
  int				act;

  act = _action->getVar();
  return act & action;
}

bool				Action::getUp() const
{
  return (getAction(Action::UP));
}

bool				Action::getDown() const
{
  return (getAction(Action::DOWN));
}

bool				Action::getRight() const
{
  return (getAction(Action::RIGHT));
}

bool				Action::getLeft() const
{
  return (getAction(Action::LEFT));
}

bool				Action::getFire() const
{
  return (getAction(Action::FIRE));
}

bool				Action::getQuitGame() const
{
  return (getAction(Action::QUITGAME));
}

bool				Action::getQuitAll() const
{
  return (getAction(Action::QUITALL));
}

bool				Action::getGameList() const
{
  return (getAction(Action::GAMELIST));
}

bool				Action::getJoin() const
{
  return (getAction(Action::JOIN));
}

bool				Action::getCreate() const
{
  return (getAction(Action::CREATE));
}

bool				Action::getGetSprite() const
{
  return (getAction(Action::GETSPRITE));
}

std::string const		&Action::getParam() const
{
  return (this->_param);
}

void				Action::setAction(bool const set, Action::eAction const action)
{
  int				act;

  act = _action->getVar();
  if (set)
    act |= action;
  else
    act &= ~action;
  _action->setVar(act);
}

void				Action::setUp(bool const set)
{
  this->setAction(set, Action::UP);
}

void				Action::setDown(bool const set)
{
  this->setAction(set, Action::DOWN);
}

void				Action::setRight(bool const set)
{
  this->setAction(set, Action::RIGHT);
}

void				Action::setLeft(bool const set)
{
  this->setAction(set, Action::LEFT);
}

void				Action::setFire(bool const set)
{
  this->setAction(set, Action::FIRE);
}

void				Action::setQuitGame(bool const set)
{
  this->setAction(set, Action::QUITGAME);
}

void				Action::setQuitAll(bool const set)
{
  this->setAction(set, Action::QUITALL);
}

void				Action::setGameList(bool const set)
{
  this->setAction(set, Action::GAMELIST);
}

void				Action::setJoin(bool const set)
{
  this->setAction(set, Action::JOIN);
}

void				Action::setCreate(bool const set)
{
  this->setAction(set, Action::CREATE);
}

void				Action::setGetSprite(bool const set)
{
  this->setAction(set, Action::GETSPRITE);
}

void				Action::setParam(std::string const &param)
{
  this->_param = param;
}

bool				Action::empty() const
{
  if (this->_action->getVar() == 0)
    return (true);
  return (false);
}

void				Action::reset()
{
  int				act = _action->getVar();

  act ^= act;
  _action->setVar(act);
}

Action::operator std::string(void) const
{
  std::string			ret;
  int				act = _action->getVar();

  ret = std::to_string(act);
  return (ret);
}
