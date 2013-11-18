//
// FixedSprite.cpp for  in /home/jourda_c/GIT/zappy-2016/include/Graphics/Sprite
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Thu Jun 27 15:40:31 2013 cyril jourdain
// Last update Sun Nov 17 22:30:20 2013 cyril jourdain
//

#include		"Graphic/Graphics/Sprites/FixedSprite.hh"

FixedSprite::FixedSprite(float ox, float oy, float sx, float sy) : ASprite()
{
  _vertex[0].position = sf::Vector2f(0, 0);
  _vertex[1].position = sf::Vector2f(0, sy);
  _vertex[2].position = sf::Vector2f(sx, sy);
  _vertex[3].position = sf::Vector2f(sx, 0);

  _vertex[0].color = sf::Color(255, 255, 255);
  _vertex[1].color = sf::Color(255, 255, 255);
  _vertex[2].color = sf::Color(255, 255, 255);
  _vertex[3].color = sf::Color(255, 255, 255);

  _vertex[0].texCoords = sf::Vector2f(ox, oy);
  _vertex[1].texCoords = sf::Vector2f(ox, sy);
  _vertex[2].texCoords = sf::Vector2f(sx + ox, sy + oy);
  _vertex[3].texCoords = sf::Vector2f(sx + ox, oy);
}

FixedSprite::~FixedSprite()
{
}

void			FixedSprite::update(sf::Clock &)
{
  // Not used here
}

void			FixedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (_texture)
    {
      states.texture = _texture;
      states.transform *= getTransform();
      target.draw(_vertex, 4, sf::Quads, states);
    }
}
