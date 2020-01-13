/*
** EPITECH PROJECT, 2019
** dictionary_key_exists
** File description:
** return true if key exist else false if it doesn't exist
*/

#include <stdlib.h>
#include "my.h"

int dictionary_key_exists(dictionary **dict, char *key)
{
    return (dictionary_getvalue(dict, key) != NULL);
}