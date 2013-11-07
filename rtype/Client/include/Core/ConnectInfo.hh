//
// ConnectInfo.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Wed Nov  6 17:30:33 2013 guillaume marescaux
// Last update Wed Nov  6 17:33:11 2013 guillaume marescaux
//

#ifndef 		__CONNECTINFO_HH__
# define 		__CONNECTINFO_HH__

#include		<string>

class			ConnectInfo
{
private:

  // Attributes
  std::string		_ip;
  std::string		_port;

public:

  // Ctor / Dtor
  ConnectInfo(std::string const &ip = "", std::string const &port = "");
  ConnectInfo(ConnectInfo const &other);
  ConnectInfo		&operator=(ConnectInfo const &other);
  virtual ~ConnectInfo();

  // Getters / Setters
  std::string const	&getIp(void) const;
  std::string const	&getPort(void) const;
  void			setIp(std::string const &ip);
  void			setPort(std::string const &port);
};

#endif
