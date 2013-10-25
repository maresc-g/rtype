/***********************************************************************
 * Module:  Command.h
 * Author:  ansel
 * Modified: mercredi 23 octobre 2013 08:17:18
 * Purpose: Declaration of the class Command
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_Command_h)
#define __ClassDiagram_Server_Command_h

class Action;

#include <Trame.h>

class Command
{
public:
   Action** action;

protected:
private:
   Trame * _trame;


};

#endif