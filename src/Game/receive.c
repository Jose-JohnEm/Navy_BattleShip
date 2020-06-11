/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** receive.c
*/

#include "src.h"

char *demand(int nb)
{
    char *ans = malloc(sizeof(char) * 3);

    ans[0] = nb / 10 + 'A' - 1;
    ans[1] = nb % 10 + '0';
    ans[2] = '\0';
    return (ans);
}

void increase(int sig)
{
    opponent_pid++;
    (void)sig;
}

void reset(int sig)
{
    opponent_pid = 0;
    (void)sig;
}

void receive(g_data *game_data)
{
    int target = 0;

    opponent_pid = 0;
    signal(SIGUSR1, increase);
    signal(SIGUSR2, reset);
    do {
        pause();
        if (opponent_pid != 0)
            target++;
    } while (opponent_pid > 0);
    my_putstr(demand(target));
    usleep(500);
    if (does_it_touch(game_data, target)) {
        my_kill(game_data->opponent_pid, SIGUSR1);
        my_putstr(": hit\n");
    } else {
        my_kill(game_data->opponent_pid, SIGUSR2);
        my_putstr(": missed\n");
    }
}