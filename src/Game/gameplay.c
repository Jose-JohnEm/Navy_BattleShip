/*
** EPITECH PROJECT, 2019
** gameplay.c
** File description:
** navy
*/

#include "src.h"

int position_is_wrong(char *str, char **map)
{
    if (map[str[0] - '1'][str[1] - 'A'] == '.')
        return (1);
    return (0);
}

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

int check_case(g_data *data)
{
    int i = 0;
    char *str = malloc(100);

    if ((i = read(0, str, 3)) == -1 || i != 3)
        return -1;
    if (is_format_correct(str) == -1)
        return -1;
    return (position_is_wrong(str, data->attack_map));
}

void gameplay(g_data *data)
{
    int err = 0;

    do {
        my_putstr("\nattack: ");
        err = check_case(data);
        if (err == -1)
            my_putstr("wrong position\n");
    } while (err == -1);
}