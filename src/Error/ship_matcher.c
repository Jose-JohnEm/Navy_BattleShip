/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** ship_matcher.c
*/

#include "src.h"

int do_not_cross(char **map)
{
    char tmp;
    int ok[4] = {0, 0, 0, 0};

    for (int i = 0, j = 0; i < 8; j++) {
        if (j == 8) {
            i++;
            j = -1;
        }
        else if ((tmp = map[i][j]) == '2' || tmp == '3' || tmp == '4'
            || tmp == '5')
            ok[tmp - '0' - 2]++;
    }
    if (ok[0] == 2 && ok[1] == 3 && ok[2] == 4 && ok[3] == 5)
        return (1);
    return (-1);
}

char **insert_ship(char **map, char *position)
{
    char pos1[3] = {position[2], position[3]};
    char pos2[3] = {position[5], position[6]};

    if (pos1[0] == pos2[0])
        map = set_map_test_length(map, pos2[1] - pos1[1], pos1[0], pos1[1]);
    if (pos1[1] == pos2[1])
        map = set_map_test_width(map, pos2[0] - pos1[0], pos1[0], pos1[1]);
    return (map);
}

char **init_map_test(void)
{
    char **map = malloc(sizeof(char *) * 9);

    map[8] = NULL;
    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 9);
        for (int j = 0; j < 8; j++)
            map[i][j] = ' ';
        map[i][8] = '\0';
    }
    return (map);
}

int does_it_match(char **tab)
{
    char **map = init_map_test();

    for (int i = 0; i < 4; i++) {
        map = insert_ship(map, tab[i]);
    }
    if (do_not_cross(map) == -1)
        return (-1);
    return (1);
}
