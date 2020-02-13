/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** main.c
*/

#include "src.h"

int main(int ac, char **av)
{
    int err_value;

    if ((err_value = error(ac, av)) == 84 || err_value == 0)
        return (err_value);
    return (0);
}