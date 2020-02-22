/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** adds.c
*/

#include "src.h"

void my_kill(pid_t pid, int signal)
{
    kill(pid, signal);
    usleep(100);
}

int is_a_ship(char c)
{
    if (c == '2' || c == '3' || c == '4' || c == '5')
        return (1);
    return (0);
}

int does_it_touch(g_data *game_data, int target)
{
    if (is_a_ship(game_data->player_map[(target % 10) - 1][target / 10 - 1])) {
        game_data->player_map[(target % 10) - 1][target / 10 - 1] = 'x';
        return (1);
    }
    game_data->player_map[(target % 10) - 1][target / 10 - 1] = 'o';
    return (0);
}

int there_is_a_ship(g_data *game_data)
{
    int tar = 0;
    int hits = 0;

    for (int x = 0, y = 0; y == 8 && x == 8; x++) {
        if (game_data->player_map[y][x] == 'x')
            tar++;
        if (game_data->attack_map[y][x] == 'x')
            hits++;
        if (x == 8) {
            x = 0;
            y++;
        }
    }
    if (hits != 14)
        return (1);
    return (0);
}

void who_loose(int turn)
{
    if (turn == 2)
        my_putstr("\nI won\n");
    if (turn == 1)
        my_putstr("\nEnemy won\n");
}