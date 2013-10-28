//
// Select.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Fri Oct 25 15:14:00 2013 guillaume marescaux
// Last update Fri Oct 25 15:58:53 2013 guillaume marescaux
//

#ifndef 		__SELECT_HH__
# define 		__SELECT_HH__

#include		<iostream>
#include		<sys/select.h>
#include		<map>

class			Select
{
public:

  enum			eSelect
    {
      READ,
      WRITE
    };

private:

  // Attributs
  std::map<eSelect, fd_set>	*_fdSets;
  int			_maxFd;
  struct timeval	*_timeout;

  // Private Ctor / Dtor
  Select(Select const &);
  Select		&operator=(Select const &);

public:

  // Ctor / Dtor
  Select();
  virtual ~Select();

  // Methods
  void			pushFd(int fd, eSelect type);
  void			clear(eSelect type);
  int			select();
  void			setTimeout(long sec, long usec);
  bool			isSet(int fd, eSelect type);
};

#endif
