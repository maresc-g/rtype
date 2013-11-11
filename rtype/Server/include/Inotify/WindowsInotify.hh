//
// WindowsInotify.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Sun Nov 10 20:25:59 2013 laurent ansel
// Last update Sun Nov 10 21:03:26 2013 laurent ansel
//

#ifndef 			__WINDOWSINOTIFY_HH__
# define 			__WINDOWSINOTIFY_HH__

#ifdef _WIN32

#include			<map>
#include			<Windows.h>
#include			"Inotify/IInotify.hh"

class				WindowsInotify : public IInotify
{
private:
  std::map<std::string, std::pair<enum IInotify::eInotify, std::string> >	*_event;
  std::map<std::string, std::pair<HANDLE, enum IInotify::eInotify> >	*_fd;
  std::map<int, enum IInotify::eInotify>	*_tab;
public:
  WindowsInotify();
  virtual ~WindowsInotify();
  virtual bool			initInotify();
  virtual bool			waitEvent(std::string const &path);
  virtual std::pair<enum IInotify::eInotify, std::string> const	getEvent(std::string const &path) const;
  virtual bool			addWatch(std::string const &path, enum IInotify::eInotify const event);
  virtual void			destroyInotify();
  virtual void			rmWatch(std::string const &path);
};

#endif

#endif
