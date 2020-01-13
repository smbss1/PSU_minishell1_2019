/*
** EPITECH PROJECT, 2019
** vector_get
** File description:
** get the data with the index we given
*/

#include "my.h"

void *vector_get_at(vector **v, int index)
{
    vector *tmp = vector_getnode_at(v, index);
    return (tmp->data);
}