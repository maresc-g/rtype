//
// ConnectInfo.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Wed Nov  6 17:33:21 2013 guillaume marescaux
// Last update Wed Nov  6 17:37:54 2013 guillaume marescaux
//

#include			"Core/ConnectInfo.hh"

ConnectInfo::ConnectInfo(std::string const &ip, std::string const &port):
  _ip(ip), _port(port)
{
}

ConnectInfo::ConnectInfo(ConnectInfo const &other):
  _ip(other._ip), _port(other._port)
{
}

ConnectInfo				&ConnectInfo::operator=(ConnectInfo const &other)
{
  if (this != &other)
    {
      _ip = other._ip;
      _port = other._port;
    }
  return (*this);
}

ConnectInfo::~ConnectInfo()
{
}

std::string const		&ConnectInfo::getIp(void) const { return (_ip); }
std::string const		&ConnectInfo::getPort(void) const { return (_port); }
void				ConnectInfo::setIp(std::string const &ip) { _ip = ip; }
void				ConnectInfo::setPort(std::string const &port) { _port = port; }

