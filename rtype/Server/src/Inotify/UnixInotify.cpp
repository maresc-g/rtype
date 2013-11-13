//
// UnixNotify.cpp for  in /home/ansel_l/testInotify/include/Inotify
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Sat Nov  9 12:55:19 2013 laurent ansel
// Last update Wed Nov 13 14:49:04 2013 alexis mestag
//

#ifndef	_WIN32
#include			<limits.h>
#include			<utility>
#include			<unistd.h>
#include			<sys/inotify.h>
#include			"Inotify/UnixInotify.hh"

UnixInotify::UnixInotify():
  _event(new std::map<std::string, std::pair<enum IInotify::eInotify, std::string> >),
  _fd(new std::map<std::string, int>),
  _notify(-1)
{

}

UnixInotify::~UnixInotify()
{
  delete _event;
  delete _fd;
}

bool			UnixInotify::initInotify()
{
  if ((_notify = inotify_init()) > -1)
    return (true);
  return (false);
}

bool			UnixInotify::waitEvent(std::string const &path)
{
  static std::map<int, enum IInotify::eInotify> tab =
    {
      {IN_CREATE, IInotify::ADD},
      {IN_MODIFY, IInotify::MODIFY},
      {IN_DELETE, IInotify::DELETEFILE},
      {IN_DELETE_SELF, IInotify::DELETEFILE},
      {IN_MOVE_SELF, IInotify::MOVE},
      {IN_MOVED_FROM, IInotify::MOVE},
      {IN_MOVED_TO, IInotify::MOVE}
    };
  int				len;
  // char			buffer[1024 + (sizeof(struct inotify_event) + 16)];
  char				buffer[sizeof(struct inotify_event) + NAME_MAX];
  struct inotify_event		*event = NULL;
  enum IInotify::eInotify	ret = NOTHING;

  if (this->_fd->find(path) != this->_fd->end())
    {
      // len = read(this->_notify, buffer, 1024 + (sizeof(struct inotify_event) + 16));
      len = read(this->_notify, buffer, sizeof(buffer));
      // for (int i = 0 ; i < len ; i+= sizeof(struct inotify_event))
      if (len != -1)
	{
	  event = reinterpret_cast<struct inotify_event *>(buffer);
	  if (event->len)
	    {
	      for (auto it = tab.begin() ; it != tab.end() && ret == NOTHING ; ++it)
		if ((event->mask & it->first))
		  ret = it->second;
	    }
	}
      if (event && !(event->mask & IN_IGNORED))
	(*this->_event)[path] = std::make_pair(ret, std::string(event->name));
      return (true);
    }
  return (false);
}

std::pair<enum IInotify::eInotify, std::string> const	UnixInotify::getEvent(std::string const &path) const
{
  if (this->_event->find(path) != this->_event->end())
    return ((*this->_event)[path]);
  return (std::make_pair(IInotify::NOTHING, path));
}

bool			UnixInotify::addWatch(std::string const &path, enum IInotify::eInotify const event)
{
  int			fd;

  if ((fd = inotify_add_watch(this->_notify, path.c_str(), event)) > -1)
    {
      (*this->_fd)[path] = fd;
      return (true);
    }
  return (false);
}

void			UnixInotify::destroyInotify()
{
  if (this->_notify > -1)
    {
      for (auto it = this->_fd->begin() ; it != this->_fd->end() ; ++it)
	close(it->second);
      close(this->_notify);
    }
}

void			UnixInotify::rmWatch(std::string const &path)
{
  std::map<std::string, int>::iterator it;

  if (this->_notify > -1)
    {
      if ((it = this->_fd->find(path)) != this->_fd->end())
	{
	  inotify_rm_watch(this->_notify, it->second);
	  it = this->_fd->erase(it);
	}
    }
}

#endif
