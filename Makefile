##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## infinadd
##

MAIN     	=	main.c								\

ERROR		=	src/Error/error.c					\
				src/Error/verif_players.c			\
				src/Error/check_map.c				\
				src/Error/ship_matcher.c			\
				src/Error/set_map_test.c			\

CONNECTION	=	src/Connection/pid_connection.c		\

GAME		=	src/Game/launch_game.c				\
				src/Game/gameplay.c					\
				src/Game/send.c						\
				src/Game/receive.c					\

ADDS		=	src/Adds/adds.c						\

CC			=	gcc -I./include -W -Wall -Wextra -g

NAME		=	navy

all:
	make -C lib/my
	$(CC) $(MAIN) $(ERROR) $(CONNECTION) $(GAME) $(ADDS) -o $(NAME) -L. -lmy

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean: clean
	make -C lib/my fclean
	rm -f $(NAME)
	rm -f $(BRUH)

re:     fclean all

tests_run:
	make -C lib/my
	gcc -o Units_Test -I./include Units/units_test.c --coverage -lcriterion -lmy -L.
	./Units_Test