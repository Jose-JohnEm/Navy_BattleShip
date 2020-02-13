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

#endif