/*
** EPITECH PROJECT, 2019
** my_event
** File description:
** Header Event Container
*/

#ifndef _MY_EVENT_
#define _MY_EVENT_

typedef struct listener_t
{
    char *name;
    void (*handle)(void *);
    void (*handle2)(void *, void *);
} listener_t;

typedef struct listener_l
{
    listener_t listeners[100];
    int listener_count;
} listener_l;

#endif