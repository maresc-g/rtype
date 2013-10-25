/***********************************************************************
 * Module:  ISocket.h
 * Author:  ansel
 * Modified: lundi 21 octobre 2013 11:11:23
 * Purpose: Declaration of the class ISocket
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_ISocket_h)
#define __ClassDiagram_Server_ISocket_h

#include <ISocketClient.h>

class ISocket
{
public:
   virtual int _create(void)=0;
   virtual int destroy(void)=0;
   virtual int bind(void)=0;
   virtual int listen(void)=0;
   virtual int connect(void)=0;
   virtual ISocketClient accept(void)=0;

protected:
private:

};

#endif