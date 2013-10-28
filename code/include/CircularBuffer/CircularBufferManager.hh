//
// CircularBufferManager.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Fri Oct 25 11:08:36 2013 guillaume marescaux
// Last update Fri Oct 25 13:46:30 2013 guillaume marescaux
//

#ifndef 		__CIRCULARBUFFERMANAGER_HH__
# define 		__CIRCULARBUFFERMANAGER_HH__

#include		<map>
#include		"Utils/Singleton.hpp"
#include		"CircularBuffer.hh"

class			CircularBufferManager : public Singleton<CircularBufferManager>
{
  friend class		Singleton<CircularBufferManager>;

public:

  enum			eTypeBuffer
    {
      READ_BUFFER,
      WRITE_BUFFER
    };

private:

  // Attributs
  std::map<eTypeBuffer, CircularBuffer *>	*_buffers;

  // Ctor / Dtor
  CircularBufferManager();
  CircularBufferManager(CircularBufferManager const &);
  CircularBufferManager	&operator=(CircularBufferManager const &);
  virtual ~CircularBufferManager();

public:

  // Methods
  void			pushTrame(Trame *trame, eTypeBuffer type);
  Trame const		*getTrame(eTypeBuffer type) const;
  Trame			*popTrame(eTypeBuffer type);
};

#endif
