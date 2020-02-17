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
    char **enemy_map;
    __pid_t pid;
} g_data;