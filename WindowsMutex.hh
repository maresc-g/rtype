#ifdef _WIN32

#ifndef __WINDOWSMUTEX_HH__
# define __WINDOWSMUTEX_HH__

#include	"IMutex.hh"

class WindowsMutex : public IMutex
{
private:
	CRITICAL_SECTION _section;
public:
	WindowsMutex();
	virtual ~WindowsMutex();
	virtual void initialize();
	virtual void destroy();
	virtual void enter();
	virtual void tryEnter();
	virtual void leave();
};

#endif

#endif