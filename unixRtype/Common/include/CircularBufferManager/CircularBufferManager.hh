//
// CircularBufferManager.hh for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 23:59:10 2013 laurent ansel
// Last update Tue Oct 29 14:33:27 2013 laurent ansel
//

#ifndef 			__CIRCULARBUFFERMANAGER_HH__
# define 			__CIRCULARBUFFERMANAGER_HH__

#include			<map>
#include			<utility>
#include			"CircularBufferManager/CircularBuffer/CircularBuffer.hh"

class				CircularBufferManager
{
public:
  enum				eTypeBuffer
    {
      READ_BUFFER,
      WRITE_BUFFER
    };
private:
  std::map<enum eTypeBuffer, CircularBuffer *>	*_buffer;
public:
  CircularBufferManager();
  virtual ~CircularBufferManager();
  void				pushTrame(Trame *trame, enum eTypeBuffer const type);
  Trame	const			&getTrame(enum eTypeBuffer const type) const;
  Trame				*popTrame(enum eTypeBuffer const type) const;
};

#endif
