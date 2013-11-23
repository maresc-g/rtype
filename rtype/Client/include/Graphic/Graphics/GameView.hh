//
// GameView.hh for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Nov 16 17:56:23 2013 cyril jourdain
// Last update Sat Nov 23 17:13:07 2013 cyril jourdain
//

#ifndef 		__GAMEVIEW_HH__
# define 		__GAMEVIEW_HH__

#include		"Graphic/SFGraphics/Widgets/SFWidget.hh"
#include		"Graphic/SFGraphics/Widgets/SFImageBox.hh"
#include		"Graphic/Graphics/Sprites/FixedSprite.hh"
#include		"Graphic/Graphics/Sprites/AnimatedSprite.hh"
#include		"Graphic/PressedKey.hh"

class			GameView : public SFWidget
{
private:
  SFImageBox		*_background;
  AnimatedSprite	*_player;
  AnimatedSprite	*_rocket;
  sf::Clock		*_clock;
  PressedKey		*_keys;
  unsigned int		_scroll;
  int			_totalScroll;
  sf::Clock		*_clockScroll;

public:
  GameView();
  virtual ~GameView();

public:
  virtual void			init();
  virtual sf::FloatRect		&getBound() const;
  virtual void			setBackgroundColor(sf::Color const) {};
  void				update(sf::RenderWindow *);
  void				checkKeys();
  void				reset();

private:
  virtual void			draw(sf::RenderTarget &target, sf::RenderStates states) const;
  virtual void			onKeyPressed(void *const key);

};

#endif
