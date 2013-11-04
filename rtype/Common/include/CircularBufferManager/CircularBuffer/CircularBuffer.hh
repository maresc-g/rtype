//
// CircularBuffer.hh for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 00:02:38 2013 laurent ansel
// Last update Fri Nov  1 14:40:06 2013 laurent ansel
//

#ifndef 			__CIRCULARBUFFER_HH__
# define 			__CIRCULARBUFFER_HH__

#include			<list>
#include			"CircularBufferManager/CircularBuffer/Trame/Trame.hh"

class				CircularBuffer
{
private:
  std::list<Trame *>		*_buffer;
public:
  CircularBuffer();
  virtual ~CircularBuffer();
  void				pushTrame(Trame *trame);
  Trame const			&getFirstTrame() const;
  Trame				*popFirstTrame();
  Trame				*popFirstTrame(unsigned int const id , std::string const &proto);
  void				deleteTrame(unsigned int const id);
};

#endif
