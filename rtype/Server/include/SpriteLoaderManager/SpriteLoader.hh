//
// SpriteLoader.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Fri Nov  8 22:44:47 2013 laurent ansel
// Last update Fri Nov 15 15:44:32 2013 antoine maitre
//

#ifndef 			__SPRITELOADER_HH__
# define 			__SPRITELOADER_HH__

#include			<list>
#include			<string>
#include			"Entities/AEntity.hh"

#define	SPAWN			"spwanProjectile="
#define	LIFE			"life="
#define	HEIGHT			"height="
#define	WIDTH			"width="
#define	SPEED			"speed="
#define	DESTRUCTIBLE		"destructible="
#define	FORMAT			"format:"

class				SpriteLoader
{
private:
  size_t			_id;
  std::string			_path;
  std::string			_content;
  std::string			_confFile;
  AEntity			*_entity;
  std::pair<std::string, std::string>	_confClient;
public:
  SpriteLoader(size_t const id, std::string const &path, std::string const &confFile = "");
  virtual ~SpriteLoader();
  size_t			getId() const;
  std::string const		&getPath() const;
  std::string const		&getContent() const;
  std::string const		&getConfFile() const;
  void				setId(size_t const id);
  void				setPath(std::string const &path);
  void				setConfFile(std::string const &file);
  void				setNameConfClient(std::string const &name);
  std::string const		&getNameConfClient() const;
  std::string const		&getContentConfClient() const;
private:
  void				loadConfFile();
  void				loadConfClient();
  void				loadSprite();
  void				getSpeed(std::string const &content);
  void				getDestructible(std::string const &content);
  InformationHitBox		*findInformationHitBox(std::string const &str);
  void				getInformationHitBox(std::string const &content);
  void				getWidthAndHeight(std::string const &content);
  void				getLife(std::string const &content);
  bool				isHere(std::string const &content);
  void				getSpawnCoordinate(std::string const &content);
};

#endif
