#ifdef _WIN32

#include		"WindowsThread.hh"

WindowsThread::WindowsThread():
	_thread(NULL)
{

}

WindowsThread::~WindowsThread()
{

}

int				WindowsThread::start()
{
	if (!_thread)
		return (1);
	ResumeThread(_thread);
	return (0);
}

int				WindowsThread::createThread(void *(*func)(void *), void *data)
{
	if ((_thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)func, data, CREATE_SUSPENDED, NULL)) == NULL)
		{
			std::cerr << "error" << std::endl;
			return (1);
		}
	return (0);
}

void			WindowsThread::destroyThread()
{
	if (_thread)
		CloseHandle(_thread);
}

int				WindowsThread::waitThread()
{
	if (WaitForSingleObject(_thread, INFINITE) == WAIT_FAILED)
		return (1);
	return (0);
}

#endif