/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** task01
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
    return;
}
