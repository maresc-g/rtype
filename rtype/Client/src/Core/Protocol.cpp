//
// Protocol.cpp for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Fri Nov  1 13:39:28 2013 guillaume marescaux
// Last update Tue Nov 19 11:21:41 2013 guillaume marescaux
//

#include			<sstream>
#include			"Core/Protocol.hh"
#include			"CircularBufferManager/CircularBufferManager.hh"

//---------------------------------BEGIN CTOR / DTOR------------------------------------------

Protocol::Protocol():
  _ptrs(new std::map<eProtocol, void(Protocol::*)(int const, void *)>),
  _equivalent(new std::map<std::string, eProtocol>),
  _trameId(0)
{
  // ptrs
  _ptrs->insert(std::pair<eProtocol, void(Protocol::*)(int const, void *)>(INITIALIZE, &Protocol::initialize));
  _ptrs->insert(std::pair<eProtocol, void(Protocol::*)(int const, void *)>(GET_GAMELIST, &Protocol::getGamelist));
  _ptrs->insert(std::pair<eProtocol, void(Protocol::*)(int const, void *)>(JOIN, &Protocol::join));
  _ptrs->insert(std::pair<eProtocol, void(Protocol::*)(int const, void *)>(CREATE, &Protocol::create));
  _ptrs->insert(std::pair<eProtocol, void(Protocol::*)(int const, void *)>(ACTION, &Protocol::action));
  _ptrs->insert(std::pair<eProtocol, void(Protocol::*)(int const, void *)>(GET_SPRITE, &Protocol::getSprite));
  _ptrs->insert(std::pair<eProtocol, void(Protocol::*)(int const, void *)>(QUIT_GAME, &Protocol::quitGame));
  _ptrs->insert(std::pair<eProtocol, void(Protocol::*)(int const, void *)>(QUIT_SERVER, &Protocol::quitServer));
  // equivalent
  _equivalent->insert(std::pair<std::string, eProtocol>("BIENVENUE", WELCOME));
  _equivalent->insert(std::pair<std::string, eProtocol>("CHECK", CHECK));
  _equivalent->insert(std::pair<std::string, eProtocol>("GAMELIST", GAMELIST));
  _equivalent->insert(std::pair<std::string, eProtocol>("OK", OK));
  _equivalent->insert(std::pair<std::string, eProtocol>("KO", KO));
  _equivalent->insert(std::pair<std::string, eProtocol>("LAUNCHGAME", LAUNCHGAME));
  _equivalent->insert(std::pair<std::string, eProtocol>("MAP", MAP));
  _equivalent->insert(std::pair<std::string, eProtocol>("ENTITY", ENTITY));
  _equivalent->insert(std::pair<std::string, eProtocol>("SCROLL", SCROLL));
  _equivalent->insert(std::pair<std::string, eProtocol>("DEAD", DEAD));
  _equivalent->insert(std::pair<std::string, eProtocol>("SPRITE", SPRITE));
  _equivalent->insert(std::pair<std::string, eProtocol>("CONTENTFILE", CONTENTFILE));
  _equivalent->insert(std::pair<std::string, eProtocol>("LEVELUP", LEVELUP));
  _equivalent->insert(std::pair<std::string, eProtocol>("ENDGAME", ENDGAME));
  _equivalent->insert(std::pair<std::string, eProtocol>("SERVERQUIT", SERVERQUIT));
}

Protocol::~Protocol()
{
  delete _ptrs;
  delete _equivalent;
}

//----------------------------------END CTOR / DTOR-------------------------------------------

//-----------------------------------BEGIN METHODS--------------------------------------------

void				Protocol::protocolMsg(eProtocol proto, int const id, void *data)
{
  (this->*(*_ptrs)[proto])(id, data);
  _trameId++;
}

Protocol::eProtocol		Protocol::getMsg(Trame *trame)
{
  std::istringstream		iss(trame->getContent());
  std::string			tmp;
  std::string			tmp2 = trame->getContent();
  size_t			pos;

  // std::cout << "CONTENT = ";
  // std::cout.write(trame->getContent().c_str(), trame->getContent().size());
  // std::cout << std::endl;
  iss >> tmp;
  tmp2.erase(0, tmp.size() + 2);
  pos = tmp2.find(END_TRAME);
  if (pos != std::string::npos)
    tmp2.erase(pos, pos + std::string(END_TRAME).size());
  pos = tmp.find(END_TRAME);
  if (pos != std::string::npos)
    tmp.erase(pos, pos + std::string(END_TRAME).size());
  trame->setContent(tmp2);
  return ((*_equivalent)[tmp]);
}

//------------------------------------END METHODS---------------------------------------------

//-------------------------------BEGIN PRIVATE METHODS----------------------------------------

void				Protocol::initialize(int const id, void *)
{
  Trame				*trame = new Trame(id, _trameId, "UDP", "INITIALIZE", true);
  CircularBufferManager		*manager = CircularBufferManager::getInstance();

  std::cout << "TRAME = " << trame->toString() << std::endl;
  manager->pushTrame(trame, CircularBufferManager::WRITE_BUFFER);
}

void				Protocol::getGamelist(int const id, void *)
{
  Trame				*trame = new Trame(id, _trameId, "UDP", "GAMELIST", true);
  CircularBufferManager		*manager = CircularBufferManager::getInstance();

  manager->pushTrame(trame, CircularBufferManager::WRITE_BUFFER);
}

void				Protocol::join(int const id, void *data)
{
  std::string			tmp("JOIN ");
  tmp += *(reinterpret_cast<int *>(data));
  Trame				*trame = new Trame(id, _trameId, "TCP", tmp, true);
  CircularBufferManager		*manager = CircularBufferManager::getInstance();

  manager->pushTrame(trame, CircularBufferManager::WRITE_BUFFER);
}

void				Protocol::create(int const id, void *data)
{
  std::string			tmp("CREATE ");
  tmp += *(reinterpret_cast<std::string *>(data));
  Trame				*trame = new Trame(id, _trameId, "TCP", tmp, true);
  CircularBufferManager		*manager = CircularBufferManager::getInstance();

  manager->pushTrame(trame, CircularBufferManager::WRITE_BUFFER);
}

void				Protocol::action(int const id, void *data)
{
  std::string			tmp("ACTION");
  tmp += *(reinterpret_cast<std::string *>(data));
  Trame				*trame = new Trame(id, _trameId, "UDP", tmp, true);
  CircularBufferManager		*manager = CircularBufferManager::getInstance();

  std::cout << "|" << *(reinterpret_cast<std::string *>(data)) << "|" << std::endl;
  manager->pushTrame(trame, CircularBufferManager::WRITE_BUFFER);
}

void				Protocol::getSprite(int const id, void *data)
{
  std::string			tmp("GETSPRITE ");
  tmp += *(reinterpret_cast<std::string *>(data));
  Trame				*trame = new Trame(id, _trameId, "TCP", tmp, true);
  CircularBufferManager		*manager = CircularBufferManager::getInstance();

  manager->pushTrame(trame, CircularBufferManager::WRITE_BUFFER);
}

void				Protocol::quitGame(int const id, void *)
{
  Trame				*trame = new Trame(id, _trameId, "TCP", "QUITGAME", true);
  CircularBufferManager		*manager = CircularBufferManager::getInstance();

  manager->pushTrame(trame, CircularBufferManager::WRITE_BUFFER);
}

void				Protocol::quitServer(int const id, void *)
{
  Trame				*trame = new Trame(id, _trameId, "TCP", "QUITSERVER", true);
  CircularBufferManager		*manager = CircularBufferManager::getInstance();

  manager->pushTrame(trame, CircularBufferManager::WRITE_BUFFER);
}

//---------------------------------END PRIVATE METHODS----------------------------------------
