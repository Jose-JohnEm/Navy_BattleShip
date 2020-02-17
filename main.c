/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** main.c
*/

#include "src.h"

int main(int ac, char **av)
{
    int value = 0;

    if ((value = error(ac, av)) == 84 || value == 0)
        return (value);
    if (value == 1)
        value = pid_connection(value, 0);
    if (value == 2)
        value = pid_connection(value, my_getnbr(av[1]));
    if (value == 84)
        return (value);
    navy_game(my_getnbr(av[value]));
    return (0);
}