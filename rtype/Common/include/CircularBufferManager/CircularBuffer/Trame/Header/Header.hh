//
// Header.hh for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:07:45 2013 laurent ansel
// Last update Thu Oct 31 13:14:30 2013 laurent ansel
//

#ifndef 			__HEADER_HH__
# define 			__HEADER_HH__

#include			<iostream>
#include			<string>

class				Header
{
private:
  int				_id;
  int				_trameId;
  std::string			_proto;
public:
  Header(int const id, int const trameId, std::string const &proto);
  virtual ~Header();
  int				getId() const;
  int				getTrameId() const;
  std::string const		&getProto() const;
  void				setId(int const id);
  void				setTrameId(int const trameId);
  void				setProto(std::string const &proto);
  std::string const		toString() const;
  static Header			*toHeader(std::string &str);
};

#endif
