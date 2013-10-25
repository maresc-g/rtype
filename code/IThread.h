/***********************************************************************
 * Module:  IThread.h
 * Author:  ansel
 * Modified: mardi 22 octobre 2013 08:18:37
 * Purpose: Declaration of the class IThread
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_IThread_h)
#define __ClassDiagram_Server_IThread_h

class IThread
{
public:
   virtual int create(void)=0;
   virtual int start(void)=0;
   virtual void destroy(void)=0;
   virtual int wait(void)=0;

protected:
private:

};

#endif