/*
** EPITECH PROJECT, 2019
** my_putab.c
** File description:
** Put tab
*/

char *my_putstr(char *str);

void my_putab(char **tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
}
