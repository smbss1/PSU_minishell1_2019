/*
** EPITECH PROJECT, 2019
** my_put_float
** File description:
** Function that displays, all the combinations of two two-digit numbers.
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

void my_put_float(double nb)
{
    int	i;
    int	entire_part;
    double	decimal_part;

    i = 100;
    entire_part = (int)(nb / 1);
    decimal_part = (nb - entire_part) * i;
    if (decimal_part < 0)
        decimal_part *= -1;
    my_put_nbr(entire_part);
    my_putchar('.');
    if (decimal_part) {
        while (decimal_part / (i = i / 10) == 0 && i > 0)
            my_putchar('0');
    }
    my_put_nbr((int)decimal_part);
}

void my_put_float_void(void *nb)
{
    double *nbr = nb;
    my_put_float(*nbr);
}