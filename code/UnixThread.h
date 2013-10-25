/***********************************************************************
 * Module:  UnixThread.h
 * Author:  ansel
 * Modified: lundi 21 octobre 2013 08:34:40
 * Purpose: Declaration of the class UnixThread
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_UnixThread_h)
#define __ClassDiagram_Server_UnixThread_h

#include <IThread.h>

class UnixThread : public IThread
{
public:
protected:
private:
   pthread_t _thread;


};

#endif