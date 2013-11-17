//
// SFArrayLine.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Mon Nov 11 23:40:44 2013 cyril jourdain
// Last update Thu Nov 14 17:18:37 2013 cyril jourdain
//

#include		"Graphic/SFGraphics/Widgets/SFArray.hh"

SFArrayLine::SFArrayLine(std::list<std::string> const &list,
			 sf::Vector2f const &pos, sf::Vector2f const &size) :
  _columnArray(new std::map<std::string, SFArrayColumn*>)
{
  int		i = 0;
  SFArrayColumn	*ar;

  _fieldList = new std::list<std::string>(list);
  _bounds = new sf::FloatRect(0,0,0,0);
  _bounds->top = pos.y;
  _bounds->left = pos.x;
  _bounds->width = size.x;
  _bounds->height = size.y;
  for (auto it = list.begin(); it != list.end(); it++)
    {
      ar = new SFArrayColumn();
      ar->init((*(SFRessourcesManager::getInstance()->Images))[ARRAY_LINE_PART],
	       (i * (size.x / list.size())), pos.y, size.x / list.size(), size.y);
      _columnArray->insert(std::pair<std::string, SFArrayColumn*>(*it, ar));
      i++;
    }
}

SFArrayLine::~SFArrayLine()
{
  for (auto it = _columnArray->begin(); it != _columnArray->end(); it++)
    delete it->second;
  _columnArray->clear();
  
}

std::list<std::string>	*SFArrayLine::getFieldList() const
{
  return _fieldList;
}

SFArrayColumn		&SFArrayLine::operator[](std::string const &str)
{
  return *(*_columnArray)[str];
}

sf::FloatRect		*SFArrayLine::getBound() const{return _bounds;}

void			SFArrayLine::setSelected(bool select)
{
  _selected = select;
  if (_selected){
    for (auto it = _columnArray->begin(); it != _columnArray->end(); it++)
      it->second->setTexture((*(SFRessourcesManager::getInstance()->Images))[ARRAY_LINE_PART_SELECTED]);
  }
  else {
    for (auto it = _columnArray->begin(); it != _columnArray->end(); it++)
      it->second->setTexture((*(SFRessourcesManager::getInstance()->Images))[ARRAY_LINE_PART]);
  }
}

bool			SFArrayLine::mouseIn(sf::Vector2f const &mouse) const
{
  if (mouse.x >= _bounds->left && mouse.x <= _bounds->left + _bounds->width &&
      mouse.y >= _bounds->top && mouse.y <= _bounds->top + _bounds->height)
    return true;
  return false;
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
