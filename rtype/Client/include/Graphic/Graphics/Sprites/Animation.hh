//
// Animation.hh for  in /home/jourda_c/GIT/zappy-2016/src/Graphics/Animation
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Jun 19 11:02:47 2013 cyril jourdain
// Last update Tue Jul  2 13:01:20 2013 cyril jourdain
//

#ifndef				__ANIMATION_HH__
# define			__ANIMATION_HH__

#include			<SFML/Graphics.hpp>
#include			<vector>
#include			<string>

class				Animation
{
private:
  sf::Texture			*_texture;
  std::vector<sf::IntRect *>	*_spriteList;
  unsigned int			_frameCount;
  unsigned int			_frameLength;

public:
  Animation();
  Animation(Animation const &);
  Animation &operator=(Animation const &);
  virtual ~Animation();

public:
  void				setSpriteSheetFromPath(std::string const &path);
  void				setSpriteSheet(sf::Texture *texure);
  void				addFrame(sf::IntRect const &);
  void				setFrameLenght(unsigned int);

public:
  sf::IntRect			*getFrame(unsigned int) const;
  sf::Texture			*getSpriteSheet() const;
  unsigned int			getFrameLenght() const;
};

#endif
