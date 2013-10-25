/***********************************************************************
 * Module:  ClientInfo.h
 * Author:  ansel
 * Modified: mercredi 23 octobre 2013 08:54:48
 * Purpose: Declaration of the class ClientInfo
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_ClientInfo_h)
#define __ClassDiagram_Server_ClientInfo_h

class Trame;
class ISocketClient;
class Command;

#include <IMutex.h>
#include <Trame.h>

class ClientInfo : public IMutex
{
public:
   Command * getCommand(void);
   void pushCommand(Trame* command);

   Trame** trame;
   ISocketClient* iSocketClient;
   Command** command;

protected:
private:

};

#endif