/***********************************************************************
 * Module:  WindowsSocketClient.h
 * Author:  ansel
 * Modified: lundi 21 octobre 2013 11:39:56
 * Purpose: Declaration of the class WindowsSocketClient
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_WindowsSocketClient_h)
#define __ClassDiagram_Server_WindowsSocketClient_h

#include <ISocketClient.h>

class WindowsSocketClient : public ISocketClient
{
public:
protected:
private:
   SOCKET _sock;


};

#endif