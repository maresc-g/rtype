/***********************************************************************
 * Module:  Game.h
 * Author:  ansel
 * Modified: mardi 22 octobre 2013 08:54:34
 * Purpose: Declaration of the class Game
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_Game_h)
#define __ClassDiagram_Server_Game_h

class Player;
class LevelManager;

#include <IThread.h>

class Game : public IThread
{
public:
   void loop(void);
   void execCommand(Command * command);

   Player** player;
   LevelManager** levelManager;

protected:
private:

};

#endif