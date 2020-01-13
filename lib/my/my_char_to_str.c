/*
** EPITECH PROJECT, 2019
** my_char_to_str
** File description:
** Function that verify that the char is only number
*/

#include<stdlib.h>
#include "../../include/my.h"

char *my_char_to_str(char c)
{
    char *str = my_strdup("");
    str[0] = c;
    str[1] = '\0';
    return (str);
}