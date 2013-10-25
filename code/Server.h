/***********************************************************************
 * Module:  Server.h
 * Author:  ansel
 * Modified: mercredi 23 octobre 2013 08:32:20
 * Purpose: Declaration of the class Server
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_Server_h)
#define __ClassDiagram_Server_Server_h

class ClientInfo;
class ISocket;
class Game;
class Select;

class Server
{
public:
   void run(void);

   ClientInfo** clientInfo;
   ISocket** iSocket;
   Game** game;
   Select** select;

protected:
private:

};

#endif