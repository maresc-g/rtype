//
// GameOver.hh for  in /home/jourda_c/Documents/C++/Rtype_test/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Nov 23 18:00:26 2013 cyril jourdain
// Last update Sat Nov 23 18:01:35 2013 cyril jourdain
//

#ifndef 		__GAMEOVER_HH__
# define 		__GAMEOVER_HH__

#include		"Graphic/SFGraphics/Widgets/SFWidget.hh"
#include		"Graphic/SFGraphics/Widgets/SFImageBox.hh"
#include		"Graphic/SFGraphics/Widgets/SFLabel.hh"
#include		"Graphic/Graphics/Sprites/AnimatedSprite.hh"

class			GameOver : public SFWidget
{
private:
  SFImageBox		*_gameOverImage;

public:
  GameOver();
  virtual ~GameOver();

public:
  virtual void			init();
  virtual sf::FloatRect		&getBound() const;
  virtual void			setBackgroundColor(sf::Color const) {};

private:
  virtual void			draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif
