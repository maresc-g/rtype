//
// Header.hh for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:07:45 2013 laurent ansel
// Last update Tue Oct 29 14:32:51 2013 laurent ansel
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
public:
  Header(int const id, int const trameId);
  virtual ~Header();
  int				getId() const;
  int				getTrameId() const;
  void				setId(int const id);
  void				setTrameId(int const trameId);
};

#endif
