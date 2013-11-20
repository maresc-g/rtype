//
// SpriteLoader.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Fri Nov  8 22:44:47 2013 laurent ansel
// Last update Wed Nov 20 15:05:51 2013 laurent ansel
//

#ifndef 			__SPRITELOADER_HH__
# define 			__SPRITELOADER_HH__

#include			<list>
#include			<string>
#include			"Entities/AEntity.hh"

#define	SPAWN			"spawnProjectile="
#define	LIFE			"life="
#define	HEIGHT			"height="
#define	WIDTH			"width="
#define	SPEED			"speed="
#define	DESTRUCTIBLE		"destructible="
#define	FORMAT			"format:"

#define	CONFCLIENT		".sprite"
#define	CONFSERVER		".conf"

struct				s_entity
{
  int			_width;
  int			_height;
  unsigned int		_life;
  Coordinate		*_coord;
  std::string		_path;
  int			_speed;
  bool			_destructible;
  bool			_dead;
  std::string
  std::list<InformationHitBox *>	*_hitbox;
  Coordinate			*_spawnProjectile;
};

class				SpriteLoader
{
private:
  size_t			_id;
  std::string			_path;
  std::string			_content;
  std::string			_confFile;
  s_entity			*_entity;
  std::pair<std::string, std::string>	_confClient;
public:
  SpriteLoader(size_t const id, std::string const &path, std::string const &confFile = "");
  virtual ~SpriteLoader();
  SpriteLoader			&operator>>(AEntity &entity);
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
  void				loadSprite();
private:
  void				loadConfFile();
  void				loadConfClient();
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
