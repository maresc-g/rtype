//
// Select.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 21:02:23 2013 laurent ansel
// Last update Thu Oct 31 10:38:15 2013 laurent ansel
//

#ifndef 			__SELECT_HH__
# define 			__SELECT_HH__

#include			<map>
#ifndef _WIN32
#include			<sys/select.h>
#else
#include			<Windows.h>
#endif
#include			<stdlib.h>

class				Select
{
public:
  enum				eSelect
    {
      READ,
      WRITE
    };
private:
  std::map<Select::eSelect, fd_set>	*_fd;
  int				_fdMax;
  struct timeval		*_timeout;
public:
  Select();
  virtual ~Select();
  void				pushFd(int const fd, enum Select::eSelect const type);
  void				clear();
  void				setTimeout(long const second, long const microsecond);
  bool				isSet(int const fd, enum Select::eSelect const type);
  int				runSelect(bool const set) const;
};

#endif
