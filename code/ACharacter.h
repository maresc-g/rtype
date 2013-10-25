/***********************************************************************
 * Module:  ACharacter.h
 * Author:  ansel
 * Modified: mercredi 23 octobre 2013 08:57:48
 * Purpose: Declaration of the class ACharacter
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_ACharacter_h)
#define __ClassDiagram_Server_ACharacter_h

class Weapon;

#include <AEntity.h>

class ACharacter : public AEntity
{
public:
   Weapon** weapon;

protected:
private:
   int _life;


};

#endif