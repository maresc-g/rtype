//
// CircularBuffer.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Fri Oct 25 12:51:24 2013 guillaume marescaux
// Last update Fri Oct 25 13:58:23 2013 guillaume marescaux
//

#include			"CircularBuffer/CircularBuffer.hh"

//----------------------------------BEGIN CTOR / DTOR-------------------------------------------

CircularBuffer::CircularBuffer():
  _trames(new std::list<Trame *>)
{
}


CircularBuffer::CircularBuffer(CircularBuffer const &other):
  _trames(new std::list<Trame *>(*(other._trames)))
{
}

CircularBuffer			&CircularBuffer::operator=(CircularBuffer const &other)
{
  if (this != &other)
    {
      _trames = new std::list<Trame *>(*(other._trames));
    }
  return (*this);
}

CircularBuffer::~CircularBuffer()
{
  delete _trames;
}

//----------------------------------END CTOR / DTOR-------------------------------------------

//----------------------------------BEGIN GETTERS / SETTERS-----------------------------------

Trame const			*CircularBuffer::getFirstTrame() const { return (_trames->front()); }
Trame				*CircularBuffer::popFirstTrame()
{
  Trame				*tmp;

  tmp = _trames->front();
  _trames->pop_front();
  return (tmp);
}
void				CircularBuffer::pushTrame(Trame *trame) { _trames->push_back(trame); }

//-----------------------------------END GETTERS / SETTERS------------------------------------
