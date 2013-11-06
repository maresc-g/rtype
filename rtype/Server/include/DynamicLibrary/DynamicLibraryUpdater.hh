//
// DynamicLibraryUpdater.hh for RType in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Mon Nov  4 20:06:17 2013 alexis mestag
// Last update Tue Nov  5 21:49:03 2013 alexis mestag
//

#ifndef			__DYNAMICLIBRARYUPDATER_HH__
# define		__DYNAMICLIBRARYUPDATER_HH__

# include		<string>
# include		"Thread/Thread.hpp"
# include		"FileSystem/Directory.hh"

# define		LIB_PATH	"Libraries"

class			DynamicLibraryUpdater : public Thread
{
private:
  unsigned int		_timer;
  FileSystem::Directory	*_directory;

  DynamicLibraryUpdater(DynamicLibraryUpdater const &rhs);
  DynamicLibraryUpdater	&operator=(DynamicLibraryUpdater const &rhs);

public:
  DynamicLibraryUpdater(unsigned int const sec, std::string const &path = LIB_PATH);
  virtual ~DynamicLibraryUpdater();

  void			startUpdate();
  void			updateLibraries();
  FileSystem::Directory const	&getDirectory() const;
  unsigned int		getTimer() const;
  void			setTimer(unsigned int const timer);
};

#endif
