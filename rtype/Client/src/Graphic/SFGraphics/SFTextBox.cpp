//
// SFTextBox.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Tue Oct 22 14:07:18 2013 cyril jourdain
// Last update Wed Nov  6 14:13:17 2013 cyril jourdain
//

#include		<iostream>
#include		"Graphic/SFGraphics/Widgets/SFTextBox.hh"
#include		"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"

SFTextBox::SFTextBox() :
  SFWidget(), _vertices(sf::Quads, 4), _cursor(sf::Quads, 4), _pos(0),
  _mask(NONE), _size(new sf::Vector2f(150,20))
{
}

SFTextBox::SFTextBox(float sizex, float sizey) :
  SFWidget(), _vertices(sf::Quads, 4), _cursor(sf::Quads, 4), _pos(0),
  _mask(NONE), _size(new sf::Vector2f(sizex, sizey))
{
}

SFTextBox::~SFTextBox()
{
}

void		SFTextBox::init()
{
  _focused = false;
  _text.setFont(SFRessourcesManager::Fonts->getFont("arial"));
  _text.setColor(sf::Color::Black);
  _text.setCharacterSize(13);
  _text.setPosition(sf::Vector2f(3,0));
  _vertices[0].position = sf::Vector2f(0,0);
  _vertices[1].position = sf::Vector2f(_size->x,0);
  _vertices[2].position = sf::Vector2f(_size->x,_size->y);
  _vertices[3].position = sf::Vector2f(0,_size->y);
  _vertices[0].color = sf::Color::White;
  _vertices[1].color = sf::Color::White;
  _vertices[2].color = sf::Color::White;
  _vertices[3].color = sf::Color::White;  
  _cursor[0].position = sf::Vector2f(3,2);
  _cursor[1].position = sf::Vector2f(5,2);
  _cursor[2].position = sf::Vector2f(5,17);
  _cursor[3].position = sf::Vector2f(3,17);
  _cursor[0].color = sf::Color::Black;
  _cursor[1].color = sf::Color::Black;
  _cursor[2].color = sf::Color::Black;
  _cursor[3].color = sf::Color::Black;  
  if (_bounds)
    *_bounds = _vertices.getBounds();
}

void		SFTextBox::addLetter(char c)
{
  if (_text.findCharacterPos(_data.length()).x <= getBound().width - _text.getCharacterSize())
    {
      _data.insert(_pos, &c, 1);
      _text.setString((_mask == PASSWORD ? std::string().assign(_data.length(), '*') : _data));
      _pos++;
      updateCursor();
    }
}

void		SFTextBox::removeLast()
{
  std::string tmp;
  std::string tmp2;
  if (_data.length() > 0 && _pos > 0){
    _data.erase(_pos - 1);
    _pos--;
    tmp2 = _text.getString();
    _data += tmp2.substr(_pos + 1);
    _text.setString((_mask == PASSWORD ? std::string().assign(_data.length(), '*') : _data));
    updateCursor();
  }
}

void		SFTextBox::moveRight()
{
  if ((size_t)(_pos + 1) <= _text.getString().getSize())
    _pos++;
  updateCursor();
}

void		SFTextBox::moveLeft()
{
  if (_pos - 1 >= 0)
    _pos--;
  updateCursor();
}

void		SFTextBox::setMask(StringMask mask)
{
  _mask = mask;
}


void		SFTextBox::setBoxSize(int const size)
{
  _vertices[1].position.x = static_cast<float>(size);
  _vertices[2].position.x = static_cast<float>(size);
  _size->x = static_cast<float>(size);
  *_bounds = _vertices.getBounds();
}

std::string	SFTextBox::getText() const
{
  return _data;
}

void		SFTextBox::updateCursor()
{
  _cursor[0].position.x = _text.findCharacterPos(_pos).x;
  _cursor[1].position.x = _text.findCharacterPos(_pos).x + 2;
  _cursor[2].position.x = _text.findCharacterPos(_pos).x + 2;
  _cursor[3].position.x = _text.findCharacterPos(_pos).x;
}

void		SFTextBox::applyStringMask()
{
  if (_mask == PASSWORD) {
    if (_text.findCharacterPos(_data.length()).x <= getBound().width - _text.getCharacterSize())
      _text.setString(std::string().assign(_data.length(), '*'));
    updateCursor();
  }
}

void		SFTextBox::checkStringLen()
{
    
}

sf::FloatRect	&SFTextBox::getBound() const
{
  return (*_bounds);
}

void		SFTextBox::setBackgroundColor(sf::Color color)
{
  _vertices[0].color = color;
  _vertices[1].color = color;
  _vertices[2].color = color;
  _vertices[3].color = color;
}

void		SFTextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  target.draw(_vertices, states);
  target.draw(_text, states);
  if (_focused)
    target.draw(_cursor, states);
}

void		SFTextBox::onKeyPressed(void *const e)
{
  sf::Event *event = reinterpret_cast<sf::Event*>(e); 
  if (event->key.code == sf::Keyboard::BackSpace)
    removeLast();
  if (event->key.code == sf::Keyboard::Left)
    moveLeft();
  if (event->key.code == sf::Keyboard::Right)
    moveRight();
}

void		SFTextBox::onTextEntered(void *const e)
{
  sf::Event *event = reinterpret_cast<sf::Event*>(e); 
  if (event->text.unicode < 128 && isprint(event->text.unicode))
    addLetter(event->text.unicode);
  if (_mask != NONE)
    applyStringMask();
}
