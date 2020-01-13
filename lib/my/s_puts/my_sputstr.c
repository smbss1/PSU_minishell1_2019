/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Function that displays, one-by-one, the characters of a string.
*/

#include <unistd.h>
#include "my.h"

void my_sputstr(char const *str, char *buffer)
{
    my_strcat(buffer, str);
}

void my_sputstr_void(void *str, char *buffer)
{
    char *str2 = (char *) str;
    my_sputstr(str2, buffer);
}