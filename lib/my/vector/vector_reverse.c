/*
** EPITECH PROJECT, 2019
** vector_reverse
** File description:
** reverse the list
*/

#include <stdlib.h>
#include "my.h"

void vector_reverse(vector **begin)
{
    vector *next = NULL;
    vector *current = *begin;
    vector *prev = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *begin = prev;
}