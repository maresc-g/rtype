//
// SpriteLoader.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Sun Nov 10 15:04:52 2013 laurent ansel
// Last update Thu Nov 14 17:29:55 2013 laurent ansel
//

#include		<iostream>
#include		<sstream>
#include		<fstream>
#include		"SpriteLoaderManager/SpriteLoader.hh"

SpriteLoader::SpriteLoader(size_t const id, std::string const &path, std::string const &confFile) :
  _id(id),
  _path(path),
  _confFile(confFile),
  _entity(new AEntity(0, 0, "", 0, false))
{
}

SpriteLoader::~SpriteLoader()
{

}

void			SpriteLoader::getLife(std::string const &content)
{
  if (this->_entity)
    {
      size_t		pos = 0;
      size_t		endPos = 0;

      if ((pos = content.find(LIFE)) != std::string::npos && (endPos = content.find("\n", pos)) != std::string::npos)
	{
	  std::istringstream	str(content.substr(pos + std::string(LIFE).size(), endPos));
	  int	life;

	  str >> life;
	  if (life > -1)
	    this->_entity->setLife(life);
	}
    }
}

void			SpriteLoader::getWidthAndHeight(std::string const &content)
{
  if (this->_entity)
    {
      size_t		pos = 0;
      size_t		endPos = 0;

      if ((pos = content.find(WIDTH)) != std::string::npos && (endPos = content.find("\n", pos)) != std::string::npos)
	{
	  std::istringstream	str(content.substr(pos + std::string(WIDTH).size(), endPos));
	  int	width;

	  str >> width;
	  if (width > -1)
	    this->_entity->setWidth(width);
	}
      if ((pos = content.find(HEIGHT)) != std::string::npos && (endPos = content.find("\n", pos)) != std::string::npos)
	{
	  std::istringstream	str(content.substr(pos + std::string(HEIGHT).size(), endPos));
	  int	height;

	  str >> height;
	  if (height > -1)
	    this->_entity->setHeight(height);
	}
    }
}

void			SpriteLoader::getSpeed(std::string const &content)
{
  if (this->_entity)
    {
      size_t		pos = 0;
      size_t		endPos = 0;

      if ((pos = content.find(SPEED)) != std::string::npos && (endPos = content.find("\n", pos)) != std::string::npos)
	{
	  std::istringstream	str(content.substr(pos + std::string(SPEED).size(), endPos));
	  int	speed;

	  str >> speed;
	  if (speed > -1 && speed < 500)
	    this->_entity->setSpeed(speed);
	}
    }
}

void			SpriteLoader::getDestructible(std::string const &content)
{
  if (this->_entity)
    {
      size_t		pos = 0;
      size_t		endPos = 0;

      if ((pos = content.find(DESTRUCTIBLE)) != std::string::npos && (endPos = content.find("\n", pos)) != std::string::npos)
	{
	  std::istringstream	str(content.substr(pos + std::string(DESTRUCTIBLE).size(), endPos));
	  bool		destructible;

	  str >> std::boolalpha >> destructible;
	  this->_entity->setDestructible(destructible);
	}
    }
}

bool			SpriteLoader::isHere(std::string const &content)
{
  static std::string	tab[] =
    {
      SPEED,
      LIFE,
      HEIGHT,
      WIDTH,
      DESTRUCTIBLE,
      FORMAT
    };
  static unsigned int size = sizeof(tab) / sizeof(*tab);
  bool			ret = false;

  for (unsigned int i = 0 ; i < size ; ++i)
    {
      if (content.find(tab[i]) != std::string::npos)
	ret = true;
    }
  return (ret);
}

InformationHitBox	*SpriteLoader::findInformationHitBox(std::string const &str)
{
  InformationHitBox	*hitbox = NULL;
  size_t		pos;
  size_t		endPos;
  size_t		posSize;

  if (!this->isHere(str) &&
      (pos = str.find(":")) != std::string::npos && (endPos = str.find("=")) != std::string::npos && (posSize = str.find("x")) != std::string::npos)
    {
      int		tmp[4];

      tmp[0] = std::stoi(str.substr(0, pos));
      tmp[1] = std::stoi(str.substr(pos + 1, endPos));
      tmp[2] = std::stoi(str.substr(endPos + 1, posSize));
      tmp[3] = std::stoi(str.substr(posSize + 1));
      hitbox = new InformationHitBox(Coordinate(tmp[0], tmp[1]), tmp[2], tmp[3]);
    }
  return (hitbox);
}

void			SpriteLoader::getInformationHitBox(std::string const &content)
{
  std::list<InformationHitBox *>	*hitbox = new std::list<InformationHitBox *>;
  InformationHitBox	*node;

  if (this->_entity)
    {
      size_t		pos = 0;
      std::stringstream	str;
      std::string	tmp;

      if ((pos = content.find(FORMAT)) != std::string::npos)
	{
	  pos += std::string(FORMAT).size() + 1;
	  str.str(content.substr(pos));
	  std::getline(str, tmp);
	  node = findInformationHitBox(tmp);
	  while (node && str.good())
	    {
	      hitbox->push_back(node);
	      std::getline(str, tmp);
	      node = findInformationHitBox(tmp);
	    }
	  if (node)
	    hitbox->push_back(node);
	}
      this->_entity->setInformationHitBox(hitbox);
    }

}

void			SpriteLoader::loadConfFile()
{
  if (_confFile != "")
    {
      std::ifstream	str;
      std::string	content;

      str.open(_confFile);
      while (str.good())
	content += str.get();
      this->getLife(content);
      this->getWidthAndHeight(content);
      this->getSpeed(content);
      this->getDestructible(content);
      this->getInformationHitBox(content);
    }
}

void			SpriteLoader::loadSprite()
{
  if (_path != "")
    {
      std::ifstream	str;

      str.open(_path);
      while (str.good())
	_content += str.get();
    }
}

size_t			SpriteLoader::getId() const
{
  return (this->_id);
}

std::string const	&SpriteLoader::getPath() const
{
  return (this->_path);
}

std::string const	&SpriteLoader::getContent() const
{
  return (this->_content);
}

std::string const	&SpriteLoader::getConfFile() const
{
  return (this->_confFile);
}

void			SpriteLoader::setId(size_t const id)
{
  this->_id = id;
}

void			SpriteLoader::setPath(std::string const &path)
{
  this->_path = path;
}

void			SpriteLoader::setConfFile(std::string const &confFile)
{
  this->_confFile = confFile;
  this->loadConfFile();
}
