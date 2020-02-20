/*
** EPITECH PROJECT, 2019
** gameplay.c
** File description:
** navy
*/

#include "src.h"

int is_format_correct(char *str)
{
    if (str[0] < 'A' || str[0] > 'H')
        return -1;
    if (str[1] < '1' || str[1] > '8')
        return -1;
    if (str[2] != '\0')
        return -1;
    return 0;
}

char *check_case(g_data *data)
{
    int i = 0;
    char *str = malloc(100);

    if ((i = read(0, str, 3)) == -1 || i != 3)
        return NULL;
    if (is_format_correct(str) == -1)
        return NULL;
    //repeate_case();
    return str;
}

void gameplay(g_data *data)
{
    char *attack = NULL;

    do {
        my_putstr("\nattack: ");
        attack = check_case(data);
        if (attack == NULL)
            my_putstr("wrong position\n");
    } while (attack == NULL);
    my_putstr(attack);

}