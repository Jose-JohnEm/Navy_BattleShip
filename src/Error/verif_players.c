/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** verif_players.c
*/

#include "src.h"

int verif_player1(char **av)
{
    int fd = open(av[1], O_RDONLY);

    if (fd == -1)
        return (84);
    if (demand_map(fd) == 1)
        return (1);
    return (84);
}

int verif_player2(char **av)
{
    return (2);
}