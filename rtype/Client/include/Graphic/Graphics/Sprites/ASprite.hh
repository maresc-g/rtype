//
// ASprite.hh for  in /home/jourda_c/GIT/zappy-2016/include/Graphics/Sprite
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Thu Jun 27 15:04:10 2013 cyril jourdain
// Last update Fri Jul  5 16:28:30 2013 cyril jourdain
//

#ifndef 		__ASPRITE_HH__
# define 		__ASPRITE_HH__

# include		<SFML/System.hpp>
# include		<SFML/Graphics.hpp>

class			ASprite : public sf::Drawable, public sf::Transformable
{
protected :
  sf::Texture		*_texture;
  sf::Vertex		_vertex[4];

public:
  ASprite();
  virtual ~ASprite();

public:
  virtual void			draw(sf::RenderTarget &, sf::RenderStates) const = 0;
  virtual void			update(sf::Clock &) = 0;

public:
  void				setTexture(sf::Texture *);
  sf::Texture			*getTexture() const;
};

#endif
