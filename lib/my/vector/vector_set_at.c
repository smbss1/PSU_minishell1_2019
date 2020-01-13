/*
** EPITECH PROJECT, 2019
** vector_set_at
** File description:
** replace the old value to the new on the node finded with the index
*/

#include <stdlib.h>
#include "my.h"

void vector_set_at(vector **v, int index, void *item)
{
    vector *tmp = vector_getnode_at(v, index);
    tmp->data = item;
}