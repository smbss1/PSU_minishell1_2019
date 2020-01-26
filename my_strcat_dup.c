/*
** EPITECH PROJECT, 2019
** my_strcat_dup
** File description:
** combine my_strcat and my_strdup
*/

#include "garbage.h"
#include "my.h"

char *my_strcat_dup(char *str1, char *str2)
{
    char *new = gc_malloc(get_garbage(), sizeof(char) *
                                    (my_strlen(str1) + my_strlen(str2) + 1));
    my_strncpy(new, str1, my_strlen(str1));
    my_strncat(new, str2, my_strlen(str2));
    return (new);
}