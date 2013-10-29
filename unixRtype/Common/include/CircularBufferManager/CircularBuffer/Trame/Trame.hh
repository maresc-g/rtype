//
// Trame.hh for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:04:47 2013 laurent ansel
// Last update Tue Oct 29 14:32:26 2013 laurent ansel
//

#ifndef 			__TRAME_HH__
# define 			__TRAME_HH__

#include			"CircularBufferManager/CircularBuffer/Trame/Header/Header.hh"

class				Trame
{
private:
  Header			*_header;
  std::string			_content;
public:
  Trame(Header *header, std::string const &content);
  Trame(int const id, int const trameId, std::string const &content);
  virtual ~Trame();
  std::string const		&getContent() const;
  Header const			&getHeader() const;
  void				setHeader(Header *header);
  void				setContent(std::string const &content);
  void				appendContent(std::string const &content);
};

#endif
