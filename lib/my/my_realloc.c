/*
** EPITECH PROJECT, 2019
** my_realloc
** File description:
** Realloc Memory
*/

#include <stdlib.h>
#include "my.h"

char *my_realloc(char *str)
{
    char *str2;
    str2 = my_strdup(str);
    free(str);
    return (str2);
}