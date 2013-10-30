//
// Header.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:16:57 2013 laurent ansel
// Last update Tue Oct 29 13:01:56 2013 laurent ansel
//

#include			"CircularBufferManager/CircularBuffer/Trame/Header/Header.hh"


Header::Header(int const id, int const trameId):
  _id(id),
  _trameId(trameId)
{
}

Header::~Header()
{
}

int				Header::getId() const
{
  return (this->_id);
}

int				Header::getTrameId() const
{
  return (this->_trameId);
}

void				Header::setId(int const id)
{
  this->_id = id;
}

void				Header::setTrameId(int const trameId)
{
  this->_trameId = trameId;
}
