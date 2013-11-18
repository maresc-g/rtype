//
// ASprite.cpp for  in /home/jourda_c/GIT/zappy-2016/include/Graphics/Sprite
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Thu Jun 27 15:04:44 2013 cyril jourdain
// Last update Sun Nov 17 22:23:35 2013 cyril jourdain
//

#include			"Graphic/Graphics/Sprites/ASprite.hh"

ASprite::ASprite() : sf::Drawable(), sf::Transformable(),
		     _texture(NULL)
{
}

ASprite::~ASprite()
{
}

void				ASprite::setTexture(sf::Texture *texture)
{
  _texture = texture;
}

sf::Texture			*ASprite::getTexture() const
{
  return (_texture);
}
