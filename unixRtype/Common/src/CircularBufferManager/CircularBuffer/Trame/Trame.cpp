//
// Trame.cpp for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:15:14 2013 laurent ansel
// Last update Tue Oct 29 14:31:48 2013 laurent ansel
//

#include			"CircularBufferManager/CircularBuffer/Trame/Trame.hh"

Trame::Trame(Header *header, std::string const &content):
  _header(header),
  _content(content)
{
}

Trame::Trame(int const id, int const trameId, std::string const &content):
  _header(new Header(id, trameId)),
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

Header const			&Trame::getHeader() const
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
