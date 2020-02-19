/*
** EPITECH PROJECT, 2019
** gameplay.c
** File description:
** navy
*/

#include "src.h"

int check_case(g_data *data)
{
    int i = 0;
    char *str = malloc(100);

    if ((i = read(0, str, 3)) == -1 || i != 3)
        return -1;
    if (is_format_correct(str) == -1)
        return -1;
    //repeate_case():
}

void gameplay(g_data *data)
{
    do {
        my_putstr("\nattack: ");
        if (position_is_wrong == -1)
            my_putstr("wrong position\n");
    } while (check_case(data) == -1);

        
    
}