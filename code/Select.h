/***********************************************************************
 * Module:  Select.h
 * Author:  ansel
 * Modified: mercredi 23 octobre 2013 08:40:20
 * Purpose: Declaration of the class Select
 ***********************************************************************/

#if !defined(__ClassDiagram_Server_Select_h)
#define __ClassDiagram_Server_Select_h

class enum_eSelect;

class Select
{
public:
   void pushFd(int fd, enum eSelect type);
   void clear(void);
   int select(void);
   void setTimeout(long second, long millisecond);
   bool isSet(int fd, enum eSelect type);

   enum_eSelect** enum_eSelect;

protected:
private:
   fd_set _fdRead;
   fd_set _fdWrite;
   int _maxFd;
   struct timeval * _timeout;


};

#endif