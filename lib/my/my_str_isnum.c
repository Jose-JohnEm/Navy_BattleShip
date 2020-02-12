/*
** EPITECH PROJECT, 2019
** my_str_isnum.c
** File description:
** task01
*/

#include <unistd.h>

int my_str_isnum(char const *str)
{
    if (str == NULL)
        return (0);
    for (int a = 0; str[a] != '\0'; a++) {
        if (a >= 48 && a <= 57)
            return (1);
    }
    return (0);
}
