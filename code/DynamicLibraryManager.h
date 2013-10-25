/***********************************************************************
 * Module:  DynamicLibraryManager.h
 * Author:  ansel
 * Modified: mercredi 23 octobre 2013 09:24:06
 * Purpose: Declaration of the class DynamicLibraryManager
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_DynamicLibraryManager_h)
#define __ClassDiagram_Server_DynamicLibraryManager_h

class IDynamicLibrary;

#include <IThread.h>
#include <Singleton.h>
#include <GameDynamicLibraryManager.h>

class DynamicLibraryManager : public Singleton, public IThread
{
public:
   GameDynamicLibraryManager * getLibraries(void);

   IDynamicLibrary** iDynamicLibrary;

protected:
private:
   std::string _path;


};

#endif