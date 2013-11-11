//
// SpriteLoader.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Fri Nov  8 22:44:47 2013 laurent ansel
// Last update Sun Nov 10 15:05:11 2013 laurent ansel
//

#ifndef 			__SPRITELOADER_HH__
# define 			__SPRITELOADER_HH__

#include			<string>

class				SpriteLoader
{
public:
  enum				eType
    {

    };
private:
  size_t			_id;
  std::string			_path;
  std::string			_content;
public:
  SpriteLoader(size_t const id, std::string const &path);
  virtual ~SpriteLoader();
  size_t			getId() const;
  std::string const		&getPath() const;
  std::string const		&getContent() const;
  void				setId(size_t const id);
  void				setPath(std::string const &path);
};

#endif
