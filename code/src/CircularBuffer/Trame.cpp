//
// Trame.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Fri Oct 25 12:55:01 2013 guillaume marescaux
// Last update Fri Oct 25 13:49:09 2013 guillaume marescaux
//

#include			"CircularBuffer/Trame.hh"

//----------------------------------BEGIN CTOR / DTOR-------------------------------------------

Trame::Trame(std::string const &content):
  _header(new Header), _content(content)
{
}

Trame::Trame(Trame const &other):
  _header(new Header(*(other._header))), _content(other._content)
{
}

Trame				&Trame::operator=(Trame const &other)
{
  if (this != &other)
    {
      _header = new Header(*(other._header));
      _content = other._content;
    }
  return (*this);
}

Trame::~Trame()
{
  delete _header;
}

//----------------------------------END CTOR / DTOR-------------------------------------------
