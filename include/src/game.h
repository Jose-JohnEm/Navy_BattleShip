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

/*----------- navy_game.c -----------*/
int navy_game(int fd, g_data *game_data);
char **create_map(int fd);
char **init_map_final(void);
char **insert_ships_final(char **final_tab, char **positions);
void print_game_situation(g_data *game_data);

/*----------- input_game.c -----------*/


#endif