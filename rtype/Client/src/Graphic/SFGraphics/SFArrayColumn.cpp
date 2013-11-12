//
// SFArrayColumn.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Mon Nov 11 23:47:58 2013 cyril jourdain
// Last update Mon Nov 11 23:51:29 2013 cyril jourdain
//

#include			"Graphic/SFGraphics/Widgets/SFArray.hh"

SFArrayColumn::SFArrayColumn() :
  _texture(new SFImageBox())
{
}

void				SFArrayColumn::init(sf::Texture *const texture, float x, float y,
						    float sx, float sy)
{
  _texture->init();
  _texture->setTexture(texture);
  _texture->setPosition(x, y);
  _texture->setSize(sx - 15, sy);
}

void				SFArrayColumn::draw(sf::RenderTarget &target) const
{
  target.draw(*_texture);
}
