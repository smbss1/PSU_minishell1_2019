/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** print my character
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchar_void(void *c)
{
    char ch = (char) c;
    my_putchar(c);
}