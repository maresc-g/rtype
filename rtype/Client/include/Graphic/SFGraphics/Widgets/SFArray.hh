//
// SFArray.hh for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Fri Nov  8 14:52:29 2013 cyril jourdain
// Last update Mon Nov 18 14:59:56 2013 cyril jourdain
//

#ifndef				__SFARRAY_HH__
# define			__SFARRAY_HH__

#include			<vector>
#include			<list>
#include			<map>
#include			"Graphic/SFGraphics/Widgets/SFWidget.hh"
#include			"Graphic/SFGraphics/Widgets/SFImageBox.hh"
#include			"Graphic/SFGraphics/Widgets/SFLabel.hh"
#include			"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"
#include			"Graphic/Global.hh"

class				SFArrayColumn
{
  SFImageBox			*_texture;
  SFLabel			*_text;
  std::string			_data;

public:
  SFArrayColumn();
  virtual ~SFArrayColumn(){};

public:
  void				init(sf::Texture *const texture, float x, float y, float sx, float sy);
  void				draw(sf::RenderTarget &target) const;
  void				setText(std::string const &);
  std::string			getData() const;
  void				setTexture(sf::Texture *const);
};

class				SFArrayLine
{
private:
  std::map<std::string, SFArrayColumn*>	*_columnArray;
  std::list<std::string>		*_fieldList;
  sf::FloatRect				*_bounds;
  bool					_selected;

public:
  SFArrayLine(std::list<std::string> const &, sf::Vector2f const &pos, sf::Vector2f const &size);
  virtual ~SFArrayLine();

public:
  std::list<std::string>	*getFieldList() const;
  void				draw(sf::RenderTarget &target) const;
  SFArrayColumn			&operator[](std::string const &);
  sf::FloatRect			*getBound() const;
  bool				mouseIn(sf::Vector2f const &mouse) const;
  void				setSelected(bool);
};

class				SFArray : public SFWidget
{

private:
  SFImageBox			*_background;
  int				_nbColumn;
  std::vector<SFArrayLine *>	*_lineArray;
  SFArrayLine			*_titleLine;
  SFArrayLine			*_selected;

public:
  SFArray();
  virtual ~SFArray();

public:
  void				create(std::list<std::string> const);
  virtual void			setSize(float const x, float const y);
  virtual void			setPosition(float const x, float const y);
  void				setBackgroundTexture(sf::Texture *const);
  void				addLine();
  SFArrayLine			&operator[](unsigned int index);
  void				clear();
  SFArrayLine			*getSelected() const;

public:
  virtual void			init();
  virtual sf::FloatRect		&getBound() const;
  virtual void			setBackgroundColor(sf::Color const) {};
  virtual void			onClick(void *const );
  virtual void			onMouseWheelMove(void *const);

private:
  virtual void			draw(sf::RenderTarget &target, sf::RenderStates states) const;


};

#endif
