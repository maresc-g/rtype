//
// WindowsSocket.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Mon Oct 28 13:21:19 2013 laurent ansel
// Last update Mon Oct 28 16:39:53 2013 laurent ansel
//

#ifdef _WIN32

#include			"Socket/WindowsSocket.hh"
#include			"Socket/WindowsSocketClient.hh"

#pragma comment(lib, "ws2_32.lib")

WindowsSocket::WindowsSocket():
  _socket(0)
{
  if (WSAStartup(MAKEWORD(2, 2), &_wsaData) != 0)
    {
      std::cout << "WSAStartup failed with error" << std::endl;
      _socket = -1;
    }
}

WindowsSocket::~WindowsSocket()
{
  if (this->_socket != -1)
    WSACleanup();
}

int				WindowsSocket::initialize(std::string const &protocole)
{
  if (protocole == "TCP")
    _socket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0);
  else if (protocole == "UDP")
    _socket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_UDP, NULL, 0, 0);
  if (this->_socket == INVALID_SOCKET)
    {
      std::cout << "WSASocket failed with error" << std::endl;
      return (-1);
    }
  return (0);
}

int				WindowsSocket::destroy()
{
  if (this->_socket == -1)
    return (-1);
  closesocket(this->_socket);
  return (0);
}

int				WindowsSocket::bindSocket(int const port)
{
  sockaddr_in			addr;
  char				*ip;
  hostent			*thisHost;

  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  thisHost = gethostbyname("");
  ip = inet_ntoa(*(struct in_addr *)*thisHost->h_addr_list);
  addr.sin_addr.s_addr = inet_addr(ip);
  if (bind(this->_socket, (SOCKADDR *)&addr, sizeof(addr)) == SOCKET_ERROR)
    return (-1);
  return (0);
}

int				WindowsSocket::listenSocket()
{
  if (listen(this->_socket, SOMAXCONN) == SOCKET_ERROR)
    return (-1);
  return (0);
}

ISocketClient			*WindowsSocket::connectToAddr(std::string const &addr, int const port)
{
  sockaddr_in			addrClient;
  char				*ip;
  hostent			*thisHost;

  addrClient.sin_family = AF_INET;
  addrClient.sin_port = htons(port);
  thisHost = gethostbyname(addr.c_str());
  ip = inet_ntoa(*(struct in_addr *)*thisHost->h_addr_list);
  addrClient.sin_addr.s_addr = inet_addr(ip);
  if ((WSAConnect(this->_socket, (SOCKADDR *)&addrClient, sizeof(addrClient), NULL, NULL, NULL, NULL)) == SOCKET_ERROR)
    return (NULL);
  return (new WindowsSocketClient(this->_socket));
}

ISocketClient			*WindowsSocket::acceptConnection()
{
  struct sockaddr_in		client;
  int				size = sizeof(client);
  SOCKET			socketClient;

  if ((socketClient = WSAAccept(this->_socket, (SOCKADDR*)&client, &size, NULL, NULL)) != SOCKET_ERROR)
    return (new WindowsSocketClient(socketClient));
  return (NULL);
}

#endif
