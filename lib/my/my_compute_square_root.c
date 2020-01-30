/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** Function that returns the squareroot
*/

#include "../../include/my.h"

int my_compute_square_root(int nb)
{
    int sqrt = nb;

    if (nb < 0 || nb % 2 == 1)
        return (0);
    for (int i = 0, x = 0; sqrt != x; i++) {
        x = sqrt;
        sqrt = (nb / x + x) / 2;
    }
    return (sqrt);
}