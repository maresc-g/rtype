//
// SFArrayLine.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Mon Nov 11 23:40:44 2013 cyril jourdain
// Last update Mon Nov 11 23:58:59 2013 cyril jourdain
//

#include		"Graphic/SFGraphics/Widgets/SFArray.hh"

SFArrayLine::SFArrayLine(int nbColumn, sf::Vector2f const &pos, sf::Vector2f const &size) :
  _columnArray(new std::list<SFArrayColumn*>)
{
  for (int i = 0; i < nbColumn; i++)
    {
      SFArrayColumn	*ar = new SFArrayColumn();

      ar->init((*(SFRessourcesManager::getInstance()->Images))[DIALOGBOX_BACKGROUND], pos.x + 10, pos.y + 15 + (i+1)*size.y, size.x, size.y);
      _columnArray->push_back(ar);
    }
}

void			SFArrayLine::draw(sf::RenderTarget &target) const
{
  for (auto it = _columnArray->begin(); it != _columnArray->end(); ++it)
    {
      (*it)->draw(target);
    }
}

/* NOTE :*/
/*
  THIS SHIT DONT WORK
  WELL IT WORKS BUT IS NOT OP
  HAVE TO FIX SOOOOOOOOOOOOOOO MANY THINGS
  POSITION, NUMBER OF COLUMN, ETC ...
 */
