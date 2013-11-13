//
// SFImageBox.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Mon Oct 28 14:25:59 2013 cyril jourdain
// Last update Mon Nov 11 22:10:52 2013 cyril jourdain
//

#ifndef 		__SFIMAGEBOX_HH__
# define 		__SFIMAGEBOX_HH__

#include		"Graphic/SFGraphics/Widgets/SFWidget.hh"

class			SFImageBox : public SFWidget
{
private:
  sf::VertexArray	_vertices;
  sf::Texture		*_backgroundTexture;

public:
  SFImageBox();
  SFImageBox(sf::Texture *);
  virtual ~SFImageBox();

public:
  void			setTexture(sf::Texture *);

public:
  virtual void		init();
  virtual sf::FloatRect	&getBound() const;
  virtual void		setBackgroundColor(sf::Color);

private:
  virtual void		draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif
