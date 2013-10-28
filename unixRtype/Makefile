##
## Makefile for  in /home/ansel_l/Documents/Rtype/rtype
## 
## Made by laurent ansel
## Login   <ansel_l@epitech.net>
## 
## Started on  Mon Oct 28 16:06:15 2013 laurent ansel
## Last update Mon Oct 28 16:33:42 2013 laurent ansel
##

NAMESERVER=	rtype-server

SERVER=		Server
SERVER_SRC=	$(SERVER)/src

include		$(SERVER)/Makefile

OBJSERVER=	$(SRCSERVER:.cpp=.o)

CPPFLAGS=	-W -Wall -Wextra -g $(SERVER_INCLUDES)

all:		$(NAMESERVER)

$(NAMESERVER):	$(OBJSERVER)
		g++ -o $(NAMESERVER) $(OBJSERVER) $(LDFLAGS)

clean:
		rm -rf $(OBJSERVER)

fclean:		clean
		rm -rf $(NAMESERVER)

re:		fclean all
