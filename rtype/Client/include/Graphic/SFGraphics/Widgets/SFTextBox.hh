//
// SFTextBox.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Tue Oct 22 14:03:29 2013 cyril jourdain
// Last update Wed Nov  6 14:11:32 2013 cyril jourdain
//

#ifndef 		__SFTEXTBOX_HH__
# define 		__SFTEXTBOX_HH__

#include		<SFML/Graphics.hpp>
#include		<functional>
#include		"Graphic/SFGraphics/Widgets/SFWidget.hh"

class			SFTextBox : public SFWidget
{
public:
  enum StringMask
    {
      NONE,
      PASSWORD
    };

  public:
  sf::VertexArray	_vertices;
  sf::VertexArray	_cursor;
  int			_pos;
  StringMask		_mask;
  sf::Vector2f		*_size;
  sf::Text		_text;
  std::string		_data;

public:
  SFTextBox();
  SFTextBox(float, float);
  virtual ~SFTextBox();

public:
  void		addLetter(char c);
  void		removeLast();
  void		moveRight();
  void		moveLeft();
  void		setMask(StringMask);
  void		setBoxSize(int const size);
  std::string	getText() const;

private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  void		updateCursor();
  void		applyStringMask();
  void		checkStringLen();

public: // virtual inherited from SFWidget
  virtual void		init();
  virtual sf::FloatRect	&getBound() const;
  virtual void		setBackgroundColor(sf::Color);
  virtual void		onKeyPressed(void *const);
  virtual void		onTextEntered(void *const);
};

#endif
