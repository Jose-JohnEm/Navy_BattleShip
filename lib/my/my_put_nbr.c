/*
** EPITECH PROJECT, 2019
** task07
** File description:
** learn C
*/

#include <unistd.h>

void my_putchar(char c);

void my_put_nbr(int nb)
{
    int cas = 0;

    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            nb = 214748364;
            cas = 1;
        } else
            nb = nb * (-1);
    }
    if (nb > 9)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
    if (cas == 1)
        my_putchar('8');
}
