//
// Header.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Fri Oct 25 12:57:53 2013 guillaume marescaux
// Last update Fri Oct 25 13:49:00 2013 guillaume marescaux
//

#include		"CircularBuffer/Header.hh"

//----------------------------------BEGIN CTOR / DTOR-------------------------------------------

Header::Header(int id, int trameId):
  _id(id), _trameId(trameId)
{
}

Header::Header(Header const &other):
  _id(other._id), _trameId(other._trameId)
{
}

Header			&Header::operator=(Header const &other)
{
  if (this != &other)
    {
      _id = other._id;
      _trameId = other._trameId;
    }
  return (*this);
}

Header::~Header() {}

//----------------------------------END CTOR / DTOR-------------------------------------------
