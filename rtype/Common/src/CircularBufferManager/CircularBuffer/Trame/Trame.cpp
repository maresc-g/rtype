//
// Trame.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:15:14 2013 laurent ansel
// Last update Thu Oct 31 15:27:42 2013 laurent ansel
//

#include			<sstream>
#include			"CircularBufferManager/CircularBuffer/Trame/Trame.hh"

Trame::Trame(std::string &str):
  _header(Header::toHeader(str)),
  _content(str)
{

}

Trame::Trame(Header *header, std::string const &content):
  _header(header),
  _content(content)
{
}

Trame::Trame(unsigned int const id, unsigned int const trameId, std::string const &proto, std::string const &content):
  _header(new Header(id, trameId, proto)),
  _content(content)
{
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

Trame				*Trame::toTrame(std::string &str)
{
  Header			*header;

  header = Header::toHeader(str);
  return (new Trame(header, str));
}
