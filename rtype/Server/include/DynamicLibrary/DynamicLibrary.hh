//
// DynamicLibrary.hh for RType in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype/Server/include/DynamicLibrary
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Sun Nov  3 17:59:31 2013 alexis mestag
// Last update Sun Nov  3 18:04:42 2013 alexis mestag
//

#ifndef			__DYNAMICLIBRARY_HH__
# define		__DYNAMICLIBRARY_HH__

# ifdef	_WIN32
#  include		"DynamicLibrary/WindowsDynamicLibrary.hh"
# else
#  include		"DynamicLibrary/UnixDynamicLibrary.hh"
# endif

# ifdef	_WIN32
class			DynamicLibrary : public WindowsDynamicLibrary
# else
class			DynamicLibrary : public UnixDynamicLibrary
# endif
{
private:
  DynamicLibrary();
  DynamicLibrary(DynamicLibrary const &rhs);
  DynamicLibrary	&operator=(DynamicLibrary const &rhs);

public:
  DynamicLibrary(std::string const &path);
  virtual ~DynamicLibrary();
};

#endif
