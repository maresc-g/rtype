//
// IInotify.hh for  in /home/ansel_l/testInotify/include/Inotify
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Sat Nov  9 12:46:32 2013 laurent ansel
// Last update Tue Nov 12 09:16:07 2013 laurent ansel
//

#ifndef 			__IINOTIFY_HH__
# define 			__IINOTIFY_HH__

#include			<iostream>
#include			<string>
#ifndef	_WIN32
#include			<sys/inotify.h>
#else
#include			<Windows.h>
#endif

class				IInotify
{
public:
  enum				eInotify
    {
#ifndef	_WIN32
      ADD = IN_CREATE,
      MODIFY = IN_MODIFY,
      DELETEFILE = IN_DELETE | IN_DELETE_SELF,
      MOVE = IN_MOVE_SELF | IN_MOVED_FROM | IN_MOVED_TO,
      ALL_EVENT = ADD | MODIFY | DELETEFILE | MOVE,
      NOTHING = -1
#else
      ADD = FILE_ACTION_ADDED,
      MODIFY = FILE_ACTION_MODIFIED | FILE_NOTIFY_CHANGE_LAST_WRITE | FILE_NOTIFY_CHANGE_SIZE,
      DELETEFILE = FILE_ACTION_REMOVED,
      MOVE = FILE_NOTIFY_CHANGE_CREATION,
      ALL_EVENT = ADD | MODIFY | DELETEFILE | MOVE,
      NOTHING = -1
#endif
    };

public:
  virtual ~IInotify(){}
  virtual bool			initInotify() = 0;
  virtual bool			waitEvent(std::string const &path) = 0;
  virtual std::pair<enum IInotify::eInotify, std::string> const	getEvent(std::string const &path) const = 0;
  virtual bool			addWatch(std::string const &path, enum IInotify::eInotify const event) = 0;
  virtual void			destroyInotify() = 0;
  virtual void			rmWatch(std::string const &path) = 0;
};

#endif
