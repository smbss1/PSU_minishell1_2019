/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** The Ultime Printf
*/

#include "my.h"

void my_sputbase(int num, const char *base)
{
    int base_size = my_strlen(base);

    if (num / base_size > 0)
        my_sputbase(num / base_size, base);

    my_sputchar(base[num % base_size], 0);
}

void my_sputbase_void(void *num, char *base)
{
    int nb = num;
    my_sputbase(nb, base);
}