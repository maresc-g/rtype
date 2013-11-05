##
## Makefile for  in /home/ansel_l/Documents/Rtype/rtype/Server
## 
## Made by laurent ansel
## Login   <ansel_l@epitech.net>
## 
## Started on  Mon Oct 28 16:05:51 2013 laurent ansel
## Last update Mon Nov  4 23:00:52 2013 antoine maitre
##

THREAD=		$(COMMON_SRC)/Thread
MUTEX=		$(COMMON_SRC)/Mutex
SOCKET=		$(COMMON_SRC)/Socket
SELECT=		$(COMMON_SRC)/Select
CIRCULAR_BUFFER_MANAGER=	$(COMMON_SRC)/CircularBufferManager

include		$(THREAD)/Makefile
include		$(MUTEX)/Makefile
include		$(SOCKET)/Makefile
include		$(SELECT)/Makefile
include		$(CIRCULAR_BUFFER_MANAGER)/Makefile

ifndef _WIN32
LDFLAGS +=	-lpthread -D_REENTRANT
endif

COMMON_INCLUDES=	-I $(COMMON)/include
