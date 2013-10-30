##
## Makefile for  in /home/ansel_l/Documents/Rtype/rtype
## 
## Made by laurent ansel
## Login   <ansel_l@epitech.net>
## 
## Started on  Mon Oct 28 16:06:15 2013 laurent ansel
## Last update Tue Oct 29 16:57:24 2013 laurent ansel
##

NAMESERVER=	rtype-server

SERVER=		Server
SERVER_SRC=	$(SERVER)/src

COMMON=		Common
COMMON_SRC=	$(COMMON)/src

include		$(COMMON)/Makefile
include		$(SERVER)/Makefile

OBJSERVER=	$(SRCSERVER:.cpp=.o)
OBJCOMMON=	$(SRCCOMMON:.cpp=.o)

CPPFLAGS=	-W -Wall -Wextra -g $(SERVER_INCLUDES) $(COMMON_INCLUDES) -std=c++0x

all:		$(OBJCOMMON) $(NAMESERVER)

$(NAMESERVER):	$(OBJCOMMON) $(OBJSERVER)
		g++ -o $(NAMESERVER) $(OBJCOMMON) $(OBJSERVER) $(LDFLAGS)

clean:
		rm -rf $(OBJSERVER) $(OBJCOMMON)

fclean:		clean
		rm -rf $(NAMESERVER)

re:		fclean all
