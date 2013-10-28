
#ifndef __WINDOWSSOCKETCLIENT_HH__
#define __WINDOWSSOCKETCLIENT_HH__

#ifdef _WIN32

#include <WinSock2.h>
#include "ISocketClient.hh"

#pragma comment(lib, "ws2_32.lib")

class WindowsSocketClient : public ISocketClient
{
private:
	SOCKET _socket;
public:
	WindowsSocketClient(SOCKET const);
	virtual ~WindowsSocketClient();
	virtual int readSocket(std::string &, int const);
	virtual int writeSocket(char *, int const);
	virtual void closeSocket();
};

#endif

#endif