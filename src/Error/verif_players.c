/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** verif_players.c
*/

#include "src.h"

char *avclean(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 32 || str[i] > 126)
            str[i] = '\0';
    return (str);
}

int verif_player1(char **av)
{
    int fd = open(av[1], O_RDONLY);

    if (fd == -1)
        return (84);
    if (demand_map(fd) == -1)
        return (84);
    close(fd);
    return (1);
}

int verif_player2(char **av)
{
    int fd = open(av[2], O_RDONLY);

    if (my_str_isnum(av[1]) == 0)
        return (84);
    if (fd == -1)
        return (84);
    if (demand_map(fd) == -1)
        return (84);
    close(fd);
    return (2);
}