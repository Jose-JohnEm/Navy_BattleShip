##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## infinadd
##

MAIN     =	main.c						\

ERROR	=	src/Error/error.c			\
			src/Error/verif_players.c	\
			src/Error/check_map.c		\
			src/Error/ship_matcher.c	\

CC		=	gcc -I./include -W -Wall -Wextra -g

NAME	=	navy

all:
	cd lib/my && make
	$(CC) $(MAIN) $(ERROR) -o $(NAME) -L. -lmy

clean:
	rm -f $(OBJ)
	cd lib/my && make clean

fclean: clean
	cd lib/my && make fclean
	rm -f $(NAME)
	rm -f $(BRUH)

re:     fclean all
