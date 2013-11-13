//
// SFArray.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Fri Nov  8 15:38:07 2013 cyril jourdain
// Last update Wed Nov 13 02:03:32 2013 cyril jourdain
//

#include		"Graphic/SFGraphics/Widgets/SFArray.hh"
#include		"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"
#include		"Graphic/Global.hh"

SFArray::SFArray() :
  SFWidget()
{
  _customView = new sf::View(sf::FloatRect(0,0,WIN_X,WIN_Y));
  _customView->setViewport(sf::FloatRect(0,0,0.5,0.5));
  _nbColumn = 1;
}

SFArray::~SFArray()
{
}


void			SFArray::init()
{
  _background = new SFImageBox();
  _background->init();
  _background->setSize(WIN_X, WIN_Y);
  _lineArray = new std::vector<SFArrayLine *>;
  // _titleLine = new SFArrayLine(_nbColumn,
  // 			       sf::Vector2f(0,0),
  // 			       sf::Vector2f(_background->getBound().width, 80));
}

void			SFArray::create(std::list<std::string> const list)
{
  _nbColumn = (list.size() > 0 ? list.size() : 1);
  _titleLine = new SFArrayLine(std::list<std::string>(list),
			       sf::Vector2f(0,0),
   			       sf::Vector2f(_background->getBound().width, 80));
  for (auto it = list.begin(); it != list.end(); it++)
    (*_titleLine)[*it].setText(*it);
}

void			SFArray::setSize(float const x, float const y)
{
  //_background->setSize(x, y);
}

void			SFArray::setPosition(float const x, float const y)
{
  SFWidget::setPosition(sf::Vector2f(x, y));
  _background->setPosition(x, y);
}

void			SFArray::setBackgroundTexture(sf::Texture *const texture)
{
  _background->setTexture(texture);
}

void			SFArray::addLine()
{
  _lineArray->push_back(new SFArrayLine(*_titleLine->getFieldList(), sf::Vector2f(0,80),
  					sf::Vector2f(_background->getBound().width,
  						     80)));
}

SFArrayLine		&SFArray::operator[](unsigned int index)
{
  return *(*_lineArray)[index];
}

sf::FloatRect		&SFArray::getBound() const
{
  // need to fix left and top
  _bounds->left = 0;
  _bounds->top = 0;
  _bounds->width = WIN_X * _customView->getViewport().width;
  _bounds->height = WIN_Y * _customView->getViewport().height;
  return *_bounds;
}

void			SFArray::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  //states.transform *= getTransform();
  // if (_backgroundTexture)
  //   states.texture = _backgroundTexture;
  target.draw(*_background, states);
  _titleLine->draw(target);
  (*_lineArray)[0]->draw(target);
}
