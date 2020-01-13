/*
** EPITECH PROJECT, 2019
** dictionary_foreach
** File description:
** loop a list
*/

#include <stdlib.h>
#include "my.h"

void dictionary_foreach(dictionary *v, int (*callback)(char *, void *))
{
    dictionary *node = v;
    int result = 1;
    while (node != NULL && result) {
        if (callback != NULL)
            result = callback(node->key, node->data);
        node = node->next;
    }
}

void dictionary_foreach_value(dictionary *v, int (*callback)(void *))
{
    dictionary *node = v;
    int result = 1;
    while (node != NULL && result) {
        if (callback != NULL)
            result = callback(node->data);
        node = node->next;
    }
}

void dictionary_foreach_key(dictionary *v, int (*callback)(char *))
{
    dictionary *node = v;
    int result = 1;
    while (node != NULL && result) {
        if (callback != NULL)
            result = callback(node->key);
        node = node->next;
    }
}