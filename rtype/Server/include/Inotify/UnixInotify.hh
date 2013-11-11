//
// UnixNotify.hh for  in /home/ansel_l/testInotify/include/Inotify
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Sat Nov  9 12:52:24 2013 laurent ansel
// Last update Sun Nov 10 21:03:20 2013 laurent ansel
//

#ifndef 			__UNIXINOTIFY_HH__
# define 			__UNIXINOTIFY_HH__

#include			<map>
#include			"Inotify/IInotify.hh"

#ifndef	_WIN32

class				UnixInotify : public IInotify
{
private:
  std::map<std::string, std::pair<enum IInotify::eInotify, std::string> >	*_event;
  std::map<std::string, int>	*_fd;
  int				_notify;
public:
  UnixInotify();
  virtual ~UnixInotify();
  virtual bool			initInotify();
  virtual bool			waitEvent(std::string const &path);
  virtual std::pair<enum IInotify::eInotify, std::string> const	getEvent(std::string const &path) const;
  virtual bool			addWatch(std::string const &path, enum IInotify::eInotify const event);
  virtual void			destroyInotify();
  virtual void			rmWatch(std::string const &path);
};

#endif

#endif
