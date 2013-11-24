//
// Animation.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Mon Nov 18 13:40:35 2013 cyril jourdain

//

#include		"Graphic/Graphics/Sprites/Animation.hh"
#include		<iostream>

Animation::Animation() :
  _texture(NULL), _spriteList(new std::vector<sf::IntRect *>),
  _frameCount(0), _frameLength(500000), _currentFrame(0), _count(0),
  _inClock(new sf::Clock)
{
  _inClock->restart();
}

Animation::Animation(Animation const &other) :
  _texture(other._texture), _spriteList(new std::vector<sf::IntRect *>),
  _frameCount(other._frameCount), _frameLength(other._frameLength), _count(other._count)
{
  if (this != &other)
    {
      for (auto it = other._spriteList->begin(); it != other._spriteList->end();it++)
	_spriteList->push_back(new sf::IntRect(*(*it)));
    }
}

Animation		&Animation::operator=(Animation const &other)
{
  if (this != &other)
    {
      _texture = other._texture;
      if (!_spriteList)
	_spriteList = new std::vector<sf::IntRect *>;
      for (auto it = other._spriteList->begin(); it != other._spriteList->end();it++)
	_spriteList->push_back(new sf::IntRect(*(*it)));
      _frameCount = other._frameCount;
      _frameLength = other._frameLength;
      _count = other._count;
    }
  return (*this);
}

Animation::~Animation()
{
  if (_texture)
    delete _texture;
  if (_spriteList)
    delete _spriteList;
}

/* Methods  */

void			Animation::setSpriteSheetFromPath(std::string const &path)
{
  _texture->loadFromFile(path);
}

void			Animation::setSpriteSheet(sf::Texture *texture)
{
  _texture = texture;
}

void			Animation::addFrame(sf::IntRect const &rect)
{
  _spriteList->push_back(new sf::IntRect(rect));
  _frameCount++;
}

void			Animation::setFrameLenght(unsigned int lenght)
{
  _frameLength = lenght;
}

void			Animation::reset()
{
  _currentFrame = 0;
}

void			Animation::update(sf::Clock &)
{
  unsigned int		time;

  time = _inClock->getElapsedTime().asMicroseconds();
  if (time >= _frameLength)
    {
      if (_currentFrame + 1 != _frameCount)
	_currentFrame++;
      _inClock->restart();
    } 
}

bool			Animation::isEnded() const
{
  if (_currentFrame + 1 == _frameCount)
    return true;
  return false;
}

sf::IntRect		*Animation::getFrame() const
{
  if (_frameCount > 0)
    return ((*_spriteList)[_currentFrame]);
  return (NULL);
}

sf::Texture		*Animation::getSpriteSheet() const
{
  return (_texture);
}

unsigned int		Animation::getFrameLenght() const
{
  return (_frameLength);
}

unsigned int		Animation::getFrameCount() const
{
  return (_frameCount);
}

unsigned int		Animation::getCurrentFrame() const
{
  return (_currentFrame);
}
