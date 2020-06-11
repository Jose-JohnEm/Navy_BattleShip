/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** set_map_test.c
*/

#include "src.h"

char **set_map_test_width(char **map, int diff, int x, int y)
{
    x -= 'A';
    y -= '0' + 1;
    for (int i = 0; i <= diff; i++) {
        map[y][x + i] = diff + 1 + '0';
    }
    return (map);
}

char **set_map_test_length(char **map, int diff, int x, int y)
{
    x -= 'A';
    y -= '0' + 1;
    for (int i = 0; i <= diff; i++) {
        map[y + i][x] = diff + 1 + '0';
    }
    return (map);
}