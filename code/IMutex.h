/***********************************************************************
 * Module:  IMutex.h
 * Author:  ansel
 * Modified: lundi 21 octobre 2013 08:57:54
 * Purpose: Declaration of the class IMutex
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_IMutex_h)
#define __ClassDiagram_Server_IMutex_h

class IMutex
{
public:
   virtual void initialize(void)=0;
   virtual void destroy(void)=0;
   virtual void enter(void)=0;
   virtual void tryEnter(void)=0;
   virtual void leave(void)=0;

protected:
private:

};

#endif