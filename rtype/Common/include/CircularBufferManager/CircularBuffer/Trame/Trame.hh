//
// Trame.hh for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:04:47 2013 laurent ansel
// Last update Tue Nov 19 18:55:36 2013 laurent ansel
//

#ifndef 			__TRAME_HH__
# define 			__TRAME_HH__

#include			"Socket/ISocketClient.hh"
#include			"CircularBufferManager/CircularBuffer/Trame/Header/Header.hh"

#define	END_TRAME		"<TRAMEEND>"

struct				s_trame
{
  s_header			header;
  char				content[SIZE_BUFFER];
};

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
  static   std::list<Trame *>	*cutToListTrame(std::string const &str);
  static Trame			*toTrame(std::string const &str);
  static std::list<Trame *>	*ToListTrame(unsigned int const id, unsigned int const trameId, std::string const &proto, std::string const &content);
};

#endif
