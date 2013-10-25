/***********************************************************************
 * Module:  AEntity.h
 * Author:  ansel
 * Modified: mercredi 23 octobre 2013 09:20:07
 * Purpose: Declaration of the class AEntity
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_AEntity_h)
#define __ClassDiagram_Server_AEntity_h

class enum_eObject;

class AEntity
{
public:
   bool checkCollision(AEntity& other);

   enum_eObject** enum_eObject;

protected:
private:
   int _x;
   int _y;
   std::string _path;
   int _speed;
   bool _destructible;


};

#endif