/***********************************************************************
 * Module:  Level.h
 * Author:  ansel
 * Modified: lundi 21 octobre 2013 08:42:03
 * Purpose: Declaration of the class Level
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_Level_h)
#define __ClassDiagram_Server_Level_h

class AEntity;
class Map;

class Level
{
public:
   AEntity** aEntity;
   Map** map;

protected:
private:

};

#endif