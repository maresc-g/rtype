//
// SFButton.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Fri Oct 25 15:49:46 2013 cyril jourdain
// Last update Wed Nov  6 14:12:43 2013 cyril jourdain
//


#include		"Graphic/SFGraphics/Widgets/SFButton.hh"

SFButton::SFButton() :
  SFWidget(), _vertices(sf::Quads, 4)
{
}

SFButton::~SFButton()
{
}

void			SFButton::setBackgroundTexture(sf::Texture *texture)
{
  if (texture)
    {
      _vertices[0].texCoords = sf::Vector2f(0, 0);
      _vertices[1].texCoords = sf::Vector2f(texture->getSize().x, 0);
      _vertices[2].texCoords = sf::Vector2f(texture->getSize().x, texture->getSize().y);
      _vertices[3].texCoords = sf::Vector2f(0, texture->getSize().y);
    }
  _backgroundTexture = texture;
}

void			SFButton::init()
{
  _focused = false;
  _vertices[0].position = sf::Vector2f(0,0);
  _vertices[1].position = sf::Vector2f(100,0);
  _vertices[2].position = sf::Vector2f(100,100);
  _vertices[3].position = sf::Vector2f(0,100);
  if (_bounds)
    *_bounds = _vertices.getBounds();
}

sf::FloatRect		&SFButton::getBound() const
{
  return (*_bounds);
}

void			SFButton::setBackgroundColor(sf::Color const color)
{
  _vertices[0].color = color;
  _vertices[1].color = color;
  _vertices[2].color = color;
  _vertices[3].color = color;  
}

void			SFButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  if (_backgroundTexture)
    states.texture = _backgroundTexture;
  target.draw(_vertices, states);
}
