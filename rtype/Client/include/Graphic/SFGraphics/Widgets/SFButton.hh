//
// SFButton.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Fri Oct 25 15:41:38 2013 cyril jourdain
// Last update Thu Nov  7 17:17:31 2013 cyril jourdain
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
  void test(void *const p){std::cout << "TB Contains : "<<  reinterpret_cast<SFTextBox*>(p)->getText() << std::endl;};

public:
  virtual void			init();
  virtual sf::FloatRect		&getBound() const;
  virtual void			setBackgroundColor(sf::Color const);
  virtual void			onClick(void *const ) {std::cout << "click" << std::endl;}

private:
  virtual void			draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif
