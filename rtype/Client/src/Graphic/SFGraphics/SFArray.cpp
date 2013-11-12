//
// SFArray.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Fri Nov  8 15:38:07 2013 cyril jourdain
// Last update Mon Nov 11 23:50:19 2013 cyril jourdain
//

#include		"Graphic/SFGraphics/Widgets/SFArray.hh"
#include		"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"
#include		"Graphic/Global.hh"

SFArray::SFArray() :
  SFWidget()
{
}

SFArray::~SFArray()
{
}


void			SFArray::init()
{
  _background = new SFImageBox();
  _background->init();
  _lineArray = new std::vector<SFArrayLine *>;
}

void			SFArray::setSize(float const x, float const y)
{
  _background->setSize(x, y);
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
  _lineArray->push_back(new SFArrayLine(2, _background->getPosition(),
					sf::Vector2f(_background->getBound().width,
						     80)));
}

void			SFArray::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  //states.transform *= getTransform();
  // if (_backgroundTexture)
  //   states.texture = _backgroundTexture;
  target.draw(*_background, states);
  (*_lineArray)[0]->draw(target);
}
