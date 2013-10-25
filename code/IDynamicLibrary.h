/***********************************************************************
 * Module:  IDynamicLibrary.h
 * Author:  ansel
 * Modified: mardi 22 octobre 2013 11:17:08
 * Purpose: Declaration of the class IDynamicLibrary
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_IDynamicLibrary_h)
#define __ClassDiagram_Server_IDynamicLibrary_h

class IDynamicLibrary
{
public:
   virtual bool load(void)=0;
   virtual void destroy(void)=0;
   virtual void * getObject(void)=0;

protected:
private:

};

#endif