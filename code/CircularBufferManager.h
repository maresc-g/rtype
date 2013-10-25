/***********************************************************************
 * Module:  CircularBufferManager.h
 * Author:  ansel
 * Modified: mardi 22 octobre 2013 08:05:21
 * Purpose: Declaration of the class CircularBufferManager
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_CircularBufferManager_h)
#define __ClassDiagram_Server_CircularBufferManager_h

class CircularBuffer;
class enum_eTypeBuffer;

#include <Singleton.h>
#include <Trame.h>

class CircularBufferManager : public Singleton
{
public:
   void pushTrame(Trameconst & trame, enum eTypeBuffer buffer);
   Trame getTrame(enum eTypeBuffer buffer);

   CircularBuffer* circularBuffer[2];
   enum_eTypeBuffer** enum_eTypeBuffer;

protected:
private:

};

#endif