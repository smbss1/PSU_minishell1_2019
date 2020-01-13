/*
** EPITECH PROJECT, 2019
** dictionary_getnode
** File description:
** get the node on the index we given in params
*/

#include <stdlib.h>
#include "my.h"

dictionary *dictionary_getnode(dictionary **dict, char *key)
{
    for (dictionary *tmp = *dict; tmp != NULL; tmp = tmp->next)
        if (my_strcmp(tmp->key, key) == 0)
            return (tmp);
    return (NULL);
}