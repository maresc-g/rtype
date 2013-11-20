//
// Donkey.cpp for Donkey in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype/Libraries
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Mon Nov 18 10:34:21 2013 alexis mestag
// Last update Wed Nov 20 15:27:14 2013 alexis mestag
//

#include			"AI/Donkey.hh"

Donkey::Donkey() :
  Mob(0, 0, "Res/Sprites/Player.gif", 2)
{
  
}

Donkey::~Donkey()
{

}

Action const			*Donkey::getAction() const
{
  _action->reset();
  _action->setLeft(true);
  return (_action);
}
