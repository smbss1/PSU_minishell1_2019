/*
** EPITECH PROJECT, 2019
** sweep
** File description:
** free address who I don't use
*/

#include "garbage.h"

void sweep(gc_t *vm)
{
    object_t **object = &vm->firstObject;
    while (*object) {
        if ((*object)->marked == 0) {
            object_t *unreached = *object;
            *object = unreached->next;
            if (unreached && unreached->data && unreached->type == OBJ_VOID_PTR)
                free(unreached->data);
            free(unreached);
            vm->numObjects--;
        } else {
            (*object)->marked = 0;
            object = &(*object)->next;
        }
    }
}