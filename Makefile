##
## Makefile for PSU_2015_philo in /mnt/62401A64401A3F6B/Dropbox/HED/ALL/epitech/rendu/PSU/PSU_2015_philo
##
## Made by Hed
## Login   <ugo@epitech.net>
##
## Started on  Fri Mar 04 13:38:22 2016 Hed
## Last update Jan May 15 20:10:15 2016
##

CC 	=	gcc

RM	=	rm -f

CFLAGS	+=	-I./sources/includes
CFLAGS  +=	-Wall -Wextra -Werror

LDFLAGS +=	-L./lib/

NAME 	=	server

SRC	=	./sources/main.c		\
		./sources/my_error.c		\
		./sources/my_str_to_wordtab.c	\
		./sources/epur.c		\
		./sources/affFd.c		\
		./sources/handleClient.c 	\
		./sources/command.c		\
		./sources/commandDirectory.c	\
		./sources/commandUseful.c	\
		./sources/myftp.c 		\

OBJ	= 	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
