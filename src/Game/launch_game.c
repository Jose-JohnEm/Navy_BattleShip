/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** launch_game.c
*/

#include "src.h"

void print_game_situation(g_data *game_data)
{
    my_putstr("\nmy positions:\n");
    my_put_map(game_data->player_map);
    my_putstr("\nenemy's positions:\n");
    my_put_map(game_data->attack_map);
}

char **insert_ships_final(char **final_tab, char **positions)
{
    for (int i = 0; i < 4; i++) {
        final_tab = insert_ship(final_tab, positions[i]);
    }
}

char **init_map_final(void)
{
    char **tab = malloc(sizeof(char *) * 9);

    tab[8] = NULL;
    for (int i = 0; i < 8; i++) {
        tab[i] = malloc(sizeof(char) * 9);
        tab[i][8] = '\0';
        my_strcpy(tab[i], "........\0");
    }
    return (tab);
}

char **create_map(int fd)
{
    char **final_tab = init_map_final();
    char *buff = malloc(sizeof(char) * MAX_TO_READ + 1);

    if (fd != -10) {
        read(fd, buff, MAX_TO_READ + 1);
        final_tab = insert_ships_final(final_tab, my_str_tab(buff));
    }
    free(buff);
    return (final_tab);
}

int navy_game(int fd, g_data *game_data)
{
    game_data->player_map = create_map(fd);
    game_data->attack_map = create_map(-10);
    print_game_situation(game_data);
    return (0);
}
