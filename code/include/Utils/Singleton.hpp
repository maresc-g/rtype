//
// Singleton.hpp for nibbler in /home/maresc_g/Projets/en_cours/nibbler
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Mar 12 11:54:01 2013 guillaume marescaux
// Last update Sat Mar 23 12:37:27 2013 guillaume marescaux
//

#ifndef			__SINGLETON_HPP__
#define			__SINGLETON_HPP__

#include		<cstdlib>

template <typename T>
class			Singleton
{
private:

  // Attributs
  static T		*_instance;

protected:

  // Ctor / Dtor
  Singleton<T>() {}
  virtual ~Singleton<T>() {}

public:

  // Ctor / Dtor singletone
  static T		*getInstance()
  {
    if (_instance == NULL)
      _instance = new T;
    return (_instance);
  }

  static void		deleteInstance()
  {
    if (_instance)
      {
	delete _instance;
	_instance = NULL;
      }
  }
};

template <typename T>
T	*Singleton<T>::_instance = NULL;

#endif
