/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** print my character
*/

#include <unistd.h>
#include "my.h"

void my_sputchar(char c, char *buffer)
{
    my_charcat(buffer, c);
}

void my_sputchar_void(void *c, char *buffer)
{
    char ch = (char) c;
    my_sputchar(c, buffer);
}