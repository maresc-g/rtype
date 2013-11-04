//
// Trame.hh for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:04:47 2013 laurent ansel
// Last update Sat Nov  2 16:30:21 2013 laurent ansel
//

#ifndef 			__TRAME_HH__
# define 			__TRAME_HH__

#include			"CircularBufferManager/CircularBuffer/Trame/Header/Header.hh"

#define	END_TRAME		"o0O°END°O0o"

class				Trame
{
private:
  Header			*_header;
  std::string			_content;
public:
  Trame(std::string &str);
  Trame(Header *header, std::string const &content, bool const setEndTrame = false);
  Trame(unsigned int const id, unsigned int const trameId, std::string const &proto, std::string const &content, bool const setEndTrame = false);
  virtual ~Trame();
  std::string const		&getContent() const;
  Header			&getHeader() const;
  void				setHeader(Header *header);
  void				setContent(std::string const &content);
  void				appendContent(std::string const &content);
  std::string const 		toString() const;
  bool				isSetEndTrame() const;
  static Trame			*toTrame(std::string &str);
  static std::list<Trame *>	*ToListTrame(unsigned int const id, unsigned int const trameId, std::string const &proto, std::string const &content);
};

#endif