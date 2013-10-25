/***********************************************************************
 * Module:  WindowsSocket.h
 * Author:  ansel
 * Modified: lundi 21 octobre 2013 09:02:51
 * Purpose: Declaration of the class WindowsSocket
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_WindowsSocket_h)
#define __ClassDiagram_Server_WindowsSocket_h

#include <ISocket.h>

class WindowsSocket : public ISocket
{
public:
protected:
private:
   SOCKET _sock;


};

#endif