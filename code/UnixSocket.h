/***********************************************************************
 * Module:  UnixSocket.h
 * Author:  ansel
 * Modified: lundi 21 octobre 2013 08:32:00
 * Purpose: Declaration of the class UnixSocket
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_UnixSocket_h)
#define __ClassDiagram_Server_UnixSocket_h

#include <ISocket.h>

class UnixSocket : public ISocket
{
public:
protected:
private:
   int _fd;


};

#endif