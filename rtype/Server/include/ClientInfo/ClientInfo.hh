//
// ClientInfo.hh for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 15:46:04 2013 laurent ansel
// Last update Tue Nov  5 19:08:06 2013 laurent ansel
//

#ifndef 			__CLIENTINFO_HH__
# define 			__CLIENTINFO_HH__

#include			<map>
#include			<utility>
#include			"Mutex/Mutex.hpp"
#include			"Command/Command.hh"
#include			"Socket/SocketClient.hpp"

class				ClientInfo
{
private:
  std::map<std::string, SocketClient *>	*_clientInfo;
  std::list<Command *>		*_command;
  std::map<std::string, int>	*_nbTrame;
  unsigned int			_id;
  Mutex				*_mutex;
  unsigned int			_trameId;
  unsigned int			_idGame;
public:
  ClientInfo(SocketClient *clientTcp, SocketClient *clientUdp = NULL, unsigned int const id = 0);
  virtual ~ClientInfo();
  Command const			*getFirstCommand() const;
  void				pushCommand(Trame *trame);
  void				setCommand();
  bool				standbyCommand() const;

  bool				canWriteSomething(std::string const &proto) const;
  void				pushWriteTrame(std::string const &proto, Trame *trame);
  void				writeImmediately(std::string const &proto, Trame *trame);
  void				writeOneTrame(std::string const &proto);
  int				readSomethingInSocket(std::string const &proto);

  bool				alreadySetUdp() const;
  void				setClientUdp(SocketClient *client);

  void				setId(unsigned int const id);
  void				setTrameId(unsigned int const trameId);
  unsigned int			getId() const;
  unsigned int			getTrameId() const;

  int				getFdTcp() const;

  SocketClient			*getClientTcp() const;
  SocketClient			*getClientUdp() const;

  unsigned int			getIdGame() const;
  void				setIdGame(unsigned int const idGame);

  Action const			&getAction() const;
};

#endif
