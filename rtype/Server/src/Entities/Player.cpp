//
// Player.cpp for Player in /home/maitre_c/work/rtype/rtype
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Nov  5 10:38:05 2013 antoine maitre
// Last update Sat Nov 23 22:17:26 2013 antoine maitre
//

#include "Entities/Player.hh"

Player::Player(int const x, int const y, std::string const &path, int const speed, bool const destructible)
  : ACharacter(x, y, path, speed, destructible),
    _score(0),
    _numPlayer(0),
    _lostLife(false)
{
  this->_weapon.setWeapon(AProjectile::ROCKET);
}

Player::~Player()
{

}

AEntity::eObject		Player::getType() const
{
  return (PLAYER);
}

void				Player::setNum(int const num)
{
  this->_numPlayer = num;
}

int				Player::getNum() const
{
  return (this->_numPlayer);
}

void				Player::collision()
{
  if (this->_timeInvincible == 0)
    {
      this->_life--;
      this->_timeInvincible = 50;
      if (this->_life <= 0 && this->_destructible == true)
	this->_dead = true;
      else if (this->_destructible == true)
	this->_lostLife = true;
    }
}

int				Player::getScore() const
{
  return (this->_score);
}

void				Player::setScore(int score)
{
  this->_score = score;
}

bool				Player::lostLife()
{
  if (_lostLife)
    {
      _lostLife = false;
      return (true);
    }
  return (false);
}
