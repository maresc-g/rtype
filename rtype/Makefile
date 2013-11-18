##
## Makefile for  in /home/ansel_l/Documents/Rtype/rtype
## 
## Made by laurent ansel
## Login   <ansel_l@epitech.net>
## 
## Started on  Mon Oct 28 16:06:15 2013 laurent ansel
## Last update Mon Nov 18 16:03:07 2013 alexis mestag
##

NAMESERVER=	rtype-server
NAMECLIENT=	rtype-client

DYNLIBPATH=	Libraries

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
OBJAI=		$(SRCAI:.cpp=.o)
SOAI=		$(OBJAI:.o=.so)

%.so:		%.o $(OBJSERVER) $(OBJCOMMON)
		g++ -shared -o $@ $< $(OBJSERVER) $(OBJCOMMON)

CPPFLAGS=	-W -Wall -Wextra -g $(SERVER_INCLUDES) $(COMMON_INCLUDES) $(CLIENT_INCLUDES) -fPIC -std=c++0x

all:		$(OBJCOMMON) $(NAMESERVER) $(NAMECLIENT) dynlibs

dynlibs:	$(OBJAI) $(SOAI)

$(NAMESERVER):	$(OBJCOMMON) $(OBJSERVER)
		g++ -o $(NAMESERVER) $(OBJCOMMON) $(OBJSERVER) $(LDFLAGS)

$(NAMECLIENT):	$(OBJCOMMON) $(OBJCLIENT)
		g++ -o $(NAMECLIENT) $(OBJCOMMON) $(OBJCLIENT) $(LDFLAGS)

clean:
		rm -rf $(OBJSERVER) $(OBJCLIENT) $(OBJCOMMON) $(OBJAI)

fclean:		clean
		rm -rf $(NAMESERVER) $(NAMECLIENT) $(SOAI)

re:		fclean all
