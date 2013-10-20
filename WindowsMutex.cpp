#ifdef _WIN32

#include		"WindowsMutex.hh"

WindowsMutex::WindowsMutex()
{
}

WindowsMutex::~WindowsMutex()
{

}

void			WindowsMutex::initialize()
{
	InitializeCriticalSection(&_section);
}

void			WindowsMutex::destroy()
{
	DeleteCriticalSection(&_section);
}

void			WindowsMutex::enter()
{
	EnterCriticalSection(&_section);
}

void			WindowsMutex::tryEnter()
{
	TryEnterCriticalSection(&_section);
}

void			WindowsMutex::leave()
{
	LeaveCriticalSection(&_section);
}

#endif