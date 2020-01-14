/*
** EPITECH PROJECT, 2019
** debug
** File description:
** debug_assert
*/

void debug(char *format)
{
    write(1, format, my_strlen(format));
}