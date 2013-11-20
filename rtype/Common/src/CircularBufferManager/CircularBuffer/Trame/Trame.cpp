//
// Trame.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:15:14 2013 laurent ansel
// Last update Wed Nov 20 10:49:35 2013 laurent ansel
//

#include			<list>
#include			<sstream>
#include			"Socket/ISocketClient.hh"
#include			"CircularBufferManager/CircularBuffer/Trame/Trame.hh"

Trame::Trame(std::string &str):
  _header(Header::toHeader(str)),
  _content(str)
{

}

Trame::Trame(Header *header, std::string const &content, bool const setEndTrame):
  _header(header),
  _content(content)
{
  if (setEndTrame)
    this->_content.append(END_TRAME);
}

Trame::Trame(unsigned int const id, unsigned int const trameId, std::string const &proto, std::string const &content, bool const setEndTrame):
  _header(new Header(id, trameId, proto)),
  _content(content)
{
  if (setEndTrame)
    this->_content.append(END_TRAME);
}

Trame::~Trame()
{
  if (this->_header)
    delete this->_header;
}

std::string const		&Trame::getContent() const
{
  return (this->_content);
}

Header				&Trame::getHeader() const
{
  return (*this->_header);
}

void				Trame::setHeader(Header *header)
{
  this->_header = header;
}

void				Trame::setContent(std::string const &content)
{
  this->_content = content;
}

void				Trame::appendContent(std::string const &content)
{
  this->_content.append(content);
}

std::string const		Trame::toString() const
{
  std::string			tmp = this->_content;
  s_trame			*trame = new s_trame;
  unsigned int			size = this->_content.size() + sizeof(s_header);
  std::ostringstream		str;

  trame->header.idClient = this->_header->getId();
  trame->header.idTrame = this->_header->getTrameId();
  this->_header->getProto().copy(trame->header.protocole, this->_header->getProto().size());
  trame->header.protocole[3] = 0;
  tmp.copy(trame->content, tmp.size() + 1);
  trame->content[tmp.size()] = 0;
  for (unsigned int i = 0 ; i < size ; ++i)
    str.put(reinterpret_cast<char *>(trame)[i]);
  delete trame;
  return (str.str());
}

bool				Trame::isSetEndTrame() const
{
  if (this->_content.find(END_TRAME) != std::string::npos)
    return (true);
  return (false);
}

std::list<Trame *>		*Trame::cutToListTrame(std::string const &str)
{
  std::list<Trame *>		*list = new std::list<Trame *>;
  Trame				*tmp = NULL;
  size_t			endPos = 0;
  size_t			endTrame(std::string(END_TRAME).size());

  for (size_t pos = 0 ; pos != std::string::npos ;)
    {
      endPos = str.find(END_TRAME, pos);
      if (endPos != std::string::npos)
	{
	  tmp = toTrame(str.substr(pos, endPos - pos + endTrame));
	  if (tmp)
	    list->push_back(tmp);
	  pos = endPos + endTrame;
	}
      else
	pos = endPos;
    }
  return (list);
}

Trame				*Trame::toTrame(std::string const &str)
{
  s_trame			*trame = NULL;
  static char			str2[SIZE_BUFFER + 20];
  Header			*header;
  std::string			content;

  if (str.size() > sizeof(s_header))
    {
      str.copy(str2, str.size());
      trame = reinterpret_cast<s_trame *>(str2);
      header = new Header(trame->header.idClient, trame->header.idTrame, trame->header.protocole);
      if (str.size() - sizeof(s_header) > 0)
	trame->content[str.size() - sizeof(s_header)] = 0;
      return (new Trame(header, std::string(trame->content)));
    }
  return (NULL);
}

std::list<Trame *>		*Trame::ToListTrame(unsigned int const id, unsigned int const trameId, std::string const &proto, std::string const &str)
{
  std::list<Trame *>		*list = new std::list<Trame *>;
  unsigned int			pos = SIZE_BUFFER - std::string(END_TRAME).size();
  unsigned int			size = SIZE_BUFFER - std::string(END_TRAME).size();
  Trame				*tmp = NULL;
  bool				good = true;

  for (; pos < str.size() && good; pos += size)
    {
      tmp = new Trame(id, trameId, proto, str.substr(pos - size, size));
      if (tmp)
	list->push_back(tmp);
      else
	good = false;
    }
  tmp = new Trame(id, trameId, proto, str.substr(pos - size, str.size()), true);
  if (tmp)
    list->push_back(tmp);
  if (good)
    return (list);
  return (NULL);
}
