//
// Header.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:16:57 2013 laurent ansel
// Last update Tue Nov 19 19:23:51 2013 laurent ansel
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
  s_header			*header = new s_header;
  std::ostringstream		str;

  header->idClient = this->_id;
  header->idTrame = this->_trameId;
  this->_proto.copy(header->protocole, this->_proto.size());
  header->protocole[3] = 0;
  for (unsigned int i = 0 ; i < sizeof(*header) ; ++i)
    str.put(reinterpret_cast<char *>(header)[i]);
  delete header;
  return (str.str());
}

Header				*Header::toHeader(std::string const &str)
{
  s_header			*header = NULL;
  char				str2[20];
  Header			*ret = NULL;

  if (str.size() > sizeof(s_header))
    {
      str.copy(str2, sizeof(*header));
      header = reinterpret_cast<s_header *>(str2);
      ret = new Header(header->idClient, header->idTrame, header->protocole);
    }
  return (ret);
}
