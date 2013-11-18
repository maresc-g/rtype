//
// FixedSprite.hh for  in /home/jourda_c/GIT/zappy-2016/include/Graphics/Sprite
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Thu Jun 27 15:36:49 2013 cyril jourdain
// Last update Thu Jun 27 16:00:17 2013 cyril jourdain
//

#ifndef 		__FIXEDSPRITE_HH__
# define 		__FIXEDSPRITE_HH__

# include		<SFML/System.hpp>
# include		<SFML/Graphics.hpp>
# include		"ASprite.hh"

class			FixedSprite : public ASprite
{
public:
  FixedSprite(float, float, float, float);
  virtual ~FixedSprite();

public:
  virtual void		update(sf::Clock &clock);
  virtual void		draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif
