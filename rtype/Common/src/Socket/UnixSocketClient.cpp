//
// UnixSocketClient.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 15:26:32 2013 laurent ansel
// Last update Sat Nov  2 16:33:14 2013 laurent ansel
//

#ifndef _WIN32

#include		<iostream>
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

int			UnixSocketClient::readSocket(char *buf, int const size) const
{
  int			ret = 0;
  socklen_t		addrlen = sizeof(*this->_addr);

  if (this->_proto == "UDP")
    ret = recvfrom(this->_socket, buf, size, 0, (struct sockaddr *)this->_addr, &addrlen);
  else
    ret = recv(this->_socket, buf, size, MSG_DONTWAIT);
  std::cout << "READ : [" << buf << "]" << std::endl;
  return (ret);
}

int			UnixSocketClient::writeSocket(char *buf, int const size) const
{
  int			ret = 0;
  socklen_t		addrlen = sizeof(*this->_addr);

  std::cout << "WRITE : [" << buf << "]" << std::endl;
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

void			UnixSocketClient::setAddr(struct sockaddr_in *addr)
{
  this->_addr = addr;
}

struct sockaddr_in	*UnixSocketClient::getAddr() const
{
  return (this->_addr);
}

#endif
