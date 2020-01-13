/*
** EPITECH PROJECT, 2019
** set_variable
** File description:
** Set Value of a variable in Text
*/

#include <stdlib.h>
#include "my.h"

void set_variable(char *str, char *name, char *data)
{
    char *to_replace = 0;
    int data_l = my_strlen(data);
    char *dup = my_strdup(str);
    char *pos = my_strstr(dup, name);
    to_replace = get_str(str, name);
    pos = my_strstr(pos, to_replace);

    if (pos != NULL) {
        long newlen = my_strlen(dup) - my_strlen(to_replace) + my_strlen(data);
        char new_dup[newlen + 1];
        my_memcpy(new_dup, dup, pos - dup);
        my_memcpy(new_dup + (pos - dup), data, my_strlen(data));
        my_strcpy(new_dup + (pos - dup) + data_l, pos + my_strlen(to_replace));
        my_printf("Old: \n%sNew: \n%s", dup, new_dup);
        writeFile("Parsing.txt", new_dup);
    }
    free (dup);
}