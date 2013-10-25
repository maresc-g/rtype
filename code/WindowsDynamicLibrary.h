/***********************************************************************
 * Module:  WindowsDynamicLibrary.h
 * Author:  ansel
 * Modified: mardi 22 octobre 2013 11:13:38
 * Purpose: Declaration of the class WindowsDynamicLibrary
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_WindowsDynamicLibrary_h)
#define __ClassDiagram_Server_WindowsDynamicLibrary_h

#include <IDynamicLibrary.h>

class WindowsDynamicLibrary : public IDynamicLibrary
{
public:
protected:
private:
   HMODULE _lib;


};

#endif