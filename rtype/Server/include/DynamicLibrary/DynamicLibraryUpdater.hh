//
// DynamicLibraryUpdater.hh for RType in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype
// 
// Made by alexis mestag
// Login   <mestag_a@epitech.net>
// 
// Started on  Mon Nov  4 20:06:17 2013 alexis mestag
// Last update Mon Nov  4 20:07:25 2013 alexis mestag
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
  FileSystem::Directory	*_directory;

  DynamicLibraryUpdater(DynamicLibraryUpdater const &rhs);
  DynamicLibraryUpdater	&operator=(DynamicLibraryUpdater const &rhs);

  void				setDirectory(FileSystem::Directory const &directory);

public:
  DynamicLibraryUpdater(std::string const &path = LIB_PATH);
  virtual ~DynamicLibraryUpdater();

  FileSystem::Directory const	&getDirectory() const;
};

#endif
