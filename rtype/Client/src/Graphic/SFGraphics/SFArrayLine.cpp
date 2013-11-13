//
// SFArrayLine.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Mon Nov 11 23:40:44 2013 cyril jourdain
// Last update Wed Nov 13 02:02:23 2013 cyril jourdain
//

#include		"Graphic/SFGraphics/Widgets/SFArray.hh"

SFArrayLine::SFArrayLine(std::list<std::string> const &list, sf::Vector2f const &pos, sf::Vector2f const &size) :
  _columnArray(new std::map<std::string, SFArrayColumn*>)
{
  int		i = 0;

  _fieldList = new std::list<std::string>(list);
  std::cout << "list size : " << list.size() << std::endl;
  for (auto it = list.begin(); it != list.end(); it++)
    {
      SFArrayColumn	*ar = new SFArrayColumn();

      ar->init((*(SFRessourcesManager::getInstance()->Images))[ARRAY_LINE_PART],
	       (i * (size.x / list.size())), pos.y, size.x / list.size(), size.y);
      // ar->setText(*it);
      _columnArray->insert(std::pair<std::string, SFArrayColumn*>(*it, ar));
      i++;
    }
}

std::list<std::string>	*SFArrayLine::getFieldList() const
{
  return _fieldList;
}

SFArrayColumn		&SFArrayLine::operator[](std::string const &str)
{
  return *(*_columnArray)[str];
}

void			SFArrayLine::draw(sf::RenderTarget &target) const
{
  for (auto it = _columnArray->begin(); it != _columnArray->end(); ++it)
    {
      it->second->draw(target);
    }
}

/* NOTE :*/
/*
  THIS SHIT DONT WORK
  WELL IT WORKS BUT IS NOT OP
  HAVE TO FIX SOOOOOOOOOOOOOOO MANY THINGS
  POSITION, NUMBER OF COLUMN, ETC ...
 */
