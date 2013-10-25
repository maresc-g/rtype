/***********************************************************************
 * Module:  ObjectPoolManager.h
 * Author:  ansel
 * Modified: mardi 22 octobre 2013 08:47:30
 * Purpose: Declaration of the class ObjectPoolManager
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_ObjectPoolManager_h)
#define __ClassDiagram_Server_ObjectPoolManager_h

class IMutex;

#include <IThread.h>
#include <Singleton.h>

class ObjectPoolManager : public Singleton, public IThread
{
public:
   void push(std::list<AEntity *> object);
   std::list<AEntity *> pop(void);
   void create(void);

   IMutex** iMutex;

protected:
private:
   std::map<enum eObject, std::list<AEntity *>> _pool;


};

#endif