/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** units_test.c
*/

#include <criterion/criterion.h>
#include "src.h"

Test(inputs, no_args) {
    int ac = 1;

    cr_assert(error(ac, NULL) == 84);
}

Test(inputs, too_many_args) {
    int ac = 1;

    cr_assert_eq(error(ac, NULL), 84);
}

Test(inputs, args_but_map_eq_NULL) {
    int ac = 1;

    cr_assert_eq(error(ac, NULL), 84);
}

Test(inputs, args_but_invalid_PID) {
    int ac = 1;

    cr_assert_eq(error(ac, NULL), 84);
}

Test(inputs, first_player) {
    char **av = malloc(sizeof(char *) * 3);
    int ac = 2;
    int err;

    av[0] = NULL;
    av[1] = "Map/m1";
    av[2] = NULL;
    err = error(ac, av);
    cr_assert_eq(err, 1, "The result was %d. Expected %d, err, 1");
}