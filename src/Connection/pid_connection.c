/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** pid_connection.c
*/

#include "src.h"
pid_t opponent = -1;

void succ_play1(int sig, siginfo_t *act, void *context)
{
    my_putstr("\nenemy connected\n");
    opponent = act->si_pid;
}

void succ_play2(int sig)
{
    my_putstr("successfully connected\n");
}

int connection_first_player()
{
    struct sigaction act;

    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putstr("\nwaiting for enemy connection...\n");
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &succ_play1;
    sigaction(SIGUSR1, &act, NULL);
    pause();
    kill(opponent, SIGUSR2);
    return (0);
}

int connection_second_player(int pid)
{
    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putstr("\n");
    kill(pid, SIGUSR1);
    signal(SIGUSR2, succ_play2);
    pause();
    return (0);
}

int pid_connection(int player, int pid)
{
    if (player == 1)
        connection_first_player();
    if (player == 2)
        connection_second_player(pid);
    return (player);
}