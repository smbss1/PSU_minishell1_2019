/*
** EPITECH PROJECT, 2019
** my_int_to_string
** File description:
** Transform int to string
*/

#include "my.h"

char	*my_int_to_str(int nbr, char *result)
{
    int	nbrr = nbr;

    if (nbr < 0)
        nbr *= -1;
    for (int i = 0; nbr != 0; i++) {
        result[i++] = nbr % 10 + '0';
        nbr /= 10;
    }
    if (nbrr < 0)
        my_strcat(result, "-");
    my_strcat(result, "\0");
    if (nbrr == 0)
    {
        result[0] = '0';
        result[1] = 0;
    }
    return (my_revstr(result));
}