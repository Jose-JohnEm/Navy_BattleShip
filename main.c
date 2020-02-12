/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** main.c
*/

#include "src.h"

int help(void)
{
    my_putstr("USAGE\n     ./navy [first_player_pid] navy_positions\nDESCRIPT");
    my_putstr("ION\n     first_player_pid:  only for the 2nd player.  pid of ");
    my_putstr("the first player.\n     navy_positions:  file representing the");
    my_putstr(" positions of the ships.\n");
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp("-h", av[1]))
        return (help());

}