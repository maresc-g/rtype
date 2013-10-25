/***********************************************************************
 * Module:  Player.h
 * Author:  ansel
 * Modified: lundi 21 octobre 2013 10:50:41
 * Purpose: Declaration of the class Player
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_Player_h)
#define __ClassDiagram_Server_Player_h

class ClientInfo;

#include <ACharacter.h>

class Player : public ACharacter
{
public:
   ClientInfo** clientInfo;

protected:
private:

};

#endif