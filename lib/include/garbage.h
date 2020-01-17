/*
** EPITECH PROJECT, 2019
** my_event
** File description:
** Header Event Container
*/

#ifndef _GARBAGE_
#define _GARBAGE_

#include <stdlib.h>

#define STACK_MAX (256)

typedef enum t {
    OBJ_INT,
    OBJ_VOID_PTR,
    OBJ_PAIR
} object_type;

typedef struct sObject {
    object_type type;
    unsigned char marked;
    size_t hash;
    int id;
    struct sObject *next;

    union {
        int value;
        void *data;
        struct {
            struct sObject *head;
            struct sObject *tail;
        };
    };
} object_t;

typedef struct {
    object_t *stack[STACK_MAX];
    int stackSize;
    object_t *firstObject;
    int numObjects;
    int maxObjects;
} gc_t;

////////////////////////////////////////////////////////

void gc_run(gc_t *vm);
void gc_stop(gc_t *vm);
gc_t *my_gc_new(void);
object_t *newObject(gc_t *vm, object_type type);
void *gc_malloc(gc_t *vm, size_t size);
void gc_free(gc_t *vm, void *ptr);
gc_t *get_garbage(void);

#endif