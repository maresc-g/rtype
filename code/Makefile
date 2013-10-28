##
## Makefile for server in /home/maresc_g/Projets/en_cours/rtypeSource
##
## Made by guillaume marescaux
## Login   <maresc_g@epitech.net>
##
## Started on  Fri Oct 25 11:19:10 2013 guillaume marescaux
## Last update Fri Oct 25 13:35:13 2013 guillaume marescaux
##

NAME=		server

SRC_PATH=	src

SRC=		src/CircularBuffer/CircularBufferManager.cpp \
		src/main.cpp \

OBJ=		$(SRC:.cpp=.o)

INCLUDES=	-I include

include		$(SRC_PATH)/Makefile

CPPFLAGS=	-W -Wall -Wextra $(INCLUDES) --std=c++0x

RM=		rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
