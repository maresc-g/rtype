//
// GameHud.hh for  in /home/jourda_c/Documents/C++/Rtype_test/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Nov 23 17:12:57 2013 cyril jourdain
// Last update Sat Nov 23 23:29:11 2013 cyril jourdain
//

#ifndef 		__GAMEHUD_HH__
# define 		__GAMEHUD_HH__

#include		"Graphic/SFGraphics/Widgets/SFWidget.hh"
#include		"Graphic/SFGraphics/Widgets/SFImageBox.hh"
#include		"Graphic/SFGraphics/Widgets/SFLabel.hh"
#include		"Graphic/Graphics/Sprites/FixedSprite.hh"
#include		"Graphic/Graphics/Sprites/AnimatedSprite.hh"

class			GameHud : public SFWidget
{
private:
  SFImageBox		*_background;
  SFLabel		*_score;
  SFImageBox		*_life;

public:
  GameHud();
  virtual ~GameHud();

public:
  virtual void			init();
  virtual sf::FloatRect		&getBound() const;
  virtual void			setBackgroundColor(sf::Color const) {};
  void				updateScore();

private:
  virtual void			draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif
