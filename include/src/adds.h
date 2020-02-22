/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** adds.h
*/

#ifndef ADDS_H
#define ADDS_H

#include "src.h"

/*------------ adds.c ----------*/
void my_kill(pid_t pid, int signal);
int is_a_ship(char c);
int does_it_touch(g_data *game_data, int target);

#endif