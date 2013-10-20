#ifdef _WIN32

#ifndef __WINDOWSTHREAD_HH__
# define __WINDOWSTHREAD_HH__

#include	"IThread.hh"

class WindowsThread : public IThread
{
private:
	HANDLE  _thread;	
public:
	WindowsThread();
	virtual ~WindowsThread();
	virtual int		start();
	virtual int		createThread(void *(*func)(void*), void *);
	virtual void	destroyThread();
	virtual int		waitThread();
};

#endif

#endif