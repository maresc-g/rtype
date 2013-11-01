//
// Header.hh for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:07:45 2013 laurent ansel
// Last update Thu Oct 31 15:19:51 2013 laurent ansel
//

#ifndef 			__HEADER_HH__
# define 			__HEADER_HH__

#include			<iostream>
#include			<string>

class				Header
{
private:
  unsigned int			_id;
  unsigned int			_trameId;
  std::string			_proto;
public:
  Header(unsigned int const id, unsigned int const trameId, std::string const &proto);
  virtual ~Header();
  unsigned int			getId() const;
  unsigned int			getTrameId() const;
  std::string const		&getProto() const;
  void				setId(unsigned int const id);
  void				setTrameId(unsigned int const trameId);
  void				setProto(std::string const &proto);
  std::string const		toString() const;
  static Header			*toHeader(std::string &str);
};

#endif
