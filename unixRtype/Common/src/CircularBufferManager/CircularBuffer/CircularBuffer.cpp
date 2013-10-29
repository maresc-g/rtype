//
// CircularBuffer.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:13:43 2013 laurent ansel
// Last update Tue Oct 29 14:31:01 2013 laurent ansel
//

#include			"CircularBufferManager/CircularBuffer/CircularBuffer.hh"

CircularBuffer::CircularBuffer():
  _buffer(new std::list<Trame *>)
{
}

CircularBuffer::~CircularBuffer()
{
  if (this->_buffer)
    {
      for (std::list<Trame *>::iterator it = _buffer->begin() ; it != _buffer->end() ; ++it)
	delete *it;
      delete _buffer;
    }
}

void				CircularBuffer::pushTrame(Trame *trame)
{
  this->_buffer->push_back(trame);
}

Trame const			&CircularBuffer::getFirstTrame() const
{
  return (*this->_buffer->front());
}

Trame				*CircularBuffer::popFirstTrame()
{
  Trame				*tmp = this->_buffer->front();

  this->_buffer->pop_front();
  return (tmp);
}
