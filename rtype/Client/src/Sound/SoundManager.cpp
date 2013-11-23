//
// SoundManager.cpp for  in /home/jourda_c/Documents/C++/Rtype_test/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Sat Nov 23 20:11:19 2013 cyril jourdain
// Last update Sat Nov 23 22:24:47 2013 cyril jourdain
//

#include		"Sound/SoundManager.hh"

SoundManager::SoundManager() :
  _sounds(new std::map<std::string, sf::SoundBuffer *>),
  _musics(new std::map<std::string, sf::Music *>)
{
}

SoundManager::~SoundManager()
{
  for (auto it = _sounds->begin(); it != _sounds->end(); it++)
    {
      delete it->second;
      _sounds->erase(it);
    }
  for (auto it = _musics->begin(); it != _musics->end(); it++)
    {
      it->second->stop();
      delete it->second;
      _musics->erase(it);
    }
}

void			SoundManager::addSound(std::string const &name, std::string const &path)
{
  (*_sounds)[name] = new sf::SoundBuffer();
  (*_sounds)[name]->loadFromFile(path);
}

void			SoundManager::addMusic(std::string const &name, std::string const &path)
{
  (*_musics)[name] = new sf::Music();
  (*_musics)[name]->openFromFile(path);
}

void			SoundManager::playSound(std::string const &name)
{
  sf::Sound		sound;

  if ((*_sounds)[name])
    {
      _sound.setBuffer(*(*_sounds)[name]);
      _sound.play();
    }
}

void			SoundManager::playMusic(std::string const &name)
{
  if ((*_musics)[name])
    (*_musics)[name]->play();
}

void			SoundManager::pauseMusic(std::string const &name)
{
  if ((*_musics)[name])
    (*_musics)[name]->play();
}

void			SoundManager::stopMusic(std::string const &name)
{
  if ((*_musics)[name])
    (*_musics)[name]->stop();
}

void			SoundManager::loadDefaultSounds()
{
  addSound("shot", "Res/Sounds/shot.ogg");
  addMusic("background", "Res/Sounds/background.ogg");
}
