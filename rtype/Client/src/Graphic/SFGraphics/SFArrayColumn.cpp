//
// SFArrayColumn.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Nov 13 01:16:03 2013 cyril jourdain
// Last update Sun Nov 24 21:12:28 2013 cyril jourdain
//

#include			"Graphic/SFGraphics/Widgets/SFArray.hh"

SFArrayColumn::SFArrayColumn() :
  _texture(new SFImageBox()), _text(new SFLabel())
{
}

SFArrayColumn::~SFArrayColumn()
{
  if (_texture)
    delete _texture;
  if (_text)
    delete _text;
}

void				SFArrayColumn::init(sf::Texture *const texture, float x, float y,
						    float sx, float sy)
{
  _texture->init();
  _texture->setTexture(texture);
  _texture->setPosition(x, y);
  _texture->setSize(sx, sy);
  _text->init();
  _text->setTextSize(40);
  _text->setPosition(x + 50, y+5);
}

void				SFArrayColumn::setText(std::string const &text)
{
  _text->setText(text);
  _data = text;
}

std::string			SFArrayColumn::getData() const
{
  return _data;
}

void				SFArrayColumn::setTexture(sf::Texture *const text)
{
  _texture->setTexture(text);
}

void				SFArrayColumn::draw(sf::RenderTarget &target) const
{
  target.draw(*_texture);
  target.draw(*_text);
}
