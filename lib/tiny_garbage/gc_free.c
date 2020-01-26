/*
** EPITECH PROJECT, 2019
** my_free
** File description:
** like free funct
*/

#include "garbage.h"

void gc_free(gc_t *vm, void *ptr)
{
    assert(vm->stack_size > 0, "Stack underflow!");
    for (int i = 0; i < vm->stack_size; i++)
        if (vm->stack[i] && ptr && vm->stack[i]->data == ptr) {
            vm->stack[i] = NULL;
            break;
        }
}