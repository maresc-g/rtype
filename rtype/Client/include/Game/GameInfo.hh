//
// GameInfo.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Oct 29 14:35:13 2013 guillaume marescaux
// Last update Wed Nov 13 11:00:22 2013 cyril jourdain
//

#ifndef 		__GAMEINFO_HH__
# define 		__GAMEINFO_HH__

#include		<string>

class			GameInfo
{
private:

  // Attributes
  std::string		_id;
  std::string		_name;
  std::string		_nbPlayer;
  std::string		_level;

public:

  // Ctor / Dtor
  GameInfo(std::string const & id = "", std::string const &name = "", std::string const & nbPlayer = "", std::string const & level = "");
  GameInfo(GameInfo const &other);
  GameInfo		&operator=(GameInfo const &other);
  virtual ~GameInfo();

  // Getters / Setters
  std::string const	&getId(void) const;
  void			setId(std::string const &id);
  std::string const	&getName(void) const;
  void			setName(std::string const &name);
  std::string const 	&getNbPlayer(void) const;
  void			setNbPlayer(std::string const &nbPlayer);
  std::string const 	&getLevel(void) const;
  void			setLevel(std::string const &level);
};

#endif
