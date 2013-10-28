//
// CircularBuffer.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Fri Oct 25 11:28:23 2013 guillaume marescaux
// Last update Fri Oct 25 13:42:28 2013 guillaume marescaux
//

#ifndef 		__CIRCULARBUFFER_HH__
# define 		__CIRCULARBUFFER_HH__

#include		<list>
#include		"Trame.hh"

class			CircularBuffer
{
private:

  // Attributs
  std::list<Trame *>	*_trames;

public:

  // Ctor / Dtor
  CircularBuffer();
  CircularBuffer(CircularBuffer const &other);
  CircularBuffer	&operator=(CircularBuffer const &other);
  virtual ~CircularBuffer();

  // Methods
  Trame const		*getFirstTrame() const;
  Trame			*popFirstTrame();
  void			pushTrame(Trame *trame);
};

#endif
