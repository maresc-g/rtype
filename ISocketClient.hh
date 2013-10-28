
#ifndef __ISOCKETCLIENT_HH__
#define __ISOCKETCLIENT_HH__

#include <string>

class ISocketClient
{
public:
	virtual ~ISocketClient(){}
	virtual int readSocket(std::string &, int const) = 0;
	virtual int writeSocket(char *, int const) = 0;
	virtual void closeSocket() = 0;
};

#endif