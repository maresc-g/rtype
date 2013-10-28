//
// Select.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Fri Oct 25 15:21:08 2013 guillaume marescaux
// Last update Fri Oct 25 15:58:56 2013 guillaume marescaux
//

#include		"Server/Select.hh"

//------------------------------BEGIN CTOR / DTOR-----------------------------------

Select::Select():
  _fdSets(new std::map<eSelect, fd_set>), _maxFd(0), _timeout(NULL)
{
  _fdSets->insert(std::pair<eSelect, fd_set>(READ, fd_set()));
  // FD_ZERO(&_fdRead);
  // FD_ZERO(&_fdWrite);
}

Select::~Select()
{
  delete _fdSets;
  if (_timeout)
    delete _timeout;
}

//------------------------------END CTOR / DTOR-----------------------------------

//-------------------------------BEGIN METHODS------------------------------------

void			Select::pushFd(int fd, eSelect type)
{
  if (fd > _maxFd)
    _maxFd = fd;
  FD_SET(fd, &(*_fdSets)[type]);
}

void			Select::clear(eSelect type)
{
  FD_ZERO(&(*_fdSets)[type]);
}

int			Select::select()
{
  // return (select(_maxFd, &(*_fdSets)[READ], &(*_fdSets)[WRITE], NULL, _timeout));
}

void			Select::setTimeout(long sec, long usec)
{
  if (_timeout)
    delete _timeout;
  _timeout = new struct timeval;
  _timeout->tv_sec = sec;
  _timeout->tv_usec = usec;
}

bool			Select::isSet(int fd, eSelect type)
{
  return (FD_ISSET(fd, &(*_fdSets)[type]) == 0 ? true : false);
}

//--------------------------------END METHODS-------------------------------------
