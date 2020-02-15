/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** error.h
*/

#ifndef ERROR_H
#define ERROR_H

#define MAX_TO_READ 32

/*--------- error.c ----------*/
int help(void);
int error(int ac, char **av);

/*--------- verif_players.c ----------*/
int verif_player1(char **av);
int verif_player2(char **av);

/*--------- check_map.c ----------*/
int is_the_map_correct(char *str);
int demand_map(int fd);
int verif_cara(int cara, int line, char current);
int verif_positions(char **tab);

/*--------- ship_matcher.c ----------*/
int does_it_match(char **tab);
char **init_map_test();
int do_not_cross(char **map);
char **insert_ship(char **map, char *position);

/*--------- ship_matcher.c ----------*/
char **set_map_test_width(char **map, int diff, int x, int y);
char **set_map_test_length(char **map, int diff, int x, int y);

#endif