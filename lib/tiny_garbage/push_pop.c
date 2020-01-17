/*
** EPITECH PROJECT, 2019
** push
** File description:
** push
*/

#include "garbage.h"

void gc_push(gc_t *vm, object_t *value)
{
    if (assert(vm->stackSize < STACK_MAX, "Stack overflow!"))
        return;
    for (int i = 0; i < vm->stackSize; i++)
        if (vm->stack[i] == NULL) {
            vm->stack[i] = value;
            return;
        }
    value->id = vm->stackSize;
    vm->stack[vm->stackSize++] = value;
}

object_t *pop(gc_t *vm)
{
    if (assert(vm->stackSize > 0, "Stack underflow!"))
        return;
    vm->stack[vm->stackSize] = NULL;
    return (vm->stack[--vm->stackSize]);
}

void pushInt(gc_t *vm, int intValue)
{
    object_t *object = new_object(vm, OBJ_INT);
    object->value = intValue;

    gc_push(vm, object);
}

object_t *pushPair(gc_t *vm)
{
    object_t *object = new_object(vm, OBJ_PAIR);
    object->tail = pop(vm);
    object->head = pop(vm);

    gc_push(vm, object);
    return object;
}