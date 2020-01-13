/*
** EPITECH PROJECT, 2019
** dictionary_delete
** File description:
** Delete a node
*/

#include <stdlib.h>
#include "my.h"

void dictionary_delete(dictionary **dict, char *key)
{
    dictionary *delete_node = dictionary_getnode(dict, key);

    if (*dict == NULL || delete_node == NULL)
        return;
    if (*dict == delete_node)
        *dict = delete_node->next;

    if (delete_node->next != NULL)
        delete_node->next->prev = delete_node->prev;

    if (delete_node->prev != NULL)
        delete_node->prev->next = delete_node->next;
    free(delete_node);
}

void dictionary_delete_all(dictionary *v)
{
    dictionary *temp;

    while (v != NULL) {
        temp = v;
        v = v->next;
        free(temp);
    }
}