//
// AError.hpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Wed Oct 30 15:37:54 2013 laurent ansel
// Last update Wed Oct 30 15:50:24 2013 laurent ansel
//

#ifndef			__SOCKETERROR_HPP__
# define		__SOCKETERROR_HPP__

#include		"Error/IError.hh"

class			SocketError : public IError
{
private:
  std::string		_msg;
public:
  SocketError(std::string const &msg):
    _msg(msg)
  {
  }
  virtual ~SocketError() throw(){}
  virtual char const	*what() const throw()
  {
    std::ostringstream	str;

    str << "Error Socket : " << _msg << std::endl;
    return (str.str().c_str());
  }
};

#endif
