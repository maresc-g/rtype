/***********************************************************************
 * Module:  Weapon.h
 * Author:  ansel
 * Modified: mercredi 23 octobre 2013 09:10:12
 * Purpose: Declaration of the class Weapon
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_Weapon_h)
#define __ClassDiagram_Server_Weapon_h

class AProjectile;

#include <AEntity.h>

class Weapon : public AEntity
{
public:
   AProjectile** aProjectile;

protected:
private:

};

#endif