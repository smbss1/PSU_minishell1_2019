/*
** EPITECH PROJECT, 2019
** my_put_unsigned
** File description:
** Function that displays, unsigned number
*/

#include "my.h"
#include <stdlib.h>

void my_sput_unsigned(unsigned int nb)
{
    if (nb < 0) {
        my_sputstr("The number is not unsigned", NULL);
        return;
    }
    if (nb > 9) {
        my_sput_nbr(nb / 10, NULL);
    }
    my_sputchar(nb % 10 + 48, NULL);
}