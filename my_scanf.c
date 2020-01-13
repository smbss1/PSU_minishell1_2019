/*
** EPITECH PROJECT, 2019
** my_scanf
** File description:
** scanf function
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

static void process(va_list print, const char fmt)
{
    char *buffe = NULL;
    if (fmt == 's') {
        size_t size;
        getline(&buffe, &size, stdin);
        if (size > 0) {
            my_strcpy(va_arg(print, char *), buffe);
        }
    }
}

void my_scanf(const char *fmt, ...)
{
    va_list print;
    va_start(print, fmt);
    for (int i = 0; fmt[i]; i++) {
        if (fmt[i] == '%') {
            process(print, fmt[++i]);
        }
    }
    va_end(print);
}