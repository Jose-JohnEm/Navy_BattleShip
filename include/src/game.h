/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** game.h
*/

#ifndef GAME_H
#define GAME_H

#ifndef GAME_STRUCT_H
#define GAME_STRUCT_H

#include "src/game/game_struct.h"

#endif

<<<<<<< HEAD
/*----------- navy_game.c -----------*/
=======
/*---------- launch_game.c ------------*/
>>>>>>> 1cb1979d2eaab8ec839489fecdae61b2ffa58b11
int navy_game(int fd, g_data *game_data);
char **create_map(int fd);
char **init_map_final(void);
char **insert_ships_final(char **final_tab, char **positions);
void print_game_situation(g_data *game_data);

<<<<<<< HEAD
/*----------- gameplay.c -----------*/
int gameplay(g_data *data);
char *check_case(g_data *data);
int is_format_correct(char *str);
char *position_is_wrong(char *str, char **map);
int waiting(g_data *data);

/*----------- send.c -----------*/
void can_i_attack(g_data *game_data, char *ans);
int converted_message(char *ans);
void missed(int signum);
void hit(int signum);


/*----------- receive.c -----------*/
void receive(g_data *game_data);
void reset(int sig);
void increase(int sig);
char *demand(int nb);

=======

/*---------- launch_game.c ------------*/
void gameplay(g_data *data);
char *check_case(g_data *data);
int is_format_correct(char *str);
>>>>>>> 1cb1979d2eaab8ec839489fecdae61b2ffa58b11

#endif