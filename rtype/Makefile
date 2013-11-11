##
## Makefile for  in /home/ansel_l/Documents/Rtype/rtype
## 
## Made by laurent ansel
## Login   <ansel_l@epitech.net>
## 
## Started on  Mon Oct 28 16:06:15 2013 laurent ansel
## Last update Sat Nov  9 17:43:39 2013 laurent ansel
##

NAMESERVER=	rtype-server
NAMECLIENT=	rtype-client

SERVER=		Server
SERVER_SRC=	$(SERVER)/src

COMMON=		Common
COMMON_SRC=	$(COMMON)/src

CLIENT=		Client
CLIENT_SRC=	$(CLIENT)/src

include		$(COMMON)/Makefile
include		$(SERVER)/Makefile
include		$(CLIENT)/Makefile

OBJSERVER=	$(SRCSERVER:.cpp=.o)
OBJCOMMON=	$(SRCCOMMON:.cpp=.o)
OBJCLIENT=	$(SRCCLIENT:.cpp=.o)

CPPFLAGS=	-W -Wall -Wextra -g $(SERVER_INCLUDES) $(COMMON_INCLUDES) $(CLIENT_INCLUDES) -std=c++0x

all:		$(OBJCOMMON) $(NAMESERVER) $(NAMECLIENT)

$(NAMESERVER):	$(OBJCOMMON) $(OBJSERVER)
		g++ -o $(NAMESERVER) $(OBJCOMMON) $(OBJSERVER) $(LDFLAGS)

$(NAMECLIENT):	$(OBJCOMMON) $(OBJCLIENT)
		g++ -o $(NAMECLIENT) $(OBJCOMMON) $(OBJCLIENT) $(LDFLAGS)

clean:
		rm -rf $(OBJSERVER) $(OBJCLIENT) $(OBJCOMMON)

fclean:		clean
		rm -rf $(NAMESERVER) $(NAMECLIENT)

re:		fclean all
