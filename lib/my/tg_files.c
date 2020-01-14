/*
** EPITECH PROJECT, 2019
** tg_files
** File description:
** Tiny Garbage
*/

#include <stdlib.h>
#include "my.h"

static inline vector *blocks;

void tg_start(void)
{
    blocks = NULL;
}

int free_all(void *data)
{
    if (data != NULL)
        free(data);
    return (1);
}

void *tg_malloc(size_t size)
{
    void *data = malloc(size);
    vector_add(&blocks, data);
    return (data);
}

void tg_stop(void)
{
    vector_foreach(blocks, free_all);
    vector_delete_all(blocks);
}