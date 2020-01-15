/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** Func that splits a string into words
*/

#include <stdlib.h>
#include "my.h"
#include "debug.h"

static int get_col_length(char const *str)
{
    char *dup = my_strdup(str);
    char *ptr = my_strtok(dup, " ");
    int col = my_strlen(ptr);
    for (int i = 0; ptr; i++) {
        int len = my_strlen(ptr);
        if (len > col)
            col = len;
        ptr = my_strtok(NULL, " \t");
    }
    return (col);
}

static int get_row_length(char const *str)
{
    char *dup = my_strdup(str);
    char *ptr = my_strtok(dup, " ");
    int row = 0;
    for (int i = 0; ptr; i++) {
        ptr = my_strtok(NULL, " \t");
        row++;
    }
    return (row);
}

char **my_str_to_word_array(char const *str)
{
    R_DEV_ASSERT(str != NULL && str[0] != '\0', "", return (NULL));
    int row = get_row_length(str);
    int col = get_col_length(str);
    char **array = mem_alloc_2d_array(row, col);
    R_DEV_ASSERT(array, "", return (NULL));
    my_memset_array(array, 0, row, col);
    char *word = my_strtok(str, " \t");
    int i = 0;
    for (i = 0; word; i++) {
        array[i] = word;
        word = my_strtok(NULL, " \t");
    }
    array[row] = NULL;
    return (array);
}