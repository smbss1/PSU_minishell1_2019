/*
** EPITECH PROJECT, 2019
** vector_delete
** File description:
** Delete a node
*/

#include <stdlib.h>
#include "my.h"

void vector_delete(vector **v, int index)
{
    vector *delete_node;
    vector *prev;
    int i = 0;
    int size = vector_getsize(*v);

    if (index == 0) {
        delete_node = *v;
        *v = delete_node->next;
        free(delete_node);
        return;
    }
    for (vector *tmp = *v; tmp != NULL; tmp = tmp->next, i++)
        if (i == index) {
            delete_node = tmp;
            prev = delete_node->prev;
            prev->next = delete_node->next;
            break;
        }
    free(delete_node);
}

void vector_delete_all(vector *v)
{
    vector *temp;

    while (v != NULL) {
        temp = v;
        v = v->next;
        free(temp);
    }
}