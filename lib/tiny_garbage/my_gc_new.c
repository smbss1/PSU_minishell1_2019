/*
** EPITECH PROJECT, 2019
** mark_sweep
** File description:
** sf
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "garbage.h"

static inline gc_t *gc_static;

int assert(int condition, const char *message) {
    if (!condition) {
        my_printf("%s\n", message);
        return (1);
    }
    return (0);
}

static size_t hash(void *ptr)
{
    return ((unsigned long)ptr) >> 3;
}

gc_t *get_garbage(void)
{
    return (gc_static);
}

gc_t *my_gc_new(void)
{
    if (gc_static != NULL)
        return (gc_static);
    gc_t *vm = malloc(sizeof(gc_t));
    vm->stackSize = 0;
    vm->firstObject = NULL;
    vm->numObjects = 0;
    vm->maxObjects = 8;
    gc_static = vm;
    return (vm);
}

object_t *new_object(gc_t *vm, object_type type)
{
    if (vm->numObjects >= vm->maxObjects)
        gc_run(vm);
    object_t *object = malloc(sizeof(object_t));
    object->type = type;
    object->next = vm->firstObject;
    vm->firstObject = object;
    object->marked = 0;
    vm->numObjects++;
    return (object);
}