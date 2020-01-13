/*
** EPITECH PROJECT, 2019
** vector_foreach
** File description:
** loop a list
*/

#include <stdlib.h>
#include "my.h"

void vector_foreach(vector *v, int (*callback)(void *))
{
    vector *node = v;
    int result = 1;
    while (node != NULL && result) {
        if (callback != NULL)
            result = callback(node->data);
        node = node->next;
    }
}