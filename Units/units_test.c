/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** units_test.c
*/

#include <criterion/criterion.h>
#include "src.h"

TestSuite(inputs);

Test(inputs, no_args) {
    int ac = 1;
    char **av = malloc(sizeof(char *) * ac);

    av[0] = "./navy";
    cr_assert_eq(error(ac, av), 84);
}

Test(inputs, too_many_args) {
    char **av = malloc(sizeof(char *) * 3);
    int ac = 4;

    av[0] = "./navy";
    av[1] = "2345";
    av[2] = "Map/m1";
    av[3] = "another";
    cr_assert_eq(error(ac, av), 84);
}

Test(inputs, args_but_map_eq_NULL) {
    char **av = malloc(sizeof(char *) * 3);
    int ac = 2;

    av[0] = "./navy";
    av[1] = NULL;
    cr_expect_eq(error(ac, av), 84);
    av[1] = "Map/bad_size";
    cr_expect_eq(error(ac, av), 84);
    ac = 3;
    av[2] = av[1];
    av[1] = "99999";
    cr_expect_eq(error(ac, av), 84);
}

Test(inputs, args_but_invalid_PID) {
    char **av = malloc(sizeof(char *) * 3);
    int ac = 3;

    av[0] = "./navy";
    av[1] = "invalid pid";
    av[2] = "Map/m1";
    cr_assert_eq(error(ac, av), 84);
}

Test(inputs, help) {
    char **av = malloc(sizeof(char *) * 2);
    int ac = 2;

    av[0] = "./navy";
    av[1] = "-h";
    cr_assert_eq(error(ac, av), 0);
}

Test(inputs, first_player_ok) {
    char **av = malloc(sizeof(char *) * 2);
    int ac = 2;
    int err;

    av[0] = malloc(sizeof(char) * 7);
    av[1] = malloc(sizeof(char) * 7);
    my_strcpy(av[0], "./navy\0");
    my_strcpy(av[1], "Map/m1\0");
    err = error(ac, av);
    cr_assert_eq(err, 1, "The result was %d. Expected 2", err);
}

Test(inputs, second_player_ok) {
    char **av = malloc(sizeof(char *) * 2);
    int ac = 3;
    int err;

    av[0] = malloc(sizeof(char) * 7);
    av[1] = malloc(sizeof(char) * 6);
    av[2] = malloc(sizeof(char) * 7);
    my_strcpy(av[0], "./navy\0");
    my_strcpy(av[1], "99999\0");
    my_strcpy(av[2], "Map/m2\0");
    err = error(ac, av);
    cr_assert_eq(err, 2, "The result was %d. Expected 2", err);
}

TestSuite(map);

Test(map, file_eq_null) {
    char **av = malloc(sizeof(char *) * 2);

    av[0] = "./navy";
    av[1] = "a_map_wich_doesn't_exits";
    cr_expect_eq(verif_player1(av), 84);
    av = malloc(sizeof(char *) * 3);
    av[0] = "./navy";
    av[1] = "99999";
    av[2] = "a_map_wich_doesn't_exits";
    cr_assert_eq(verif_player2(av), 84);
}

Test(map, file_with_bad_size) {
    int fd = open("Map/bad_size", O_RDONLY);

    cr_assert_eq(demand_map(fd), -1);
}

Test(map, file_with_bad_format) {
    int fd = open("Map/bad_format", O_RDONLY);

    cr_assert_eq(demand_map(fd), -1);
}

Test(map, file_with_incorrect_size) {
    int fd = open("Map/incorrect_size", O_RDONLY);

    cr_assert_eq(demand_map(fd), -1);
}

Test(map, file_with_diagonal_ships) {
    int fd = open("Map/diagonal_ships", O_RDONLY);

    cr_assert_eq(demand_map(fd), -1);
}

Test(map, file_with_matching_ships) {
    int fd = open("Map/matching_ships", O_RDONLY);

    cr_assert_eq(demand_map(fd), -1);
}

TestSuite(connection);

Test(connection, sucess) {
    
}