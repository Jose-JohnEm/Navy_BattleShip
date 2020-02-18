/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** check_map.c
*/

#include "src.h"

int verif_positions(char **tab)
{
    int i;

    for (i = 0; tab[i] != NULL; i++) {
        if (tab[i][2] != tab[i][5] && tab[i][3] != tab[i][6])
            return (-1);
        if (tab[i][2] == tab[i][5] && tab[i][3] == tab[i][6])
            return (-1);
    }
    if (does_it_match(tab) == -1)
        return (-1);
    return (1);
}

int verif_cara(int cara, int line, char current)
{
    if (cara == 1 && current != line + 48)
        return (0);
    if ((cara == 2 || cara == 5) && current != ':')
        return (0);
    if ((cara == 3 || cara == 6) && (current < 'A' || current > 'H'))
        return (0);
    if ((cara == 4 || cara == 7) && (current < '1' || current > '8'))
        return (0);
    if (cara == 8 && current != '\n')
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
    }
    if (verif_positions(my_str_tab(str)) == -1)
        return (-1);
    return (1);
}

int demand_map(int fd)
{
    char str[40];
    int rd = read(fd, str, 40);

    if (rd != 32 && rd != 31)
        return (-1);
    if (rd == 32 && str[MAX_TO_READ - 1] == '\n')
        str[MAX_TO_READ - 1] = '\0';
    if (is_the_map_correct(str) == -1)
        return (-1);
    str[MAX_TO_READ] = '\0';
    return (1);
}
