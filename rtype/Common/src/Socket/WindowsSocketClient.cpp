//
// WindowsSocketClient.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 15:26:41 2013 laurent ansel
// Last update Tue Nov  5 18:18:08 2013 laurent ansel
//

#ifdef _WIN32

#include		<string.h>
#include		"Socket/WindowsSocketClient.hh"

WindowsSocketClient::WindowsSocketClient(SOCKET const socket, std::string const &protocole, struct sockaddr_in *addr):
  _socket(socket),
  _proto(protocole),
  _addr(addr)
{

}

WindowsSocketClient::~WindowsSocketClient()
{
}

int			WindowsSocketClient::readSocket(char *buf, int const size) const
{
  DWORD			ret = 0;
  WSABUF		dataBuf;

  dataBuf.len = SIZE_BUFFER;
  dataBuf.buf = buf;
  if (WSARecv(this->_socket, &dataBuf, 1, &ret, 0, NULL, NULL) == SOCKET_ERROR)
    return (-1);
  return (ret);
}

int			WindowsSocketClient::writeSocket(char *buf, int const size) const
{
  DWORD			ret = 0;
  WSABUF		dataBuf;

  dataBuf.len = size;
  dataBuf.buf = buf;
  if (WSASend(this->_socket, &dataBuf, 1, &ret, 0, NULL, NULL) == SOCKET_ERROR)
    return (-1);
  return (ret);
}

void			WindowsSocketClient::closeSocket() const
{
  closesocket(this->_socket);
}

int			WindowsSocketClient::getSocket() const
{
  return (this->_socket);
}

void			WindowsSocketClient::setAddr(struct sockaddr_in *addr)
{
  this->_addr = addr;
}

struct sockaddr_in	*WindowsSocketClient::getAddr() const
{
  return (this->_addr);
}

#endif
