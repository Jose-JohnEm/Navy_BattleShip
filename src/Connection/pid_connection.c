/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** pid_connection.c
*/

#include "src.h"

void succ_play1(int sig, siginfo_t *act, void *context)
{
    my_putstr("\nenemy connected\n");
    opponent_pid = act->si_pid;
    (void)sig;
    (void)context;
}

void succ_play2(int sig)
{
    my_putstr("successfully connected\n");
    (void)sig;
}

int connection_first_player(void)
{
    struct sigaction act;

    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putstr("\nwaiting for enemy connection...\n");
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &succ_play1;
    sigaction(SIGUSR1, &act, NULL);
    pause();
    kill(opponent_pid, SIGUSR2);
    return (0);
}

int connection_second_player(int pid)
{
    opponent_pid = pid;
    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putstr("\n");
    kill(pid, SIGUSR1);
    signal(SIGUSR2, succ_play2);
    pause();
    return (0);
}

g_data *pid_connection(int player, int pid)
{
    g_data *game_data = malloc(sizeof(g_data));

    if (player == 1)
        connection_first_player();
    if (player == 2)
        connection_second_player(pid);
    game_data->num_player = player;
    game_data->my_pid = getpid();
    game_data->opponent_pid = opponent_pid;
    game_data->player_map = NULL;
    return (game_data);
}