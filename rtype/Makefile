##
## Makefile for  in /home/ansel_l/Documents/Rtype/rtype
## 
## Made by laurent ansel
## Login   <ansel_l@epitech.net>
## 
## Started on  Mon Oct 28 16:06:15 2013 laurent ansel
## Last update Mon Nov  4 23:12:16 2013 antoine maitre
##

NAMESERVER=	rtype-server

SERVER=		Server
SERVER_SRC=	$(SERVER)/src

COMMON=		Common
COMMON_SRC=	$(COMMON)/src

GAMELOOP=	GameLoop
GAMELOOP_SRC=	$(GAMELOOP)/src

include		$(COMMON)/Makefile
include		$(SERVER)/Makefile
include		$(GAMELOOP)/Makefile

OBJSERVER=	$(SRCSERVER:.cpp=.o)
OBJCOMMON=	$(SRCCOMMON:.cpp=.o)
OBJGAMELOOP=	$(SRCGAMELOOP:.cpp=.o)

CPPFLAGS=	-W -Wall -Wextra -g $(SERVER_INCLUDES) $(COMMON_INCLUDES) $(GAMELOOP_INCLUDES) -std=c++0x

all:		$(OBJCOMMON) $(NAMESERVER)

$(NAMESERVER):	$(OBJCOMMON) $(OBJSERVER) $(OBJGAMELOOP)
		g++ -o $(NAMESERVER) $(OBJCOMMON) $(OBJSERVER) $(OBJGAMELOOP) $(LDFLAGS)

clean:
		rm -rf $(OBJSERVER) $(OBJCOMMON) $(OBJGAMELOOP)

fclean:		clean
		rm -rf $(NAMESERVER)

re:		fclean all
