//
// Trame.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:15:14 2013 laurent ansel
// Last update Sat Nov  2 16:31:55 2013 laurent ansel
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
    this->_content += std::string(END_TRAME);
}

Trame::Trame(unsigned int const id, unsigned int const trameId, std::string const &proto, std::string const &content, bool const setEndTrame):
  _header(new Header(id, trameId, proto)),
  _content(content)
{
  if (setEndTrame)
    this->_content += std::string(END_TRAME);
}

Trame::~Trame()
{
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

Trame				*Trame::toTrame(std::string &str)
{
  Header			*header;

  header = Header::toHeader(str);
  return (new Trame(header, str));
}

std::list<Trame *>		*Trame::ToListTrame(unsigned int const id, unsigned int const trameId, std::string const &proto, std::string const &str)
{
  std::list<Trame *>		*list = new std::list<Trame *>;
  unsigned int			pos = SIZE_BUFFER - std::string(END_TRAME).size();
  unsigned int			size = SIZE_BUFFER - std::string(END_TRAME).size();

  for (; pos < str.size() ; pos += size)
    list->push_back(new Trame(id, trameId, proto, str.substr(pos - size, pos)));
  return (list);
}