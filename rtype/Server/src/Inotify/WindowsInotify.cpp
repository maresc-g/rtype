//
// WindowsInotify.cpp for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Sun Nov 10 20:25:25 2013 laurent ansel
// Last update Mon Nov 11 11:33:37 2013 laurent ansel
//

#ifdef	_WIN32
#include			<utility>
#include			<Windows.h>
#include			"Inotify/WindowsInotify.hh"

WindowsInotify::WindowsInotify():
  _event(new std::map<std::string, std::pair<enum IInotify::eInotify, std::string> >),
  _fd(new std::map<std::string, std::pair<HANDLE, enum IInotify::eInotify> >),
  _tab(new std::map<int, enum IInotify::eInotify>)
{
  (*_tab)[FILE_ACTION_ADDED] = IInotify::ADD;
  (*_tab)[FILE_ACTION_RENAMED_NEW_NAME] =  IInotify::ADD;
  (*_tab)[FILE_ACTION_MODIFIED] = IInotify::MODIFY;
  (*_tab)[FILE_ACTION_REMOVED] =  IInotify::DELETEFILE;
  (*_tab)[FILE_ACTION_RENAMED_OLD_NAME] =  IInotify::DELETEFILE;
}

WindowsInotify::~WindowsInotify()
{
  delete _event;
  delete _fd;
}

bool			WindowsInotify::initInotify()
{
  return (true);
}

bool			WindowsInotify::waitEvent(std::string const &path)
{
  char buf[1024 + (sizeof(FILE_NOTIFY_INFORMATION) + MAX_PATH * sizeof(WCHAR))] = "";
  FILE_NOTIFY_INFORMATION *fni = NULL;
  enum IInotify::eInotify	ret = NOTHING;
  DWORD bytesret;

  if (this->_fd->find(path) != this->_fd->end())
    {
      if (ReadDirectoryChangesW((*this->_fd)[path].first, buf, sizeof(buf), 0,
				(*this->_fd)[path].second,
				&bytesret, NULL, NULL))
	{
	  char filename[MAX_PATH];
	  fni = (FILE_NOTIFY_INFORMATION*)buf;
	  for (auto it = _tab->begin() ; it != _tab->end() && ret == NOTHING ; ++it)
	    if ((fni->Action == it->first))
	      ret = it->second;
	  if (fni->FileNameLength)
	    {
	      //wcsncpy_s(filename, MAX_PATH, fni->FileName, fni->FileNameLength / 2);
	      filename[fni->FileNameLength / 2] = 0;
	      WideCharToMultiByte(CP_ACP, 0, fni->FileName, -1, filename, fni->FileNameLength / 2, NULL, NULL);
	      (*this->_event)[path] = std::make_pair(ret, std::string(filename));
            }
	  return (true);
	}
    }
  return (false);
}

std::pair<enum IInotify::eInotify, std::string> const	WindowsInotify::getEvent(std::string const &path) const
{
  if (this->_event->find(path) != this->_event->end())
    return ((*this->_event)[path]);
  return (std::make_pair(IInotify::NOTHING, path));
}

bool			WindowsInotify::addWatch(std::string const &path, enum IInotify::eInotify const event)
{
  HANDLE hDir = CreateFile(
			   path.c_str(),
			   FILE_LIST_DIRECTORY,
			   FILE_SHARE_WRITE | FILE_SHARE_READ | FILE_SHARE_DELETE,
			   NULL,
			   OPEN_EXISTING,
			   FILE_FLAG_BACKUP_SEMANTICS,
			   NULL
			   );

  if (hDir)
    {
      (*this->_fd)[path] = std::make_pair(hDir, event);
      return (true);
    }
  return (false);
}

void			WindowsInotify::destroyInotify()
{
  for (std::map<std::string, std::pair<HANDLE, enum IInotify::eInotify> >::iterator it = this->_fd->begin() ; it != this->_fd->end() ; ++it)
    CloseHandle(it->second.first);
}


void			WindowsInotify::rmWatch(std::string const &path)
{
  if ((std::map<std::string, std::pair<HANDLE, enum IInotify::eInotify> >::iterator it = this->_fd->find(path)) != this->_fd->end())
    {
      CloseHandle(it->second.first);
      it = this->_fd->erase(it);
    }
}

#endif
