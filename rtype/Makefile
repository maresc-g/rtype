##
## Makefile for  in /home/ansel_l/Documents/Rtype/rtype
## 
## Made by laurent ansel
## Login   <ansel_l@epitech.net>
## 
## Started on  Mon Oct 28 16:06:15 2013 laurent ansel
## Last update Tue Nov  5 10:17:36 2013 guillaume marescaux
##

NAMESERVER=	rtype-server
NAMECLIENT=	rtype-client

SERVER=		Server
SERVER_SRC=	$(SERVER)/src

COMMON=		Common
COMMON_SRC=	$(COMMON)/src

CLIENT=		Client
CLIENT_SRC=	$(CLIENT)/src

GAMELOOP=	GameLoop
GAMELOOP_SRC=	$(GAMELOOP)/src

include		$(COMMON)/Makefile
include		$(SERVER)/Makefile
include		$(GAMELOOP)/Makefile
include		$(CLIENT)/Makefile

OBJSERVER=	$(SRCSERVER:.cpp=.o)
OBJCOMMON=	$(SRCCOMMON:.cpp=.o)
OBJCLIENT=	$(SRCCLIENT:.cpp=.o)
OBJGAMELOOP=	$(SRCGAMELOOP:.cpp=.o)

CPPFLAGS=	-W -Wall -Wextra -g $(SERVER_INCLUDES) $(COMMON_INCLUDES) $(CLIENT_INCLUDES) $(GAMELOOP_INCLUDES) -std=c++0x

all:		$(OBJCOMMON) $(NAMESERVER) $(NAMECLIENT)

$(NAMESERVER):	$(OBJCOMMON) $(OBJSERVER)
		g++ -o $(NAMESERVER) $(OBJCOMMON) $(OBJSERVER) $(LDFLAGS)

$(NAMECLIENT):	$(OBJCOMMON) $(OBJCLIENT)
		g++ -o $(NAMECLIENT) $(OBJCOMMON) $(OBJCLIENT) $(LDFLAGS)

clean:
		rm -rf $(OBJSERVER) $(OBJCLIENT) $(OBJCOMMON) $(OBJGAMELOOP)

fclean:		clean
		rm -rf $(NAMESERVER) $(NAMECLIENT)

re:		fclean all
