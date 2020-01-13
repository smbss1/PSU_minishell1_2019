/*
** EPITECH PROJECT, 2019
** dictionary_getvalue
** File description:
** get the data with the index we given
*/

#include <stdlib.h>
#include "my.h"

void *dictionary_getvalue(dictionary **dict, char *key)
{
    dictionary *tmp = dictionary_getnode(dict, key);
    return (tmp != NULL ? tmp->data : NULL);
}