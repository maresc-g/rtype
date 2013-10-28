//
// Header.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Fri Oct 25 11:29:13 2013 guillaume marescaux
// Last update Fri Oct 25 12:41:00 2013 guillaume marescaux
//

#ifndef 		__HEADER_HH__
# define 		__HEADER_HH__

class			Header
{
private:

  // Attributs
  int			_id;
  int			_trameId;

public:

  // Ctor / Dtor
  Header();
  Header(Header const &other);
  Header		&operator=(Header const &other);
  virtual ~Header();
};

#endif
