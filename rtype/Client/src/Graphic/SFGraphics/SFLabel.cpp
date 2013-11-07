//
// SFLabel.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Nov  6 13:32:13 2013 cyril jourdain
// Last update Wed Nov  6 14:13:03 2013 cyril jourdain
//

#include		"Graphic/SFGraphics/Widgets/SFLabel.hh"
#include		"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"

SFLabel::SFLabel() :
  SFWidget(), _label(new sf::Text)
{
}

SFLabel::~SFLabel()
{
}

void			SFLabel::setText(std::string const &text)
{
  _label->setString(text);
}

void			SFLabel::init()
{
  _label->setFont(SFRessourcesManager::Fonts->getFont("arial"));
  _label->setColor(sf::Color::Black);
  _label->setCharacterSize(13);
  _label->setPosition(sf::Vector2f(0,0));
  *_bounds = _label->getGlobalBounds();
}

sf::FloatRect		&SFLabel::getBound() const
{
  return (*_bounds);
}

void			SFLabel::setBackgroundColor(sf::Color)
{
}

void			SFLabel::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  target.draw(*_label, states);
}
