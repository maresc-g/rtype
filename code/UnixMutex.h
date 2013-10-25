/***********************************************************************
 * Module:  UnixMutex.h
 * Author:  ansel
 * Modified: lundi 21 octobre 2013 08:35:43
 * Purpose: Declaration of the class UnixMutex
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_UnixMutex_h)
#define __ClassDiagram_Server_UnixMutex_h

#include <IMutex.h>

class UnixMutex : public IMutex
{
public:
protected:
private:
   mutex_t _mutex;


};

#endif