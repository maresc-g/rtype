//
// CircularBufferManager.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Fri Oct 25 11:18:10 2013 guillaume marescaux
// Last update Fri Oct 25 13:48:51 2013 guillaume marescaux
//

#include		"CircularBuffer/CircularBufferManager.hh"

//----------------------------------BEGIN CTOR / DTOR-------------------------------------------

CircularBufferManager::CircularBufferManager():
  _buffers(new std::map<eTypeBuffer, CircularBuffer *>)
{
  _buffers->insert(std::pair<eTypeBuffer, CircularBuffer *>(READ_BUFFER, new CircularBuffer));
  _buffers->insert(std::pair<eTypeBuffer, CircularBuffer *>(WRITE_BUFFER, new CircularBuffer));
}

CircularBufferManager::~CircularBufferManager()
{
  for (auto it = _buffers->begin() ; it != _buffers->end() ; it++)
    {
      delete (*it).second;
    }
  delete _buffers;
}

//----------------------------------END CTOR / DTOR-------------------------------------------

//----------------------------------BEGIN METHODS-------------------------------------------

void			CircularBufferManager::pushTrame(Trame *trame, eTypeBuffer type)
{
  (*_buffers)[type]->pushTrame(trame);
}

Trame const		*CircularBufferManager::getTrame(eTypeBuffer type) const
{
  return ((*_buffers)[type]->getFirstTrame());
}

Trame			*CircularBufferManager::popTrame(eTypeBuffer type)
{
  return ((*_buffers)[type]->popFirstTrame());
}

//----------------------------------END METHODS-------------------------------------------
