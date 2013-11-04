//
// Action.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Sat Nov  2 18:02:37 2013 laurent ansel
// Last update Sun Nov  3 21:32:28 2013 laurent ansel
//

#include			"Action/Action.hh"

Action::Action():
  _action(0),
  _param("")
{
}

Action::~Action()
{
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

std::string const		&Action::getParam() const
{
  return (this->_param);
}

void				Action::setUp(bool const set)
{
  if (set)
    this->_action |= Action::UP;
  else
    this->_action &= ~(Action::UP);
}

void				Action::setDown(bool const set)
{
  if (set)
    this->_action |= Action::DOWN;
  else
    this->_action &= ~(Action::DOWN);
}

void				Action::setRight(bool const set)
{
  if (set)
    this->_action |= Action::RIGHT;
  else
    this->_action &= ~(Action::RIGHT);
}

void				Action::setLeft(bool const set)
{
  if (set)
    this->_action |= Action::LEFT;
  else
    this->_action &= ~(Action::LEFT);
}

void				Action::setFire(bool const set)
{
  if (set)
    this->_action |= Action::FIRE;
  else
    this->_action &= ~(Action::FIRE);
}

void				Action::setQuitGame(bool const set)
{
  if (set)
    this->_action |= Action::QUITGAME;
  else
    this->_action &= ~(Action::QUITGAME);
}

void				Action::setQuitAll(bool const set)
{
  if (set)
    this->_action |= Action::QUITALL;
  else
    this->_action &= ~(Action::QUITALL);
}

void				Action::setGameList(bool const set)
{
  if (set)
    this->_action |= Action::GAMELIST;
  else
    this->_action &= ~(Action::GAMELIST);
}

void				Action::setJoin(bool const set)
{
  if (set)
    this->_action |= Action::JOIN;
  else
    this->_action &= ~(Action::JOIN);
}

void				Action::setCreate(bool const set)
{
  if (set)
    this->_action |= Action::CREATE;
  else
    this->_action &= ~(Action::CREATE);
}

void				Action::setParam(std::string const &param)
{
  this->_param = param;
}
