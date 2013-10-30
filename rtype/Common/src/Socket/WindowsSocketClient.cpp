//
// WindowsSocketClient.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 15:26:41 2013 laurent ansel
// Last update Wed Oct 30 11:41:24 2013 laurent ansel
//

#ifdef _WIN32

#include		<string.h>
#include		"Socket/WindowsSocketClient.hh"

WindowsSocketClient::WindowsSocketClient(SOCKET const socket, std::string const &protocole):
  _socket(socket),
  _proto(protocole)
{

}

WindowsSocketClient::~WindowsSocketClient()
{
}

int			WindowsSocketClient::readSocket(std::string &buf, int const size)
{
  DWORD			ret = 0;
  WSABUF		dataBuf;
  char			tmp[SIZE_BUFFER] = "";

  dataBuf.len = SIZE_BUFFER;
  dataBuf.buf = tmp;
  if (WSARecv(this->_socket, &dataBuf, 1, &ret, 0, NULL, NULL) == SOCKET_ERROR)
    return (-1);
  buf.assign(tmp);
  return (ret);
}

int			WindowsSocketClient::writeSocket(char *buf, int const size)
{
  DWORD			ret = 0;
  WSABUF		dataBuf;

  dataBuf.len = size;
  dataBuf.buf = buf;
  if (WSASend(this->_socket, &dataBuf, 1, &ret, 0, NULL, NULL) == SOCKET_ERROR)
    return (-1);
  return (ret);
}

void			WindowsSocketClient::closeSocket()
{
  closesocket(this->_socket);
}

#endif
