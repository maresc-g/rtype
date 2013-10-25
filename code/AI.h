/***********************************************************************
 * Module:  AI.h
 * Author:  ansel
 * Modified: mercredi 23 octobre 2013 07:54:03
 * Purpose: Declaration of the class AI
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_AI_h)
#define __ClassDiagram_Server_AI_h

#include <Action.h>

class AI
{
public:
   virtual Action * getActions(void)=0;

protected:
private:

};

#endif