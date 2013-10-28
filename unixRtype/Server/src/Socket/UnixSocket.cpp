//
// UnixSocket.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 13:20:50 2013 laurent ansel
// Last update Mon Oct 28 16:39:26 2013 laurent ansel
//

#ifndef _WIN32

#include			"Socket/UnixSocket.hh"
#include			"Socket/UnixSocketClient.hh"

UnixSocket::UnixSocket():
  _socket(0)
{
}

UnixSocket::~UnixSocket()
{
}

int				UnixSocket::initialize(std::string const &protocole)
{
  struct protoent		*proto;

  proto = getprotobyname(protocole.c_str());
  if ((this->_socket = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1)
    {
      dprintf(2, "socket fail\n");
      return (-1);
    }
  return (0);
}

int				UnixSocket::destroy()
{
  if (this->_socket == -1)
    return (-1);
  close(this->_socket);
  return (0);
}

int				UnixSocket::bindSocket(int const port)
{
  struct sockaddr_in		sin;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(this->_socket, (struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
      dprintf(2, "bind fail\n");
      close(this->_socket);
      return (-1);
    }
  return (0);
}

int				UnixSocket::listenSocket()
{
  if (listen(this->_socket, SOMAXCONN) == -1)
    {
      close(this->_socket);
      return (-1);
    }
  return (0);
}

ISocketClient			*UnixSocket::connectToAddr(std::string const &addr, int const port)
{
  struct sockaddr_in		sin;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(addr.c_str());
  if ((connect(this->_socket, (struct sockaddr *)&sin, sizeof(sin))) == -1)
    {
      dprintf(2, "Error: server not found\n");
      return (NULL);
    }
  return (new UnixSocketClient(this->_socket));
}

ISocketClient			*UnixSocket::acceptConnection()
{
  int				fd;
  unsigned int			size;
  struct sockaddr_in		sin;

  size = sizeof(sin);
  if ((fd = accept(this->_socket, (struct sockaddr *)&sin, (socklen_t *)&size)) != -1)
    return (NULL);
  return (new UnixSocketClient(fd));
}

#endif
