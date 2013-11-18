//
// Action.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Sat Nov  2 18:02:37 2013 laurent ansel
// Last update Mon Nov 18 17:21:56 2013 laurent ansel
//

#include			<iostream>
#include			"Action/Action.hh"

Action::Action():
  _action(0),
  _param("")
{
}

Action::~Action()
{
}

Action				&Action::operator=(Action const &other)
{
  if (this != &other)
    {
      this->_action = other._action;
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
      &Action::setRight,
      &Action::setLeft,
      &Action::setFire
    };
  for (int i = 0 ; i < Action::QUITGAME ; ++i)
    (this->*func[i])(action & (1 << i));
  return (*this);
}

bool				Action::getUp() const
{
  return (this->_action & Action::UP);
}

bool				Action::getDown() const
{
  return (this->_action & Action::DOWN);
}

bool				Action::getRight() const
{
  return (this->_action & Action::RIGHT);
}

bool				Action::getLeft() const
{
  return (this->_action & Action::LEFT);
}

bool				Action::getFire() const
{
  return (this->_action & Action::FIRE);
}

bool				Action::getQuitGame() const
{
  return (this->_action & Action::QUITGAME);
}

bool				Action::getQuitAll() const
{
  return (this->_action & Action::QUITALL);
}

bool				Action::getGameList() const
{
  return (this->_action & Action::GAMELIST);
}

bool				Action::getJoin() const
{
  return (this->_action & Action::JOIN);
}

bool				Action::getCreate() const
{
  return (this->_action & Action::CREATE);
}

bool				Action::getGetSprite() const
{
  return (this->_action & Action::GETSPRITE);
}

std::string const		&Action::getParam() const
{
  return (this->_param);
}

void				Action::setAction(bool const set, Action::eAction const action)
{
  if (set)
    this->_action |= action;
  else
    this->_action &= ~action;
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
  if (this->_action == 0)
    return (true);
  return (false);
}

void				Action::reset()
{
  _action ^= _action;
}
