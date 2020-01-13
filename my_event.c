/*
** EPITECH PROJECT, 2019
** my_event
** File description:
** event handler
*/

#include <stdlib.h>
#include "my_event.h"
#include "my.h"

static listener_l listeners;

void on(char *name, void *handler, void *handler2)
{
    listener_t listener = {name, handler, handler2};
    listeners.listeners[listeners.listener_count] = listener;
    listeners.listener_count++;
}

int emit(char *name, void *value, void *value2)
{
    int result = 0;
    for (int i = 0; i < listeners.listener_count; i++) {
        if (my_strcmp(name, listeners.listeners[i].name) == 0 &&
            listeners.listeners[i].handle != NULL) {
            listeners.listeners[i].handle(value);
            result = 1;
        }
        if (my_strcmp(name, listeners.listeners[i].name) == 0 &&
            listeners.listeners[i].handle2 != NULL) {
            listeners.listeners[i].handle2(value, value2);
            result = 1;
        }
    }
    return (result);
}