/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** game_struct.h
*/

#include "src.h"

typedef struct g_data
{
    char **player_map;
    __pid_t my_pid;
    __pid_t opponent_pid;
    char **attack_map;
    int num_player;
} g_data;