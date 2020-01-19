/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** Func that allocates memory and copies the string
*/

#include <stdlib.h>
#include "my.h"
#include "garbage.h"

char *my_strdup(char const *src)
{
    gc_t *gc = get_garbage();
    int len = my_strlen(src) + 1;
    char *str = gc_malloc(gc, sizeof(char) * len);
    my_strcpy(str, src);
    return (str);
}