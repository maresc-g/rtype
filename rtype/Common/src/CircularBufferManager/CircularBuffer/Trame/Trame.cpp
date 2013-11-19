//
// Trame.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:15:14 2013 laurent ansel
// Last update Tue Nov 19 18:04:18 2013 laurent ansel
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
  std::ostringstream		str;

  str << this->_header->toString() << " " << this->_content;
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
  Header			*header;
  std::string			content;

  header = Header::toHeader(str);
  if (header)
    {
      content.append(str.c_str() + sizeof(s_header), str.size() - sizeof(s_header));
      return (new Trame(header, content));
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
