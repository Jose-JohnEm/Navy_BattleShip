/*
** EPITECH PROJECT, 2019
** gameplay.c
** File description:
** navy
*/

#include "src.h"

char *position_is_wrong(char *str, char **map)
{
    if (map[str[1] - '1'][str[0] - 'A'] == '.')
        return (str);
    return (NULL);
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

char *check_case(g_data *data)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 100);

    if ((i = read(0, str, 100)) == -1 || i != 3)
        return NULL;
    str[i - 1] = '\0';
    if (is_format_correct(str) == -1)
        return NULL;
    return (position_is_wrong(str, data->attack_map));
}

int waiting(g_data *data)
{
    my_putstr("\nwaiting for enemy's attack...\n");
    receive(data);
    return (1);
}

int gameplay(g_data *data)
{
    char *ans;

    do {
        my_putstr("\nattack: ");
        ans = check_case(data);
        if (ans == NULL)
            my_putstr("wrong position");
    } while (ans == NULL);
    can_i_attack(data, ans);
    return (2);
}