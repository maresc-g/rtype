/***********************************************************************
 * Module:  ISocketClient.h
 * Author:  ansel
 * Modified: mercredi 23 octobre 2013 08:54:48
 * Purpose: Declaration of the class ISocketClient
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_ISocketClient_h)
#define __ClassDiagram_Server_ISocketClient_h

class ISocketClient
{
public:
   virtual int read(void)=0;
   virtual int write(void)=0;
   virtual void close(void)=0;

protected:
private:

};

#endif