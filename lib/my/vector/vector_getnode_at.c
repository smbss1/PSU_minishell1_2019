/*
** EPITECH PROJECT, 2019
** vector_getnode_at
** File description:
** get the node on the index we given in params
*/

#include <stdlib.h>
#include "my.h"

vector *vector_getnode_at(vector **v, int index)
{
    int i = 0;

    for (vector *tmp = *v; tmp != NULL; tmp = tmp->next, i++)
        if (i == index)
            return (tmp);
    return (NULL);
}