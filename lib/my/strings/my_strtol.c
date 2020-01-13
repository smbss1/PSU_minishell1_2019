/*
** EPITECH PROJECT, 2019
** my_strtol
** File description:
** Func convert char to int and return the rest
*/

#include "my.h"

int number(char **str)
{
    int nbr = 0;
    int neg = 1;

    while (*str[0] == '+' || *str[0] == '-') {
        if (*str[0] == '-')
            neg *= -1;
        *str += 1;
    }
    while (my_char_isnum(*str[0])) {
        nbr *= 10;
        nbr += *str[0] - '0';
        *str += 1;
    }
    return (nbr * neg);
}

int my_strtol(char *str, char **endptr)
{
    int num = number(&str);
    char *p = str;

    for (int i = 0; *p != '\0'; i++) {
        if (!my_char_isnum(*p))
            break;
        *p++;
    }
    *endptr = p;
    return (num);
}