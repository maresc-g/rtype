##
## Makefile for  in /home/ansel_l/Documents/Rtype/rtype/Server
## 
## Made by laurent ansel
## Login   <ansel_l@epitech.net>
## 
## Started on  Mon Oct 28 16:05:51 2013 laurent ansel
## Last update Thu Nov 21 14:57:37 2013 guillaume marescaux
##

THREAD=		$(COMMON_SRC)/Thread
MUTEX=		$(COMMON_SRC)/Mutex
SOCKET=		$(COMMON_SRC)/Socket
SELECT=		$(COMMON_SRC)/Select
CIRCULAR_BUFFER_MANAGER=	$(COMMON_SRC)/CircularBufferManager
FILESYSTEM=	$(COMMON_SRC)/FileSystem
ACTION=		$(COMMON_SRC)/Action

include		$(THREAD)/Makefile
include		$(MUTEX)/Makefile
include		$(SOCKET)/Makefile
include		$(SELECT)/Makefile
include		$(CIRCULAR_BUFFER_MANAGER)/Makefile
include		$(FILESYSTEM)/Makefile
include		$(ACTION)/Makefile

ifndef _WIN32
LDFLAGS +=	-lpthread -D_REENTRANT
endif

COMMON_INCLUDES=	-I $(COMMON)/include
