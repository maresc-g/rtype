//
// Header.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:16:57 2013 laurent ansel
// Last update Fri Nov 15 13:09:01 2013 guillaume marescaux
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
  return (str.str());
}

Header				*Header::toHeader(std::string const &str)
{
  // std::istringstream		tmp(str);
  // unsigned int			id;
  // unsigned int			trameId;
  // unsigned int			pos;
  // std::string			proto;
  // bool				good = true;
  s_header			*header = NULL;
  char				str2[20];
  Header			*ret = NULL;

  if (str.size() > sizeof(s_header))
    {
      str.copy(str2, sizeof(*header));
      header = reinterpret_cast<s_header *>(str2);
      std::cout << "id = " << header->idClient << std::endl;
      std::cout << "idT = " << header->idTrame << std::endl;
      std::cout << "proto = " << header->protocole << std::endl;
      ret = new Header(header->idClient, header->idTrame, std::string(header->protocole));
    }
  // delete header;
  return (ret);
  // if (tmp.good())
  //   tmp >> id;
  // else
  //   good = false;
  // if (tmp.good())
  //   tmp >> trameId;
  // else
  //   good = false;
  // if (tmp.good())
  //   tmp >> proto;
  // else
  //   good = false;
  // if (good)
  //   {
      // str = tmp.str().substr((pos = tmp.tellg()) + 1);
      // return (new Header(id, trameId, proto));
  //   }
  // return (NULL);
}
