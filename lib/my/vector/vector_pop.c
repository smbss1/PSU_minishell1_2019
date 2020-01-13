/*
** EPITECH PROJECT, 2019
** pop
** File description:
** removes List2 first value ant push it at the beginnig of List1
*/

#include <stdlib.h>
#include "my.h"

void *vector_pop(vector **array)
{
    vector *tmp;
    void *data;
    tmp = *array;
    *array = (*array)->next;
    data = tmp->data;
    free(tmp);
    return data;
}