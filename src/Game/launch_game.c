/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** launch_game.c
*/

#include "src.h"

char **insert_ships_final(char **final_tab, char **positions)
{
    for (int i = 0; i < 4; i++) {
        final_tab = insert_ship(final_tab, positions[i]);
    }
}

char **init_map_final(void)
{
    char **tab = malloc(sizeof(char *) * 11);

    tab[10] = NULL;
    for (int i = 0; i < 10; i++) {
        tab[i] = malloc(sizeof(char) * 18);
        tab[i][17] = '\0';
        if (i == 0)
            my_strcpy(tab[i], " |A B C D E F G H\0");
        else if (i == 1)
            my_strcpy(tab[i], "-+---------------\0");
        else {
            my_strcpy(tab[i], " |. . . . . . . .\0");
            tab[i][0] = i + '0' - 1;
        }
    }
    return (tab);
}

char **create_map(int fd)
{
    char **final_tab = init_map_final();
    char *buff = malloc(sizeof(char) * MAX_TO_READ + 1);

    read(fd, buff, MAX_TO_READ + 1);
    final_tab = insert_ships_final(final_tab, my_str_tab(buff));
    my_putab(final_tab);
    free(buff);
}

int navy_game(int fd, g_data *game_data)
{
    game_data->player_map = create_map(fd);
    (void)game_data;
    return (0);
}
