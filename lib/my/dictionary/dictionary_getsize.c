/*
** EPITECH PROJECT, 2019
** dictionary_getsize
** File description:
** Func that returns the number of elemnts onthe list
*/

#include "my.h"
#include <stdlib.h>

int dictionary_getsize(dictionary *begin)
{
    dictionary *tmp = begin;
    int count = 0;

    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return (count);
}