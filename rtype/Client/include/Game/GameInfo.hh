//
// GameInfo.hh for  in /home/maresc_g/Projets/en_cours/rtypeSource
// 
// Made by guillaume marescaux
// Login   <maresc_g@epitech.net>
// 
// Started on  Tue Oct 29 14:35:13 2013 guillaume marescaux
// Last update Tue Oct 29 14:52:32 2013 guillaume marescaux
//

#ifndef 		__GAMEINFO_HH__
# define 		__GAMEINFO_HH__

#include		<string>

class			GameInfo
{
private:

  // Attributes
  int			_id;
  std::string		_name;
  int			_nbPlayer;
  int			_level;

public:

  // Ctor / Dtor
  GameInfo(int id = 0, std::string const &name = "", int nbPlayer = 0, int level = 0);
  GameInfo(GameInfo const &other);
  GameInfo		&operator=(GameInfo const &other);
  virtual ~GameInfo();

  // Getters / Setters
  int			getId(void) const;
  void			setId(int const id);
  std::string const	&getName(void) const;
  void			setName(std::string const &name);
  int			getNbPlayer(void) const;
  void			setNbPlayer(int const nbPlayer);
  int			getLevel(void) const;
  void			setLevel(int const level);
};

#endif
