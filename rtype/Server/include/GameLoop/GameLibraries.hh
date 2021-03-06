//
// GameLibraries.hh for RType in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Mon Nov  4 20:17:46 2013 alexis mestag
// Last update Sun Nov 24 22:47:02 2013 alexis mestag
//

#ifndef			__GAMELIBRARIES_HH__
# define		__GAMELIBRARIES_HH__

# include		<map>
# include		<string>
# include		"DynamicLibrary/IDynamicLibrary.hh"
# include		"Entities/Mob.hh"

class			GameLibraries
{
private:
  std::map<std::string, IDynamicLibrary *>	*_libraries;

  void			setLibrariesFromDeepCopy(std::map<std::string, IDynamicLibrary *> &libraries);
  std::map<std::string, IDynamicLibrary *>	&getLibrariesDeepCopy() const;
  void			destroyLibraries();

  GameLibraries(GameLibraries const &rhs);
  GameLibraries		&operator=(GameLibraries const &rhs);
  void			removeLibrary(IDynamicLibrary const &lib);

public:
  GameLibraries();
  virtual ~GameLibraries();

  IDynamicLibrary	*operator[](std::string const &lib);

  void			addLibrary(IDynamicLibrary &lib);
  IDynamicLibrary	*getLibrary(std::string const &lib);
  void			setLibrary(IDynamicLibrary &lib);

  GameLibraries		&getDeepCopy() const;
  IDynamicLibrary	*getRandomLibrary();
  Mob			*getRandomInstance();
  void			deleteInstance(Mob *mob);
  void			loadLibraries();
  void			clear();
};

#endif
