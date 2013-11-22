//
// AnimatedSprite.cpp for  in /home/jourda_c/GIT/zappy-2016/src/Graphics/Animation
//
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
//
// Started on  Wed Jun 19 13:45:16 2013 cyril jourdain
// Last update Fri Nov 22 15:33:55 2013 cyril jourdain
//

#include	"Graphic/Graphics/Sprites/AnimatedSprite.hh"
#include	<iostream>
#include	<fstream>
#include	<sstream>
#include	"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"
//#include <GL/gl.h>

AnimatedSprite::AnimatedSprite() :
  _animations(new std::map<std::string, Animation *>),
  _isPlaying(false), _current(""), _count(0), _loopPlay(false), _old("")
{
  _vertex[0].position = sf::Vector2f(0, 0);
  _vertex[1].position = sf::Vector2f(0, 1);
  _vertex[2].position = sf::Vector2f(1, 1);
  _vertex[3].position = sf::Vector2f(1, 0);

  _vertex[0].color = sf::Color(255, 255, 255, 255);
  _vertex[1].color = sf::Color(255, 255, 255);
  _vertex[2].color = sf::Color(255, 255, 255);
  _vertex[3].color = sf::Color(255, 255, 255);

  _vertex[0].texCoords = sf::Vector2f(0, 0);
  _vertex[1].texCoords = sf::Vector2f(0, 1);
  _vertex[2].texCoords = sf::Vector2f(1, 1);
  _vertex[3].texCoords = sf::Vector2f(1, 0);
}

AnimatedSprite::AnimatedSprite(AnimatedSprite const &other) :
  _animations(new std::map<std::string, Animation *>)
{
  for (auto it = other._animations->begin(); it != other._animations->end();it++) {
    if (it->second)
      (*_animations)[it->first] = new Animation(*it->second);
  }
  _isPlaying = other._isPlaying;
  _current = other._current;
  _count = other._count;
  _loopPlay = other._loopPlay;
  _old = other._old;
}

AnimatedSprite		&AnimatedSprite::operator=(AnimatedSprite const &other)
{
  if (this != &other)
    {
      if (_animations)
	delete _animations;
      _animations = new std::map<std::string, Animation *>;
      for (auto it = other._animations->begin(); it != other._animations->end();it++){
	if (it->second)
	  ((*_animations)[it->first]) = new Animation(*(it->second));
      }
      _isPlaying = other._isPlaying;
      _current = other._current;
      _loopPlay = other._loopPlay;
      _old = other._old;
    }
  return (*this);
}

AnimatedSprite::~AnimatedSprite()
{
  if (_animations)
    {
      for (auto it = _animations->begin();it != _animations->end();++it)
	if (it->second)
	  delete it->second;
      delete _animations;
    }
}

void			AnimatedSprite::addAnimation(std::string const &name, Animation *anim,
						     bool loopPlay)
{
  _loopPlay = loopPlay;
  if (anim)
    (*_animations)[name] = anim;
}

void			AnimatedSprite::play(std::string const &name)
{
  if (!(*_animations)[name])
    {
      std::cout << "Error : Animation [" << name << "] not found" << std::endl;
      return;
    }
  if (_isPlaying)
    {
      if ((*_animations)[_current] && (*_animations)[_current]->isEnded())
	{
	  _texture = (*_animations)[name]->getSpriteSheet();
	  _current = name;
	}
    }
  else
    {
      _isPlaying = true;
      _texture = (*_animations)[name]->getSpriteSheet();
      _current = name;
    }
}

void			AnimatedSprite::pause()
{
  _isPlaying = false;
}

void			AnimatedSprite::update(sf::Clock &clock)
{
  
  sf::IntRect *frame;
  
  if ((*_animations)[_current] && _isPlaying){
    // if (_old != "" && _current != _old)
    //   {
    // 	(*_animations)[_old]->reset();
    // 	(*_animations)[_current]->reset();
    //   }
    // if ((*_animations)[_current]->getFrameCount() == 1 ||
    // 	(*_animations)[_current]->getCurrentFrame() + 1 != (*_animations)[_current]->getFrameCount())
    //   {
    // 	(*_animations)[_current]->update(clock);
    //   }
    frame = (*_animations)[_current]->getFrame();
    _vertex[0].texCoords = sf::Vector2f(frame->left, frame->top);
    _vertex[1].texCoords = sf::Vector2f(frame->left, frame->top + frame->height);
    _vertex[2].texCoords = sf::Vector2f(frame->left + frame->width, frame->top + frame->height);
    _vertex[3].texCoords = sf::Vector2f(frame->left + frame->width, frame->top);
    _vertex[0].position = sf::Vector2f(0, 0);
    _vertex[1].position = sf::Vector2f(0, frame->height);
    _vertex[2].position = sf::Vector2f(frame->width, frame->height);
    _vertex[3].position = sf::Vector2f(frame->width, 0);
    // _old = _current;
  }
}

static void		err(std::string const &file)
{
  std::cout << "SpriteLoader : Malformated file : " << file << std::endl;
}

void			AnimatedSprite::loadFromFile(std::string const &file)
{
  std::ifstream	in(file.c_str());
  size_t	pos;
  size_t	epos;
  std::string	name;
  std::string	texture;
  Animation	*tmp;
  int		coord[4];
  int		size;
  
  std::string first;
  getline(in, first);

  if ((pos = first.find("[file")) == std::string::npos)
    return err(file);
  if ((epos = first.find("]", pos + 6)) == std::string::npos)
    return err(file);
  texture = first.substr(pos + 6, epos - (pos + 6));
  pos = texture.find(".");
  std::string textName = texture.substr(0, pos);
  SFRessourcesManager::getInstance()->Images->loadImage(texture, textName);
  getline(in, first);
  if ((pos = first.find("[size=")) == std::string::npos)
    return err(file);
  if ((epos = first.find("]", pos + 6)) == std::string::npos)
    return err(file);
  std::istringstream is(first.substr(pos + 6, epos - (pos + 6)));
  is >> size;
  for (std::string line; getline(in, line);)
    {
      if ((pos = line.find("[name=")) == std::string::npos)
	break;
      if ((epos = line.find("]", pos + 6)) == std::string::npos)
	break;
      name = line.substr(pos + 6, epos - (pos + 6));
      tmp = new Animation();
      tmp->setSpriteSheet((*(SFRessourcesManager::getInstance()->Images))[textName]);
      while (getline(in , line) && line != "[/]")
	{
	  std::istringstream iss(line);
	  iss >> coord[0] >> coord[1] >> coord[2] >> coord[3];
	  tmp->addFrame(sf::IntRect(coord[0], coord[1], coord[2], coord[3]));
	}
      addAnimation(name, tmp);
    }
  setScale(size,size);
}

void			AnimatedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if ((*_animations)[_current] && _texture)
    {
      states.texture = _texture;
      states.transform *= getTransform();
      target.draw(_vertex, 4, sf::Quads, states);
    }
}
