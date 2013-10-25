/***********************************************************************
 * Module:  WindowsMutex.h
 * Author:  ansel
 * Modified: lundi 21 octobre 2013 08:35:04
 * Purpose: Declaration of the class WindowsMutex
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_WindowsMutex_h)
#define __ClassDiagram_Server_WindowsMutex_h

#include <IMutex.h>

class WindowsMutex : public IMutex
{
public:
protected:
private:
   CRITICAL_SECTION _mutex;


};

#endif