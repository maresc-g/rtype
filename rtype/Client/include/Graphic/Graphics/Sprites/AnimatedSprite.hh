//
// AnimatedSprite.hh for  in /home/jourda_c/GIT/zappy-2016/src/Graphics/Animation
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Jun 19 13:33:40 2013 cyril jourdain
// Last update Thu Nov 21 14:05:20 2013 cyril jourdain
//

#ifndef 		__ANIMATEDSPRITE_HH__
# define 		__ANIMATEDSPRITE_HH__

# include		<SFML/Graphics.hpp>
# include		<SFML/System.hpp>
# include		<SFML/Graphics/RenderTarget.hpp>
# include		<SFML/System/Time.hpp>
# include		<SFML/Graphics/Drawable.hpp>
# include		<SFML/Graphics/Transformable.hpp>
# include		<SFML/System/Vector2.hpp>
# include		<string>
# include		"Animation.hh"
# include		"ASprite.hh"

class			AnimatedSprite : public ASprite
{
private:
  std::map<std::string, Animation *>	*_animations;
  bool			_isPlaying;
  std::string		_current;
  unsigned int		_count;
  bool			_loopPlay;

public:
  AnimatedSprite();
  AnimatedSprite(AnimatedSprite const &);
  AnimatedSprite &operator=(AnimatedSprite const &);
  virtual ~AnimatedSprite();

public:
  void			play(std::string const &);
  void			pause();
  void			addAnimation(std::string const &, Animation *, bool loopPlay = false);
  void			loadFromFile(std::string const &file);
  virtual void		update(sf::Clock &);

private:
  virtual void		draw(sf::RenderTarget &, sf::RenderStates states) const;
};

#endif
