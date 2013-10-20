#include	<Windows.h>
#include	<iostream>

class IThread
{
public:
	virtual ~IThread(){}
	virtual int		start() = 0;
	virtual int		createThread(void *(*func)(void*), void *) = 0;
	virtual void	destroyThread() = 0;
	virtual int		waitThread() = 0;
};