/***********************************************************************
 * Module:  UnixSocketClient.h
 * Author:  ansel
 * Modified: lundi 21 octobre 2013 11:40:04
 * Purpose: Declaration of the class UnixSocketClient
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_UnixSocketClient_h)
#define __ClassDiagram_Server_UnixSocketClient_h

#include <ISocketClient.h>

class UnixSocketClient : public ISocketClient
{
public:
protected:
private:
   int _fd;


};

#endif