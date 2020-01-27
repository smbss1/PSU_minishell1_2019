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
    #ifdef NDEBUG
    int numObjects = vm->num_objects;
    #endif

    mark_all(vm);
    sweep(vm);
    vm->max_objects = vm->num_objects * 2;
    #ifdef NDEBUG
    int collected = numObjects - vm->num_objects;
    my_printf("%d collected, %d remaining\n", collected, vm->num_objects);
    #endif
}

void gc_print(gc_t *vm)
{
    for (int i = 0; i < vm->stack_size; i++) {
        if (vm->stack[i])
            my_printf("%s\n", vm->stack[i]->data);
    }
}