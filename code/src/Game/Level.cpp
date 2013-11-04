//
// Level.cpp for level in /home/maitre_c/work/local/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 16:09:33 2013 antoine maitre
// Last update Fri Nov  1 10:56:06 2013 arthur rucquois
//

#include	"Game/Level.hh"

int		Level::getAdv() const
{
  return (this->adv);
}

void		Level::incAdv()
{
  this->adv++;
}

Level::Level()
{
}

Level::~Level()
{
}
