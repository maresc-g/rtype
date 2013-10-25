/***********************************************************************
 * Module:  WindowsThread.h
 * Author:  ansel
 * Modified: lundi 21 octobre 2013 08:32:53
 * Purpose: Declaration of the class WindowsThread
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_WindowsThread_h)
#define __ClassDiagram_Server_WindowsThread_h

#include <IThread.h>

class WindowsThread : public IThread
{
public:
protected:
private:
   HANDLE _handle;


};

#endif