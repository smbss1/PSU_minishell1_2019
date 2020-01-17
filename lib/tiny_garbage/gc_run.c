/*
** EPITECH PROJECT, 2019
** gc_run
** File description:
** run the GC
*/

#include "garbage.h"
#include "my.h"

void gc_run(gc_t *vm)
{
    int numObjects = vm->numObjects;

    mark_all(vm);
    sweep(vm);
    vm->maxObjects = vm->numObjects * 2;
    int collected = numObjects - vm->numObjects;
    my_printf("Collected %d objects, %d remaining.\n", collected,
                                                    vm->numObjects);
}

void gc_print(gc_t *vm)
{
    for (int i = 0; i < vm->stackSize; i++) {
        if (vm->stack[i])
            my_printf("%s\n", vm->stack[i]->data);
    }
}