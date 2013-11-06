##
## Makefile<2> for Rtype in /home/mestag_a/Documents/Projets/Tek3/RType/rtype/rtype/Server/src
## 
## Made by alexis mestag
## Login   <mestag_a@epitech.net>
## 
## Started on  Sat Nov  2 18:00:02 2013 alexis mestag
## Last update Tue Nov  5 14:16:42 2013 alexis mestag
##

SRCSERVER +=	$(DYNAMICLIBRARY)/UnixDynamicLibrary.cpp	\
		$(DYNAMICLIBRARY)/WindowsDynamicLibrary.cpp	\
		$(DYNAMICLIBRARY)/ADynamicLibrary.cpp		\
		$(DYNAMICLIBRARY)/DynamicLibrary.cpp		\
		$(DYNAMICLIBRARY)/DynamicLibraryManager.cpp	\
		$(DYNAMICLIBRARY)/DynamicLibraryUpdater.cpp

ifndef _WIN32
LDFLAGS +=	-ldl
endif
