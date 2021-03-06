//
// SFButton.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Fri Oct 25 15:41:38 2013 cyril jourdain
// Last update Fri Nov  8 16:58:09 2013 cyril jourdain
//

#ifndef 		__SFBUTTON_HH__
# define 		__SFBUTTON_HH__

#include		<SFML/Graphics.hpp>
#include		"Graphic/SFGraphics/Widgets/SFWidget.hh"
// TO DELETE
#include "Graphic/SFGraphics/Widgets/SFTextBox.hh"
//
class				SFButton : public SFWidget
{
public:
  sf::VertexArray		_vertices;
  sf::Texture			*_backgroundTexture;

public:
  SFButton();
  virtual ~SFButton();

public:
  void				setBackgroundTexture(sf::Texture *);

public:
  virtual void			init();
  virtual sf::FloatRect		&getBound() const;
  virtual void			setBackgroundColor(sf::Color const);
  virtual void			onClick(void *const ) {};

private:
  virtual void			draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif
