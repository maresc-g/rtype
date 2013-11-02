#ifndef __WINDOWSDYNAMICLIBRARY_HH__
# define	__WINDOWSDYNAMICLIBRARY_HH__

#include	"Windows.h"
#include	"direct.h"
#include	"DynamicLibrary/IDynamicLibrary.hh"

class WindowsDynamicLibrary : public IDynamicLibrary
{
private:	
	std::string		_path;
	HMODULE			_lib;

private:
	WindowsDynamicLibrary();
	WindowsDynamicLibrary(WindowsDynamicLibrary const &rhs);

	WindowsDynamicLibrary	&operator=(WindowsDynamicLibrary const &rhs);

public:
	WindowsDynamicLibrary(std::string const &path);
	virtual ~WindowsDynamicLibrary();

	virtual bool	load();
	virtual void	destroy();
	virtual void	*getSymbol(std::string const &sym);
};

#endif // !__WINDOWSDYNAMICLIBRARY_HH__
