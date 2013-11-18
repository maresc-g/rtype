//
// CircularBufferManager.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:12:01 2013 laurent ansel
// Last update Mon Nov 18 14:49:50 2013 laurent ansel
//

#include			"CircularBufferManager/CircularBufferManager.hh"

CircularBufferManager::CircularBufferManager():
  _buffer(new std::map<enum CircularBufferManager::eTypeBuffer, CircularBuffer *>),
  _mutex(new Mutex)
{
  this->_buffer->insert(std::make_pair(CircularBufferManager::READ_BUFFER, new CircularBuffer));
  this->_buffer->insert(std::make_pair(CircularBufferManager::WRITE_BUFFER, new CircularBuffer));
  this->_mutex->initialize();
}

CircularBufferManager::~CircularBufferManager()
{
  delete (*this->_buffer)[CircularBufferManager::READ_BUFFER];
  delete (*this->_buffer)[CircularBufferManager::WRITE_BUFFER];
  delete this->_buffer;
  this->_mutex->destroy();
  delete this->_mutex;
}

void				CircularBufferManager::pushTrame(Trame *trame, enum eTypeBuffer const type)
{
  this->_mutex->enter();
  if (type == CircularBufferManager::WRITE_BUFFER)
    (*this->_buffer)[type]->pushTrame(trame, true);
  else
    (*this->_buffer)[type]->pushTrame(trame, false);
  this->_mutex->leave();
}

void				CircularBufferManager::pushFrontTrame(Trame *trame, enum eTypeBuffer const type)
{
  this->_mutex->enter();
  if (type == CircularBufferManager::WRITE_BUFFER)
    (*this->_buffer)[type]->pushTrame(trame, true);
  else
    (*this->_buffer)[type]->pushTrame(trame, false);
  this->_mutex->leave();
}


Trame const			&CircularBufferManager::getTrame(enum eTypeBuffer const type) const
{
  Trame const			*tmp;

  this->_mutex->enter();
  tmp = &(*this->_buffer)[type]->getFirstTrame();
  this->_mutex->leave();
  return (*tmp);
}

Trame				*CircularBufferManager::popTrame(enum eTypeBuffer const type) const
{
  Trame				*tmp;

  this->_mutex->enter();
  tmp = (*this->_buffer)[type]->popFirstTrame();
  this->_mutex->leave();
  return (tmp);
}

Trame				*CircularBufferManager::popTrame(unsigned int const id, std::string const &proto, enum eTypeBuffer const type) const
{
  Trame				*tmp;

  this->_mutex->enter();
  tmp = (*this->_buffer)[type]->popFirstTrame(id, proto);
  this->_mutex->leave();
  return (tmp);
}

void				CircularBufferManager::deleteTrame(unsigned int const id)
{
  this->_mutex->enter();
  (*this->_buffer)[CircularBufferManager::READ_BUFFER]->deleteTrame(id);
  (*this->_buffer)[CircularBufferManager::WRITE_BUFFER]->deleteTrame(id);
  this->_mutex->leave();
}
