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
    if (demand_map(fd) == -1)
        return (84);
    return (1);
}

int verif_player2(char **av)
{
    int fd = open(av[2], O_RDONLY);

    if (my_str_isnum(av[1]) == 0)
        return (84);
    if (fd == -1)
        return (84);
    return (2);
}