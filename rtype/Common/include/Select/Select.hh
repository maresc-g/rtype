//
// Select.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 21:02:23 2013 laurent ansel
// Last update Mon Oct 28 21:34:50 2013 laurent ansel
//

#ifndef 			__SELECT_HH__
# define 			__SELECT_HH__

#include			<map>
#include			<sys/select.h>
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
  void				pushFd(int const, enum Select::eSelect const);
  void				clear();
  void				setTimeout(long const, long const);
  bool				isSet(int const, enum Select::eSelect const);
  int				runSelect(bool const) const;
};

#endif
