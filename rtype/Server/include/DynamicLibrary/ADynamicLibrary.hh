//
// ADynamicLibrary.hh for RType in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Mon Nov  4 21:20:25 2013 alexis mestag
// Last update Mon Nov  4 21:41:40 2013 alexis mestag
//

#ifndef			__ADYNAMICLIBRARY_HH__
# define		__ADYNAMICLIBRARY_HH__

# include		"DynamicLibrary/IDynamicLibrary.hh"

class			ADynamicLibrary : public IDynamicLibrary
{
private:
  std::string		_path;

protected:
  ADynamicLibrary();
  ADynamicLibrary(ADynamicLibrary const &rhs);
  ADynamicLibrary	&operator=(ADynamicLibrary const &rhs);

  void			setPath(std::string const &path);

public:
  ADynamicLibrary(std::string const &path);
  virtual ~ADynamicLibrary();

  virtual std::string const	&getPath() const;
};

#endif
