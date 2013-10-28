#ifdef _WIN32

#include <iostream>
#include <WinSock2.h>
#include "ISocket.hh"

class WindowsSocket : public ISocket
{
private:
	SOCKET		_socket;
	WSADATA		_wsaData;
public:
	WindowsSocket();
	virtual ~WindowsSocket();
	virtual int initialize(std::string const &);
	virtual int destroy();
	virtual int bindSocket(int const);
	virtual int listenSocket();
	virtual ISocketClient *connectToAddr(std::string const &, int const);
	virtual ISocketClient *acceptConnection();
};

#endif