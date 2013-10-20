#include	<Windows.h>
#include	<iostream>

class IMutex
{
public:
	virtual ~IMutex(){}
	virtual void initialize() = 0;
	virtual void destroy() = 0;
	virtual void enter() = 0;
	virtual void tryEnter() = 0;
	virtual void leave() = 0;
};