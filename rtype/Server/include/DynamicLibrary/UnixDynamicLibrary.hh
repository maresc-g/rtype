//
// UnixDynamicLibrary.hh for RType in /home/mestag_a/Documents/Projets/Tek3/RType/DynamicLibrary
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Sat Nov  2 16:54:11 2013 alexis mestag
// Last update Sun Nov  3 18:05:48 2013 alexis mestag
//

#ifndef			__UNIXDYNAMICLIBRARY_HH__
# define		__UNIXDYNAMICLIBRARY_HH__

#include		"DynamicLibrary/IDynamicLibrary.hh"

class			UnixDynamicLibrary : public IDynamicLibrary
{
private:
  std::string		_path;
  void			*_lib;

protected:
  UnixDynamicLibrary();
  UnixDynamicLibrary(UnixDynamicLibrary const &rhs);
  UnixDynamicLibrary	&operator=(UnixDynamicLibrary const &rhs);

public:
  UnixDynamicLibrary(std::string const &path);
  virtual ~UnixDynamicLibrary();

  virtual bool		load();
  virtual void		destroy();
  virtual void		*getSymbol(std::string const &obj);
};

#endif