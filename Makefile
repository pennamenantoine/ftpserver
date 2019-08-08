##
## Makefile for make in /home/pennam_a/Systeme_unix/PSU_2015_myftp/tp
##
## Made by antoine pennamen
## Login   <pennam_a@epitech.net>
##
## Started on  Fri May 13 21:36:46 2016 antoine pennamen
## Last update Sun May 15 23:51:40 2016 antoine pennamen
##

NAME	= server

CC	= gcc

RM	= rm -rf

SRC	= server.c \
	  built.c \
	  built2.c \
	  str_to_wordtab.c

OBJ	= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

all	: $(NAME)

$(NAME)	: $(OBJ)
	  $(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean	:
	  $(RM) $(OBJ)

fclean	: clean
	  $(RM) $(NAME)

re	: fclean all
