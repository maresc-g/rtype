/***********************************************************************
 * Module:  CircularBuffer.h
 * Author:  ansel
 * Modified: mardi 22 octobre 2013 08:03:34
 * Purpose: Declaration of the class CircularBuffer
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_CircularBuffer_h)
#define __ClassDiagram_Server_CircularBuffer_h

class Trame;

#include <IMutex.h>
#include <Trame.h>

class CircularBuffer : public IMutex
{
public:
   Trame * const getFirstTrame(void);
   Trame * popFirstTrame(void);

   Trame** trame;

protected:
private:

};

#endif