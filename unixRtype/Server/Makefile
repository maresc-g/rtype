##
## Makefile for  in /home/ansel_l/Documents/Rtype/rtype/Server
## 
## Made by laurent ansel
## Login   <ansel_l@epitech.net>
## 
## Started on  Mon Oct 28 16:05:51 2013 laurent ansel
## Last update Mon Oct 28 16:35:40 2013 laurent ansel
##

THREAD=		$(SERVER_SRC)/Thread
MUTEX=		$(SERVER_SRC)/Mutex
SOCKET=		$(SERVER_SRC)/Socket

SRCSERVER +=	$(SERVER)/main.cpp

include		$(THREAD)/Makefile
include		$(MUTEX)/Makefile
include		$(SOCKET)/Makefile

ifndef _WIN32
LDFLAGS +=	-lpthread -D_REENTRANT
endif

SERVER_INCLUDES=	-I $(SERVER)/include
