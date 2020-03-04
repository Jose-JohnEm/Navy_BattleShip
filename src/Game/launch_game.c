/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** launch_game.c
*/

#include "src.h"

int print_game_situation(g_data *game_data)
{
    my_putstr("\nmy positions:\n");
    my_put_map(game_data->player_map);
    my_putstr("\nenemy's positions:\n");
    my_put_map(game_data->attack_map);
    return (1);
}

char **insert_ships_final(char **final_tab, char **positions)
{
    for (int i = 0; i < 4; i++) {
        final_tab = insert_ship(final_tab, positions[i]);
    }
    return (final_tab);
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
    int turn = game_data->num_player;
    int aff = 0;

    game_data->player_map = create_map(fd);
    game_data->attack_map = create_map(-10);
    print_game_situation(game_data);
    for (int aff = 1; there_is_a_ship(game_data) == 1; aff++) {
        if (turn == 1)
            turn = gameplay(game_data);
        else
            turn = waiting(game_data);
        if (aff == 2) {
            aff = 0;
            print_game_situation(game_data);
        }
    }
    who_loose(turn);
    (void)aff;
    return (2 - turn);
}
