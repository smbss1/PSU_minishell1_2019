/*
** EPITECH PROJECT, 2019
** mem_alloc_2d_array
** File description:
** allocate a 2d Array and return his address
*/

/**
* \file mem_alloc_2d_array.c
* \author BESSEAU Samuel
* \version 1
* \date November 24th
*/

#include <stdlib.h>
#include "garbage.h"
#include "my.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    gc_t *gc = get_garbage();
    char **array = gc_malloc(gc, nb_rows * sizeof(char *));
    if (array == NULL)
        return (NULL);
    for (int i = 0; i < nb_rows; i++) {
        array[i] = gc_malloc(gc, nb_cols * sizeof(char));
        if (array[i] == NULL) {
            free_2d_array(array);
            return (NULL);
        }
    }
    return (array);
}

int **mem_alloc_2d_array_int(int nb_rows, int nb_cols)
{
    gc_t *gc = get_garbage();
    int **array = gc_malloc(gc, nb_rows * sizeof(int *));
    for (int i = 0; i < nb_rows; i++)
        array[i] = gc_malloc(gc, nb_cols * sizeof(int));
    return (array);
}