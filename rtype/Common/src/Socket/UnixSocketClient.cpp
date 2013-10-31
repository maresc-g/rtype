//
// UnixSocketClient.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 15:26:32 2013 laurent ansel
// Last update Thu Oct 31 10:40:24 2013 laurent ansel
//

#ifndef _WIN32

#include		"Socket/UnixSocketClient.hh"

UnixSocketClient::UnixSocketClient(int const socket, std::string const &protocole, struct sockaddr_in *addr):
  _socket(socket),
  _proto(protocole),
  _addr(addr)
{

}

UnixSocketClient::~UnixSocketClient()
{
}

int			UnixSocketClient::readSocket(std::string &buf, int const size)
{
  int			ret = 0;
  char			tmp[SIZE_BUFFER] = "";
  socklen_t		addrlen = sizeof(*this->_addr);

  if (this->_proto == "UDP")
    ret = recvfrom(this->_socket, tmp, size, 0, (struct sockaddr *)this->_addr, &addrlen);
  else
    ret = recv(this->_socket, tmp, size, MSG_DONTWAIT);
  if (ret != -1)
    buf.assign(tmp);
  return (ret);
}

int			UnixSocketClient::writeSocket(char *buf, int const size)
{
  int			ret = 0;
  socklen_t		addrlen = sizeof(*this->_addr);

  if (this->_proto == "UDP")
    ret = sendto(this->_socket, buf, size, 0, (struct sockaddr *)this->_addr, addrlen);
  else
    ret = send(this->_socket, buf, size, MSG_DONTWAIT);
  return (ret);
}

void			UnixSocketClient::closeSocket() const
{
  close(this->_socket);
}

int			UnixSocketClient::getSocket() const
{
  return (this->_socket);
}

#endif
