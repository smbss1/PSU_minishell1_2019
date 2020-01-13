/*
** EPITECH PROJECT, 2019
** my_print_comb2
** File description:
** Function that displays, numbers.
*/

#include "my.h"

static int display_min_int(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
    return (0);
}

void my_sput_nbr(int nb, char *buffer)
{
    if (nb == -2147483648) {
        display_min_int();
        return;
    }
    if (nb < 0) {
        my_charcat(buffer, '-');
        nb *= -1;
    }
    if (nb > 9) {
        my_sput_nbr(nb / 10, buffer);
    }
    my_charcat(buffer, nb % 10 + 48);
}

void my_sput_nbr_void(void *nb, char *buffer)
{
    int nbr = (int) nb;
    my_sput_nbr(nbr, buffer);
}