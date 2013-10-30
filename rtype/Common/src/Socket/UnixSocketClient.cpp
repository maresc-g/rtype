//
// UnixSocketClient.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 15:26:32 2013 laurent ansel
// Last update Wed Oct 30 14:10:14 2013 laurent ansel
//

#ifndef _WIN32

#include		"Socket/UnixSocketClient.hh"

UnixSocketClient::UnixSocketClient(int const socket, std::string const &protocole):
  _socket(socket),
  _proto(protocole)
{

}

UnixSocketClient::~UnixSocketClient()
{
}

int			UnixSocketClient::readSocket(std::string &buf, int const size)
{
  int			ret = 0;
  char			tmp[SIZE_BUFFER] = "";
  struct sockaddr_in	remaddr;
  socklen_t		addrlen = sizeof(remaddr);

  if (this->_proto == "UDP")
    ret = recvfrom(this->_socket, tmp, size, 0, (struct sockaddr *)&remaddr, &addrlen);
  else
    ret = recv(this->_socket, tmp, size, MSG_DONTWAIT);
  if (ret != -1)
    buf.assign(tmp);
  return (ret);
}

int			UnixSocketClient::writeSocket(char *buf, int const size)
{
  int			ret = 0;
  struct sockaddr_in	remaddr;
  socklen_t		addrlen = sizeof(remaddr);

  if (this->_proto == "UDP")
    ret = sendto(this->_socket, buf, size, 0, (struct sockaddr *)&remaddr, addrlen);
  else
    ret = send(this->_socket, buf, size, MSG_DONTWAIT);
  return (ret);
}

void			UnixSocketClient::closeSocket()
{
  close(this->_socket);
}

#endif
