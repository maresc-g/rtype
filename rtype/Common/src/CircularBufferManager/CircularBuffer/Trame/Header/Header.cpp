//
// Header.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:16:57 2013 laurent ansel
// Last update Mon Nov  4 19:17:45 2013 laurent ansel
//

#include			<sstream>
#include			"CircularBufferManager/CircularBuffer/Trame/Header/Header.hh"

Header::Header(unsigned int const id, unsigned int const trameId, std::string const &proto):
  _id(id),
  _trameId(trameId),
  _proto(proto)
{
}

Header::~Header()
{
}

unsigned int			Header::getId() const
{
  return (this->_id);
}

unsigned int			Header::getTrameId() const
{
  return (this->_trameId);
}

void				Header::setId(unsigned int const id)
{
  this->_id = id;
}

void				Header::setTrameId(unsigned int const trameId)
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
  unsigned int			id;
  unsigned int			trameId;
  unsigned int			pos;
  std::string			proto;
  std::string			content;
  bool				good = true;

  if (tmp.good())
    tmp >> id;
  else
    good = false;
  if (tmp.good())
    tmp >> trameId;
  else
    good = false;
  if (tmp.good())
    tmp >> proto;
  else
    good = false;
  if (good)
    {
      content = tmp.str().substr((pos = tmp.tellg()) + 1);
      return (new Header(id, trameId, proto));
    }
  return (NULL);
}
