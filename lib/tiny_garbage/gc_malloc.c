/*
** EPITECH PROJECT, 2019
** my_malloc
** File description:
** like malloc func
*/

#include "garbage.h"
#include <stdlib.h>

void *gc_malloc(gc_t *vm, size_t size)
{
    object_t *object = new_object(vm, OBJ_VOID_PTR);
    if (object == NULL)
        return (NULL);
    object->data = NULL;
    object->data = malloc(size);
    if (object->data == NULL)
        return (NULL);
    gc_push(vm, object);
    return (object->data);
}