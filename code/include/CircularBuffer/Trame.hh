//
// Trame.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Fri Oct 25 11:29:41 2013 guillaume marescaux
// Last update Fri Oct 25 12:55:56 2013 guillaume marescaux
//

#ifndef 		__TRAME_HH__
# define 		__TRAME_HH__

#include		<string>
#include		"Header.hh"

class			Trame
{
private:

  // Attributs
  Header		*_header;
  std::string		_content;

public:

  // Ctor / Dtor
  Trame(std::string const &content = "");
  Trame(Trame const &other);
  Trame			&operator=(Trame const &other);
  virtual ~Trame();
};

#endif
