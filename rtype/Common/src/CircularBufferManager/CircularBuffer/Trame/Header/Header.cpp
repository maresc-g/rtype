//
// Header.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:16:57 2013 laurent ansel
// Last update Thu Oct 31 13:15:38 2013 laurent ansel
//

#include			<sstream>
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

std::string const		Header::toString() const
{
  std::ostringstream		str;

  str << this->_id << " " << this->_trameId << " " << this->_proto;
  return (str.str());
}

Header				*Header::toHeader(std::string &str)
{
  std::istringstream		tmp(str);
  int				id;
  int				trameId;
  std::string			proto;
  std::string			content;

  tmp >> id;
  tmp >> trameId;
  tmp >> proto;
  tmp >> content;
  str = content;
  return (new Header(id, trameId, proto));
}
