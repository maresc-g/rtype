//
// Select.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 21:10:15 2013 laurent ansel
// Last update Thu Oct 31 13:48:01 2013 laurent ansel
//

#include			"Select/Select.hh"

Select::Select():
  _fd(new std::map<Select::eSelect, fd_set>),
  _fdMax(0),
  _timeout(new struct timeval)
{

}

Select::~Select()
{
  if (this->_fd)
    delete this->_fd;
  if (this->_timeout)
    delete this->_timeout;
}

void				Select::pushFd(int const fd, enum Select::eSelect const type)
{
  if (fd > this->_fdMax)
    this->_fdMax = fd;
  FD_SET(fd, &(*this->_fd)[type]);
}

void				Select::clear()
{
  this->_fdMax = 0;
  FD_ZERO(&(*this->_fd)[READ]);
  FD_ZERO(&(*this->_fd)[WRITE]);
}

void				Select::setTimeout(long const second, long const microsecond)
{
  this->_timeout->tv_sec = second;
  this->_timeout->tv_usec = microsecond;
}

bool				Select::isSet(int const fd, enum Select::eSelect const type)
{
  if (FD_ISSET(fd, &(*this->_fd)[type]))
    return (true);
  return (false);
}

int				Select::runSelect(bool const setTimeout) const
{
  int				ret;

  if (setTimeout)
    ret = select(this->_fdMax + 1, &(*this->_fd)[READ], &(*this->_fd)[WRITE], NULL, this->_timeout);
  else
    ret = select(this->_fdMax + 1, &(*this->_fd)[READ], &(*this->_fd)[WRITE], NULL, NULL);
  return (ret);
}
