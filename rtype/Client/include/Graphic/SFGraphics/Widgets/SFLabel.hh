//
// SFLabel.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Mon Oct 28 16:20:17 2013 cyril jourdain
// Last update Sun Nov 17 22:50:16 2013 cyril jourdain
//

#ifndef 		__SFLABEL_HH__
# define 		__SFLABEL_HH__

#include			"Graphic/SFGraphics/Widgets/SFWidget.hh"

class				SFLabel : public SFWidget
{
public:
  sf::Text			*_label;

public:
  SFLabel();
  virtual ~SFLabel();

public:
  void				setText(std::string const &text);
  void				setTextSize(unsigned int const size);
  void				setColor(sf::Color const);

public:
  virtual void			init();
  virtual sf::FloatRect		&getBound() const;
  virtual void			setBackgroundColor(sf::Color);

private:
  virtual void			draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif
