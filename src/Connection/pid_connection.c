/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** pid_connection.c
*/

#include "src.h"

int pid_connection(int player, int pid)
{
    __pid_t my_pid;

    my_pid = getpid();
    my_put_nbr(my_pid);
    return (0);
}