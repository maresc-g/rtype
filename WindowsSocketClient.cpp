#ifdef _WIN32

#include "WindowsSocketClient.hh"

WindowsSocketClient::WindowsSocketClient(SOCKET const socket):
	_socket(socket)
{

}

WindowsSocketClient::~WindowsSocketClient()
{
}

int		WindowsSocketClient::readSocket(std::string &buf, int const size)
{
	DWORD ret = 0;
	WSABUF dataBuf;
	char	tmp[4096];

	dataBuf.len = 4096;
	dataBuf.buf = tmp;
	if (WSARecv(this->_socket, &dataBuf, 1, &ret, 0, NULL, NULL) == SOCKET_ERROR)
		return (-1);
	buf = tmp;
	return (ret);
}

int		WindowsSocketClient::writeSocket(char *buf, int const size)
{
	DWORD ret = 0;
	WSABUF dataBuf;

	dataBuf.len = size;
	dataBuf.buf = buf;
	if (WSASend(this->_socket, &dataBuf, 1, &ret, 0, NULL, NULL) == SOCKET_ERROR)
		return (-1);
	return (ret);
}

void	WindowsSocketClient::closeSocket()
{
	closesocket(this->_socket);
}

#endif