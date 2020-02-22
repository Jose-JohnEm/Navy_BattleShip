/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** send_receive.c
*/

#include "src.h"

void hit(int signum)
{
    my_putstr(": hit\n");
    opponent_pid = 'x';
    (void)signum;
}

void missed(int signum)
{
    my_putstr(": missed\n");
    opponent_pid = 'o';
    (void)signum;
}

int converted_message(char *ans)
{
    int res = 0;

    res = (ans[0] - 'A' + 1) * 10 + ans[1] - '0';
    return (res);
}

void can_i_attack(g_data *game_data, char *ans)
{
    int sign = converted_message(ans);

    signal(SIGUSR1, hit);
    signal(SIGUSR2, missed);
    for (int i = 0; i < sign; i++) {
        my_kill(game_data->opponent_pid, SIGUSR1);
    }
    my_kill(game_data->opponent_pid, SIGUSR2);
    my_putstr(ans);
    pause();
    game_data->attack_map[(sign % 10) - 1][sign / 10 - 1] = opponent_pid;
    opponent_pid = 0;
}