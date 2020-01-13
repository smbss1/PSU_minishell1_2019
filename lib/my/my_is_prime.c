/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** Function that returns if the number is prime or not
*/

#include "../../include/my.h"

int my_is_prime(int nb)
{
    if (nb == 2)
        return (1);
    if (nb < 2 || nb % 2 == 0) {
        return (0);
    }
    for (int i = 2; i < nb; i++) {
        if (nb % i == 0) {
            return (0);
        }
    }
    return (1);
}