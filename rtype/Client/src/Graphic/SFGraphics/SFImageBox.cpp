//
// SFImageBox.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Nov  6 13:31:34 2013 cyril jourdain
// Last update Mon Nov 11 22:07:30 2013 cyril jourdain
//

#include		"Graphic/SFGraphics/Widgets/SFImageBox.hh"

SFImageBox::SFImageBox() :
  SFWidget(), _vertices(sf::Quads, 4), _backgroundTexture(NULL)
{
}

SFImageBox::SFImageBox(sf::Texture *texture) :
  SFWidget(), _vertices(sf::Quads, 4), _backgroundTexture(texture)
{
  if (texture) {
    _vertices[0].texCoords = sf::Vector2f(0, 0);
    _vertices[1].texCoords = sf::Vector2f(static_cast<float>(texture->getSize().x), 0);
    _vertices[2].texCoords = sf::Vector2f(static_cast<float>(texture->getSize().x), static_cast<float>(texture->getSize().y));
    _vertices[3].texCoords = sf::Vector2f(0, static_cast<float>(texture->getSize().y));
  }
}

SFImageBox::~SFImageBox()
{
}

void			SFImageBox::setTexture(sf::Texture *texture)
{
  if (texture)
    {
      _vertices[0].texCoords = sf::Vector2f(0, 0);
      _vertices[1].texCoords = sf::Vector2f(static_cast<float>(texture->getSize().x), 0);
      _vertices[2].texCoords = sf::Vector2f(static_cast<float>(texture->getSize().x), static_cast<float>(texture->getSize().y));
      _vertices[3].texCoords = sf::Vector2f(0, static_cast<float>(texture->getSize().y));
    }
  _backgroundTexture = texture;
}

void			SFImageBox::init()
{
  _focused = false;
  _vertices[0].position = sf::Vector2f(0,0);
  _vertices[1].position = sf::Vector2f(100,0);
  _vertices[2].position = sf::Vector2f(100,100);
  _vertices[3].position = sf::Vector2f(0,100);
  if (_bounds)
    *_bounds = _vertices.getBounds();
}

sf::FloatRect			&SFImageBox::getBound() const
{
  return (*_bounds);
}

void			SFImageBox::setBackgroundColor(sf::Color color)
{
  _vertices[0].color = color;
  _vertices[1].color = color;
  _vertices[2].color = color;
  _vertices[3].color = color;
}

void			SFImageBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  if (_backgroundTexture)
    states.texture = _backgroundTexture;
  target.draw(_vertices, states);
}
