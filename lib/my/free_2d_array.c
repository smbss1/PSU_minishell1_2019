/*
** EPITECH PROJECT, 2019
** free_2D_array
** File description:
** Free a 2D array
*/

#include <stdlib.h>
#include "garbage.h"

void free_2d_array(void **array)
{
    for (int i = 0; array[i] != NULL; i++)
        gc_free(get_garbage(), array[i]);
    gc_free(get_garbage(), array);
}