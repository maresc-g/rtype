//
// Header.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:16:57 2013 laurent ansel
// Last update Thu Oct 31 10:30:46 2013 laurent ansel
//

#include			"CircularBufferManager/CircularBuffer/Trame/Header/Header.hh"


Header::Header(int const id, int const trameId, std::string const &proto):
  _id(id),
  _trameId(trameId),
  _proto(proto)
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

std::string const		&Header::getProto() const
{
  return (this->_proto);
}

void				Header::setProto(std::string const &proto)
{
  this->_proto = proto;
}
