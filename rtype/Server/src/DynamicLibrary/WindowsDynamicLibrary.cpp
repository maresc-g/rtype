#include		<iostream>
#include		"DynamicLibrary/WindowsDynamicLibrary.hh"

WindowsDynamicLibrary::WindowsDynamicLibrary() :
	_path(""), _lib(NULL)
{
}

WindowsDynamicLibrary::WindowsDynamicLibrary(std::string const &path) :
	_path(path)
{

}

WindowsDynamicLibrary::WindowsDynamicLibrary(WindowsDynamicLibrary const &rhs)
{
	*this = rhs;
}

WindowsDynamicLibrary::~WindowsDynamicLibrary()
{
	if (_lib)
		this->destroy();
}

WindowsDynamicLibrary	&WindowsDynamicLibrary::operator=(WindowsDynamicLibrary const &rhs)
{
	if (this != &rhs)
	{

	}
	return (*this);
}

bool		WindowsDynamicLibrary::load()
{
	bool	ret = true;
	_lib = LoadLibrary(_path.c_str());
	if (!_lib) {
		std::cerr << GetLastError() << std::endl;
		ret = false;
	}
	return (ret);
}

void		WindowsDynamicLibrary::destroy()
{
	FreeLibrary(_lib);
	_lib = NULL;
}

void		*WindowsDynamicLibrary::getSymbol(std::string const &sym)
{
	void	*symbol;

	symbol = GetProcAddress(_lib, sym.c_str());
	if (!symbol) {
		std::cerr << GetLastError() << std::endl;
	}
	return (symbol);
}