/***********************************************************************
 * Module:  Trame.h
 * Author:  ansel
 * Modified: mercredi 23 octobre 2013 08:17:18
 * Purpose: Declaration of the class Trame
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_Trame_h)
#define __ClassDiagram_Server_Trame_h

class Header;

class Trame
{
public:
   Header** header;

protected:
private:
   std::string _content;


};

#endif