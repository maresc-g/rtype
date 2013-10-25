/***********************************************************************
 * Module:  HitBoxManager.h
 * Author:  ansel
 * Modified: mardi 22 octobre 2013 11:01:49
 * Purpose: Declaration of the class HitBoxManager
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_HitBoxManager_h)
#define __ClassDiagram_Server_HitBoxManager_h

class SpriteLoader;

#include <Singleton.h>

class HitBoxManager : public Singleton
{
public:
   SripteLoader * getHitBox(std::string const & path);

   SpriteLoader** spriteLoader;

protected:
private:
   std::map<std::string, SpriteLoader *> _sprite;


};

#endif