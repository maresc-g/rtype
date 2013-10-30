//
// CircularBufferManager.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:12:01 2013 laurent ansel
// Last update Tue Oct 29 15:24:11 2013 laurent ansel
//

#include			"CircularBufferManager/CircularBufferManager.hh"

CircularBufferManager::CircularBufferManager():
  _buffer(new std::map<enum CircularBufferManager::eTypeBuffer, CircularBuffer *>),
  _mutex(new Mutex)
{
  this->_buffer->insert(std::make_pair(CircularBufferManager::READ_BUFFER, new CircularBuffer));
  this->_buffer->insert(std::make_pair(CircularBufferManager::WRITE_BUFFER, new CircularBuffer));
}

CircularBufferManager::~CircularBufferManager()
{
  delete (*this->_buffer)[CircularBufferManager::READ_BUFFER];
  delete (*this->_buffer)[CircularBufferManager::WRITE_BUFFER];
  delete this->_buffer;
}

void				CircularBufferManager::pushTrame(Trame *trame, enum eTypeBuffer const type)
{
  this->_mutex->enter();
  (*this->_buffer)[type]->pushTrame(trame);
  this->_mutex->leave();
}

Trame const			&CircularBufferManager::getTrame(enum eTypeBuffer const type) const
{
  this->_mutex->enter();
  return ((*this->_buffer)[type]->getFirstTrame());
  this->_mutex->leave();
}

Trame				*CircularBufferManager::popTrame(enum eTypeBuffer const type) const
{
  this->_mutex->enter();
  return ((*this->_buffer)[type]->popFirstTrame());
  this->_mutex->leave();
}
