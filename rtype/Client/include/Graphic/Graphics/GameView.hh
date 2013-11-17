//
// GameView.hh for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Nov 16 17:56:23 2013 cyril jourdain
// Last update Sat Nov 16 18:41:25 2013 cyril jourdain
//

#ifndef 		__GAMEVIEW_HH__
# define 		__GAMEVIEW_HH__

#include		"Graphic/SFGraphics/Widgets/SFWidget.hh"
#include		"Graphic/SFGraphics/Widgets/SFImageBox.hh"

class			GameView : public SFWidget
{
private:
  SFImageBox		*_background;

public:
  GameView();
  virtual ~GameView();

public:
  virtual void			init();
  virtual sf::FloatRect		&getBound() const;
  virtual void			setBackgroundColor(sf::Color const) {};

private:
  virtual void			draw(sf::RenderTarget &target, sf::RenderStates states) const;


};

#endif
