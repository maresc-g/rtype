//
// ClientInfo.hh for  in /home/ansel_l/Documents/Rtype/work/Server
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Tue Oct 29 15:46:04 2013 laurent ansel
// Last update Sun Nov 24 14:48:25 2013 laurent ansel
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
public:
  enum				eType
    {
      SERVER,
      GAME
    };
private:
  std::map<std::string, SocketClient *>	*_clientInfo;
  std::map<enum eType, std::list<Command *> *>	*_command;
  // std::list<Command *>		*_command;
  std::map<std::string, int>	*_nbTrame;
  unsigned int			_id;
  Mutex				*_mutex;
  unsigned int			_trameId;
  unsigned int			_idGame;
  std::list<std::pair<int, int>	>	*_delai;
public:
  ClientInfo(SocketClient *clientTcp, SocketClient *clientUdp = NULL, unsigned int const id = 0);
  virtual ~ClientInfo();
  Command const			*getFirstCommand(enum ClientInfo::eType const type) const;
  void				pushCommand(Trame *trame, enum ClientInfo::eType const type);
  void				setCommand();
  bool				standbyCommand(enum ClientInfo::eType const type) const;

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

  Action const			&getAction(enum ClientInfo::eType const type) const;
  void				setAction(Action const &action, enum ClientInfo::eType const type);

  bool				actionServer() const;

  void				setDelai(int const second, int const milli);
  void				getDelai(int delai[2]) const;
  bool				availableDelai() const;

  void				quitGame();
};

#endif
