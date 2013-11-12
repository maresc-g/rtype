//
// SFArray.hh for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Fri Nov  8 14:52:29 2013 cyril jourdain
// Last update Mon Nov 11 23:47:30 2013 cyril jourdain
//

#ifndef				__SFARRAY_HH__
# define			__SFARRAY_HH__

#include			<vector>
#include			<list>
#include			"Graphic/SFGraphics/Widgets/SFWidget.hh"
#include			"Graphic/SFGraphics/Widgets/SFImageBox.hh"
#include			"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"
#include			"Graphic/Global.hh"

class				SFArrayColumn
{
  SFImageBox			*_texture;

public:
  SFArrayColumn();
  virtual ~SFArrayColumn(){};

public:
  void				init(sf::Texture *const texture, float x, float y, float sx, float sy);
  void				draw(sf::RenderTarget &target) const;
};

class				SFArrayLine
{
private:
  std::list<SFArrayColumn*>	*_columnArray;

public:
  SFArrayLine(int nbColumn, sf::Vector2f const &pos, sf::Vector2f const &size);
  virtual ~SFArrayLine(){};

public:
  void				draw(sf::RenderTarget &target) const;
};

class				SFArray : public SFWidget
{

private:
  SFImageBox			*_background;
  int				_nbColumn;
  std::vector<SFArrayLine *>	*_lineArray;

public:
  SFArray();
  virtual ~SFArray();

public:
  virtual void			setSize(float const x, float const y);
  virtual void			setPosition(float const x, float const y);
  void				setBackgroundTexture(sf::Texture *const);
  void				addLine();

public:
  virtual void			init();
  virtual sf::FloatRect		&getBound() const {return _background->getBound();}
  virtual void			setBackgroundColor(sf::Color const) {};
  virtual void			onClick(void *const ) {std::cout << "clicked on array" << std::endl;};

private:
  virtual void			draw(sf::RenderTarget &target, sf::RenderStates states) const;


};

#endif
