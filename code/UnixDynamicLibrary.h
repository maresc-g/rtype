/***********************************************************************
 * Module:  UnixDynamicLibrary.h
 * Author:  ansel
 * Modified: mardi 22 octobre 2013 11:14:41
 * Purpose: Declaration of the class UnixDynamicLibrary
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_UnixDynamicLibrary_h)
#define __ClassDiagram_Server_UnixDynamicLibrary_h

#include <IDynamicLibrary.h>

class UnixDynamicLibrary : public IDynamicLibrary
{
public:
protected:
private:
   void * _lib;


};

#endif