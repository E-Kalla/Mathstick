##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Make bsq
##

SRC		=	./src/error_management.c	\
			./src/my_putchar.c	\
			./src/my_pustr.c    \
			./src/my_getnbr.c   \
			./src/main.c    \
			./src/prepare_map.c \
			./src/play.c    \
			./src/display.c \
			./src/my_put_nbr.c  \
			./src/allcheck.c    \
			./src/my_strlen.c   \
			./src/modif.c

OBJ 	= 	$(SRC:.c=.o)

NAME	=	matchstick

$(NAME) : $(OBJ)
		gcc -o $(NAME) $(OBJ)
all:	$(NAME)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re: fclean all
