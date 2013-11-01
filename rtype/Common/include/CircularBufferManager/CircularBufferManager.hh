//
// CircularBufferManager.hh for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 23:59:10 2013 laurent ansel
// Last update Fri Nov  1 14:39:48 2013 laurent ansel
//

#ifndef 			__CIRCULARBUFFERMANAGER_HH__
# define 			__CIRCULARBUFFERMANAGER_HH__

#include			<map>
#include			<utility>
#include			"Utility/Singleton.hpp"
#include			"Mutex/Mutex.hpp"
#include			"CircularBufferManager/CircularBuffer/CircularBuffer.hh"

class				CircularBufferManager : public Singleton<CircularBufferManager>
{
  friend class			Singleton<CircularBufferManager>;

public:
  enum				eTypeBuffer
    {
      READ_BUFFER,
      WRITE_BUFFER
    };
private:
  std::map<enum eTypeBuffer, CircularBuffer *>	*_buffer;
  Mutex				*_mutex;
public:
  CircularBufferManager();
  virtual ~CircularBufferManager();
  void				pushTrame(Trame *trame, enum eTypeBuffer const type);
  Trame	const			&getTrame(enum eTypeBuffer const type) const;
  Trame				*popTrame(enum eTypeBuffer const type) const;
  Trame				*popTrame(unsigned int const id, std::string const &proto, enum eTypeBuffer const type) const;
  void				deleteTrame(unsigned int const id);
};

#endif
