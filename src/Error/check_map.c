/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** check_map.c
*/

#include "src.h"

int verif_cara(int cara, int line, char current)
{
    my_putchar('\n');
    my_put_nbr(line);
    //my_putchar('\n');
    //my_put_nbr(cara);
    my_putstr("\nOK\n");
    if (cara == 1 && current != line + 48)
        return (0);
    if ((cara == 2 || cara == 5) && current != ':')
        return (0);
    if ((cara == 3 || cara == 6) && (current < 'A' || current > 'H'))
        return (0);
    if ((cara == 4 || cara == 7) && (current < '1' || current > '8'))
        return (0);
    return (1);
}

int is_the_map_correct(char *str)
{
    int i;
    int cara;

    for (i = 0, cara = 0; i < 31; i++, cara++) {
        if (verif_cara(cara + 1, i / 8 + 2, str[i]) == 0)
            return (-1);
        if (cara == 8)
            cara = 0;
        my_putchar(str[i]);
    }
    return (1);
}

int demand_map(int fd)
{
    char str[40];
    int rd = read(fd, str, 40);

    if (my_strlen(str) != 32 && my_strlen(str) != 31)
        return (-1);
    if (str[MAX_TO_READ] == '\n')
        str[MAX_TO_READ] = '\0';
    if (is_the_map_correct(str) == -1)
        return (-1);
    str[MAX_TO_READ] = '\0';
    return (1);
}
