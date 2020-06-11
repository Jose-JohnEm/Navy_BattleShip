/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** error.c
*/

#include "src.h"

int verif_cara_suite(int cara, char current)
{
    if ((cara == 4 || cara == 7) && (current < '1' || current > '8'))
        return (0);
    if (cara == 8 && current != '\n')
        return (0);
    return (1);
}

int help(void)
{
    my_putstr("USAGE\n     ./navy [first_player_pid] navy_positions\nDESCRIPT");
    my_putstr("ION\n     first_player_pid:  only for the 2nd player.  pid of ");
    my_putstr("the first player.\n     navy_positions:  file representing the");
    my_putstr(" positions of the ships.\n");
    return (0);
}

int error(int ac, char **av)
{
    if (av == NULL)
        return (84);
    if (ac == 2 && av[1] != NULL && my_strcmp("-h", av[1]))
        return (help());
    else if (ac != 2 && ac != 3)
        return (84);
    else {
        if (ac == 2)
            return (verif_player1(av));
        if (ac == 3)
            return (verif_player2(av));
    }
    return (0);
}