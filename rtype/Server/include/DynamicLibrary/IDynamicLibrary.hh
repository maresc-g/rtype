//
// IDynamicLibrary.hh for RType in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype/Server/include/DynamicLibrary
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Sat Nov  2 16:41:20 2013 alexis mestag
// Last update Mon Nov  4 12:54:16 2013 alexis mestag
//

#ifndef			__IDYNAMICLIBRARY_HH__
# define		__IDYNAMICLIBRARY_HH__

# include		<string>

class			IDynamicLibrary
{
public:
  virtual ~IDynamicLibrary() {}
  virtual bool		load() = 0;
  virtual void		destroy() = 0;
  virtual void		*getSymbol(std::string const &) = 0;
};

#endif
