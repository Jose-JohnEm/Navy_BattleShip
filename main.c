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
    g_data *game_data = NULL;

    if ((value = error(ac, av)) == 84 || value == 0)
        return (value);
    if (value == 1)
        game_data = pid_connection(value, 0);
    if (value == 2)
        game_data = pid_connection(value, my_getnbr(av[1]));
    if (game_data == NULL)
        return (84);
    navy_game(open(av[value], O_RDONLY), game_data);
    return (0);
}