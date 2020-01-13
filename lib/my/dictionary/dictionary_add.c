/*
** EPITECH PROJECT, 2019
** dictionary_add
** File description:
** create a new element
*/

#include <stdlib.h>
#include "my.h"

dictionary *dictionary_add(dictionary **head_ref, char *key, void *data)
{
    dictionary *element = malloc(sizeof(dictionary));
    element->key = key;
    element->data = data;
    element->next = (*head_ref);
    element->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = element;
    (*head_ref) = element;
    return (element);
}